#include "MonitorView.hpp"

namespace view
{

    Monitor_view::Monitor_view(/* args */) : m_desktopMode(sf::VideoMode::getDesktopMode()),
                                             window(sf::VideoMode(m_desktopMode.width-50,
                                                                  m_desktopMode.height-50,
                                                                  m_desktopMode.bitsPerPixel),
                                                    "Game",
                                                    sf::Style::None)

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


} // namespace view