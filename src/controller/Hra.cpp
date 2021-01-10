#include "Hra.hpp"
#include <iostream>
#include <future>
#include <thread>

namespace controler
{
  Hra::Hra() 
  {
  }

  Hra::~Hra()
  {

  }

  void Hra::setMapa(model::Mapa map)
  {
    m_mapa = map;
  }

  void Hra::addNewPostava(const model::Postava &postava)
  {

    m_postava.push_back(postava);
  }

  model::Postava &Hra::getPostava(int i_postava)
  {
    return m_postava[i_postava];
  }

  void Hra::ovladanie_hry(sf::RenderWindow &window)
  {
    // Process events
    sf::Event event;
    // while (window.isOpen())
    // {
     
      bool upFlag = false;
      bool downFlag = false;
      bool leftFlag = false;
      bool rightFlag = false;
      bool change = false;

      while (window.pollEvent(event))
      {
        // Close the window if a key is pressed or if requested
        if (event.type == sf::Event::Closed)
          window.close();

        // If a key is pressed
        if (event.type == sf::Event::KeyPressed)
        {
          switch (event.key.code)
          {
          // If escape is pressed, close the application
          case sf::Keyboard::Escape:
            window.close();
            break;

          // Process the up, down, left and right keys
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

        // If a key is released
        if (event.type == sf::Event::KeyReleased)
        {
          switch (event.key.code)
          {
          // Process the up, down, left and right keys
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

      if (change == true)
      {
        client.sendMsg(Data(m_indexClient, Smer(upFlag, downFlag, leftFlag, rightFlag)));
        change = false;
      }
 //   }

    //todo
    // // Process events
    // // Update coordinates
    // if (leftFlag)
    //   x -= SPRITE_SPEED;
    // if (rightFlag)
    //   x += SPRITE_SPEED;
    // if (upFlag)
    //   y -= SPRITE_SPEED;
    // if (downFlag)
    //   y += SPRITE_SPEED;

    // // Check screen boundaries

    // if (x < 0)
    //   x = 0;
    // if (x > (int)window.getSize().x)
    //   x = window.getSize().x;
    // if (y < 0)
    //   y = 0;
    // if (y > (int)window.getSize().y)
    //   y = window.getSize().y;
  }

  bool Hra::messageReaction()
  {
    // todo   get data
    Data data = client.getFromReadQueue();

    switch (data.getType())
    {
    case typeMessage::pohyb:
      /* code */
      std::cout << "pohyb sprav prisla";
      break;
    case typeMessage::newClient:
      /* code */
      std::cout << "new Client sprav prisla";
      break;

    case typeMessage::initMessage:
      //m_indexClient = data.getIndex();
      std::cout << "init Message sprav prisla";

      break;

    default:
      break;
    }
    return true;
  }

  void Hra::init_hra()
  {
  std::cout << "window ,,,";

    sf::RenderWindow &window = m_monitorView.get();
      std::cout << "ovladanie ,,,";

    std::thread(&controler::Hra::ovladanie_hry, this ,std::ref(window)).detach();
    
    
  std::cout << "init ,,,";
    while (window.isOpen())
    {
     
      window.clear(sf::Color(127, 127, 127));
      //std::thread(&controler::Hra::ovladanie_hry, this ,std::ref(window)).detach();
    

      for (model::Postava n : m_postava)
      {
        window.draw(n.getSprite());
      }

      //window.draw(getPostava(0).getSprite());

      // Update display and wait for vsync
      window.display();
      messageReaction();
     // std::thread(&controler::Hra::messageReaction, this ).detach();

    }
  }

} // namespace controler