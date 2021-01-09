#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <thread>
#include <string>
#include <iostream>
#include <stdio.h>
#include "SocketWrapper.hpp"
#include "Queue.hpp"
#include "Data.hpp"
#include <vector>
#include <mutex>
#include <chrono>

namespace communication
{

    class Client
    {

    public:
        Client();
        Client(std::string serverIp, int port, size_t messageBufferSize);
        
        void sendMsg(const Data&);        
        Data getFromReadQueue();

    private:
        
        std::string serverIp;
        int port;
        size_t messageBufferSize;
        Queue<Data> readQueue;
        std::vector<char> messageBuffer;
        SocketWrapper clientSocketWrapp;
        std::mutex mutex_;

        void connectToServer();
        void readMessagesInLoop();
        bool isConectionActive();
        void readMessagesInThread();

        static void errcallback(std::string msg);
        static void dbgcallback(std::string msg);
        
    };

} // namespace communication
#endif /* CLIENT_HPP */