#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <thread>
#include <string>
#include <iostream>
#include <stdio.h>
#include "SocketWrapper.hpp"
#include "Queue.hpp"
#include "Data.hpp"

namespace communication
{

    class Client
    {

    public:
        Client();
        Client(std::string serverIp, int port, size_t messageBufferSize);
        void connectToServer();
        void sendMsg(const Data&);        
        void readMessagesInThread();


    private:
        SocketWrapper clientSocketWrapp;
        std::string serverIp;
        int port;
        size_t messageBufferSize;
        Queue<Data> readQueue;


        void readMessagesInLoop();
        bool isConectionActive();

        static void errcallback(std::string msg);
        static void dbgcallback(std::string msg);
        
    };

} // namespace communication
#endif /* CLIENT_HPP */