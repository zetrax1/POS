#ifndef __CONTROLLERSERVER_H__
#define __CONTROLLERSERVER_H__

#include "../communication/Server.hpp"
#include "../communication/Data.hpp"
#include <iostream>

namespace controler
{

class ControllerServer
{
private:
    static void clientChangeCallback(int clientCount);
    communication::Server server;
    
    std::pair<Data, int> m_data;
    
    int iteratorOfClient =0;
    
    

public:
    ControllerServer(/* args */);
    ~ControllerServer();

    void init();
};


}



#endif // __CONTROLLERSERVER_H__