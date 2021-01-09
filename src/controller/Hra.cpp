#include "Hra.hpp"
#include <iostream>

namespace controler
{
  Hra::Hra(/* args */) : m_monitorView(new view::Monitor_view)
  {
  }

  Hra::~Hra()
  {
    delete m_monitorView;
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

  void Hra::ovladanie_hry()
  {
    // Process events
    sf::Event event;
    sf::RenderWindow &window = m_monitorView->get();
    auto x = getPostava(0).getPozicia().first;
    auto y = getPostava(0).getPozicia().second;

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
          break;
        case sf::Keyboard::Down:
          downFlag = true;
          break;
        case sf::Keyboard::Left:
          leftFlag = true;
          break;
        case sf::Keyboard::Right:
          rightFlag = true;
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
          break;
        case sf::Keyboard::Down:
          downFlag = false;
          break;
        case sf::Keyboard::Left:
          leftFlag = false;
          break;
        case sf::Keyboard::Right:
          rightFlag = false;
          break;
        default:
          break;
        }
      }
    }

    // Process events
    // Update coordinates
    if (leftFlag)
      x -= SPRITE_SPEED;
    if (rightFlag)
      x += SPRITE_SPEED;
    if (upFlag)
      y -= SPRITE_SPEED;
    if (downFlag)
      y += SPRITE_SPEED;

    // Check screen boundaries

    if (x < 0)
      x = 0;
    if (x > (int)window.getSize().x)
      x = window.getSize().x;
    if (y < 0)
      y = 0;
    if (y > (int)window.getSize().y)
      y = window.getSize().y;

    getPostava(0).setPozicia(x, y);
  }

  void Hra::init_hra()
  {


    sf::RenderWindow &window = m_monitorView->get();


    while (window.isOpen())
    {
      ovladanie_hry();

      window.clear(sf::Color(127, 127, 127));
      window.draw(getPostava(0).getSprite());

      // Update display and wait for vsync
      window.display();
    }
  }

} // namespace controler