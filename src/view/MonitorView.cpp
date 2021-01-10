#include "MonitorView.hpp"

namespace view
{

    Monitor_view::Monitor_view(/* args */) : m_desktopMode(sf::VideoMode::getDesktopMode()),
                                             window(sf::VideoMode(m_desktopMode.width,
                                                                  m_desktopMode.height,
                                                                  m_desktopMode.bitsPerPixel),
                                                    "Game",
                                                    sf::Style::Default)

    {
        window.setVerticalSyncEnabled(true);
        window.setKeyRepeatEnabled(false);
    }

    Monitor_view::~Monitor_view()
    {
    }
    
    bool Monitor_view::open() 
    {
        return window.isOpen();
    }
    
    sf::RenderWindow &Monitor_view::get() 
    {
        return window;
    }
    
    std::pair<int, int> Monitor_view::getSize() 
    {
        std::pair<int, int>  tmp(m_desktopMode.width, m_desktopMode.height);
        return tmp;
    }


} // namespace view