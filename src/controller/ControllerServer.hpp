#ifndef __CONTROLLERSERVER_H__
#define __CONTROLLERSERVER_H__

#include "../communication/Server.hpp"
#include "../communication/Data.hpp"
#include <iostream>
#include <functional>

namespace controler
{

class ControllerServer
{
private:
    void clientChangeCallback(int clientCount);
    communication::Server server;
    std::pair<Data, int> m_data;   
    

public:
    ControllerServer();
    ~ControllerServer();
    void init();
};


}



#endif // __CONTROLLERSERVER_H__