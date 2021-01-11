#include "ControllerServer.hpp"
#include <iostream>
#include <string>
#include <functional>

namespace controler
{
    void ControllerServer::clientChangeCallback(int clientCount) 
    {
        if(clientCount > 0)
        {
            server.sendMsg( clientCount - 1 ,Data(clientCount - 1));
            server.sendMsg(Data(clientCount*5, 50, clientCount - 1));
        }
        
        if(clientCount < 0)
        {
            //client n clientCount-1 was deleted
        }
    }


    ControllerServer::ControllerServer() : m_data(Data(0),0)
    {
        auto f = std::bind(&ControllerServer::clientChangeCallback, this, std::placeholders::_1);
        server.setCallClientChangeCallback(f);
    }

    ControllerServer::~ControllerServer()
    {
    }

    void ControllerServer::init() 
    {

        while (true)
        {
                
            m_data = server.getFromReadQueue();
            std::cout << "dostal spravu  \n";
            switch (m_data.first.getType())
            {
                case typeMessage::pohyb:
                {
                    std::cout << "dostal spravu pohyb server \n";
                     std::cout << "dostal som klienovi" << std::get<0>(m_data.first.getSmer()) << 
                     std::get<1>(m_data.first.getSmer())<< std::get<2>(m_data.first.getSmer()) << std::get<3>(m_data.first.getSmer())<< "\n";
                    server.sendMsg(m_data.first);
                }
                break;

                case typeMessage::newClient:
                {
                    std::cout << "new Client sprav prisla";
                }
                break;

                case typeMessage::initMessage:
                {
                    std::cout << "init Message sprav prisla";
                }
                break;

                default:
                {
                    std::cout << "neznamy typ spravy";
                }
                break;
            }


        } 
        
        
    }


}