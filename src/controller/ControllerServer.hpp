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
    communication::Server server;
    int iteratorOfClient =0;
    std::pair<Data, int> m_data;

public:
    ControllerServer(/* args */);
    ~ControllerServer();

    void init();
};


}



#endif // __CONTROLLERSERVER_H__