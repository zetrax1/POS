#include "ControllerServer.hpp"
#include <iostream>
#include <string>

namespace controler
{
    void ControllerServer::clientChangeCallback(int clientCount) 
    {
        
    }


ControllerServer::ControllerServer() : server(clientChangeCallback),
                                       m_data(Data(0),0)
{
}

ControllerServer::~ControllerServer()
{
}

void ControllerServer::init() 
{

    do
    {
            
    m_data = server.getFromReadQueue();
    switch (m_data.first.getType())
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


    } 
    while (std::cin.get() != 27);
    
}


}