#ifndef __MONITOR_VIEW_H__
#define __MONITOR_VIEW_H__

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

namespace view
{


class Monitor_view
{
private:
    sf::VideoMode m_desktopMode;
    sf::RenderWindow window;

public:
    Monitor_view(/* args */);
    ~Monitor_view();

    bool open();

    sf::RenderWindow& get();
};


}



#endif // __MONITOR_VIEW_H__