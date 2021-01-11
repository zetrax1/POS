#include "Hra.hpp"
#include <iostream>
#include <future>
#include <thread>
#include <chrono>
namespace controler
{

  Hra::Hra()
  {
  }

  Hra::~Hra()
  {
  }

  void Hra::moveItems()
  {
    while (m_isRun)
    {

      for (int i = 0; i < (int)m_postava.size(); i++)
      {
        auto x = getPostava(i).getPozicia().first;
        auto y = getPostava(i).getPozicia().second;
        std::tuple<bool, bool, bool,bool> smer = readSmerFromVector(i);

        //left, right ,up ,down
        if (std::get<0>(smer))
          x -= SPRITE_SPEED;
        if (std::get<1>(smer))
          x += SPRITE_SPEED;
        if (std::get<2>(smer))
          y -= SPRITE_SPEED;
        if (std::get<3>(smer))
          y += SPRITE_SPEED;

        // Check screen boundaries
        if (x < 0)
          x = 0;
        if (x > sizeWin.first)
          x = sizeWin.first;
        if (y < 0)
          y = 0;
        if (y > sizeWin.second)
          y = sizeWin.second;

        writeToVector(x, y, i);
      }

      std::this_thread::sleep_for(std::chrono::milliseconds(30));
    }
  }

  std::tuple<bool, bool, bool,bool>  Hra::readSmerFromVector(int index)
  {
    return m_postava[index].getSmer();
  }

  void Hra::writeToVector(int x, int y, int index)
  {
    std::unique_lock<std::mutex> mlock(mutex_);

    m_postava[index].setPozicia(x, y);

    mutex_.unlock();
  }
  
  void Hra::writeToVector(std::tuple<bool, bool, bool,bool> smer,int index) 
  {
    std::cout << "prisla mi od servera" << std::get<0>(smer)<< std::get<1>(smer) << std::get<2>(smer) << std::get<3>(smer) << "\n";
    std::unique_lock<std::mutex> mlock(mutex_);

    m_postava[index].setSmer(smer);

    mutex_.unlock();
  }

  void Hra::setMapa(model::Mapa map)
  {
    m_mapa = map;
  }

  void Hra::addNewPostava(const model::Postava &postava)
  {

    m_postava.push_back(postava);
    m_postava.back().setSprite();
  }

  model::Postava &Hra::getPostava(int i_postava)
  {
    return m_postava[i_postava];
  }

  void Hra::ovladanie_hry(sf::RenderWindow &window)
  {
    // Process events
    sf::Event event;
    bool upFlag = false;
    bool downFlag = false;
    bool leftFlag = false;
    bool rightFlag = false;
    bool change = false;

    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();

      if (event.type == sf::Event::KeyPressed)
      {
        switch (event.key.code)
        {
        case sf::Keyboard::Escape:
          window.close();
          break;

        case sf::Keyboard::Up:
          upFlag = true;
          change = true;
          break;
        case sf::Keyboard::Down:
          downFlag = true;
          change = true;
          break;
        case sf::Keyboard::Left:
          leftFlag = true;
          change = true;
          break;
        case sf::Keyboard::Right:
          rightFlag = true;
          change = true;
          break;
        default:
          break;
        }
      }

      if (event.type == sf::Event::KeyReleased)
      {
        switch (event.key.code)
        {
        case sf::Keyboard::Up:
          upFlag = false;
          change = true;
          break;
        case sf::Keyboard::Down:
          downFlag = false;
          change = true;
          break;
        case sf::Keyboard::Left:
          leftFlag = false;
          change = true;
          break;
        case sf::Keyboard::Right:
          rightFlag = false;
          change = true;
          break;
        default:
          break;
        }
      }
    }

    if (change == true && initialized )
    {
      client.sendMsg(Data(m_postava[m_indexClient].getPozicia().first,
                          m_postava[m_indexClient].getPozicia().second,
                          m_indexClient,
                          std::make_tuple(leftFlag, rightFlag, upFlag, downFlag)));

      change = false;
    }
  }

  bool Hra::messageReaction()
  {
    while(m_isRun)
    {
    Data data = client.getFromReadQueue();
    switch (data.getType())
    {
    case typeMessage::pohyb:
      messagePohyb(data);
      break;
    case typeMessage::newClient:
      messageNewClient(data);
      break;

    case typeMessage::initMessage:
      messageInit(data);
      break;

    default:
      break;
    }
    }
    return true;
  }

  void Hra::messagePohyb(Data &data)
  {
    writeToVector(data.getSmer(),data.getIndex());
    writeToVector(data.getSuradnice().first ,data.getSuradnice().second ,data.getIndex() );
  }

  void Hra::messageInit(Data &data)
  {
    m_indexClient = data.getIndex();
    std::cout << m_indexClient << "  index clienta pri init \n";

    std::unique_lock<std::mutex> mlock(mutex_);
    for (int i = 0; i < m_indexClient+1 ; i++)
    {
     addNewPostava(model::Postava(100 ,100 ));
    }
    mutex_.unlock();
    initialized = true;

  }

  void Hra::messageNewClient(Data &data)
  {
    std::unique_lock<std::mutex> mlock(mutex_);

    addNewPostava(model::Postava(data.getSuradnice().first,data.getSuradnice().second));
    mutex_.unlock();
  }

  void Hra::init_hra()
  {
    view::Monitor_view monitorView;
    sf::RenderWindow &window = monitorView.get();
    sizeWin = monitorView.getSize();
   

    std::thread(&controler::Hra::moveItems, this).detach();
    std::future<bool> fut = std::async(&controler::Hra::messageReaction, this);

    while (window.isOpen())
    {
      ovladanie_hry(std::ref(monitorView.get()));
      window.clear();

      if(initialized)
      {
      for (model::Postava n : m_postava)
      {
        window.draw(n.getSprite());
      }
      }

      window.display();
    }

    if (fut.get())
    {
      return;
    }

    std::unique_lock<std::mutex> mlock(mutex_);
    m_isRun = false;
    mutex_.unlock();

  }

} // namespace controler