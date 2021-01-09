#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <thread>
#include <string>
#include <iostream>
#include <stdio.h>
#include "SocketWrapper.hpp"
#include "Queue.hpp"

namespace communication
{
    template <typename T> 
    class Client
    {

    public:
        Client();
        Client(std::string serverIp, int port, size_t messageBufferSize);
        void connectToServer();
        void sendMsg(T);        
        void readMessagesInThread();


    private:
        SocketWrapper<T> clientSocketWrapp;
        std::string serverIp;
        int port;
        size_t messageBufferSize;
        Queue<T> readQueue;


        void readMessagesInLoop();
        bool isConectionActive();

        static void errcallback(std::string msg);
        static void dbgcallback(std::string msg);
        
    


    void Client<T>::readMessagesInLoop() 
    {
        while(isConectionActive())
        {
            T incommingMsg = clientSocketWrapp.receiveMessage(clientSocketWrapp.getSocketFd());
            if (incommingMsg != nullptr)
            {
                readQueue.push(incommingMsg);
            }
        }
    }

    void Client<T>::sendMsg(T msg) 
    {
        if(isConectionActive())
        {
            clientSocketWrapp.sendMessage(clientSocketWrapp.getSocketFd(), msg);
        }
    }

    };

} // namespace communication
#endif /* CLIENT_HPP */