#ifndef SERVER_HPP
#define SERVER_HPP

#include "SocketWrapper.hpp"
#include <thread>
#include "Queue.hpp"
#include "Data.hpp"

#define DEFAULT_PORT 8080
#define DEFAULT_MESSAGE_BUFFER_SIZE 1024


namespace communication
{
    class Server
    {
    public:
        Server();
        Server(int port, size_t messageBufferSize);
        void createServer();
        void sendMsg(int clientIndex, const Data&);
        void sendMsg(const Data&);
        
        

    private:
        SocketWrapper serverSocketWrapp;
        int port;
        size_t messageBufferSize;
        Queue<Data> readQueue;

        bool serverRunning();
        void listenAcceptClientInLoop();
        void listenClientsInThread();
        void readMessages();
        void readMessagesInThread();

        static void errcallback(std::string msg);
        static void dbgcallback(std::string msg);
    };
} // namespace communication
#endif /* SERVER_HPP */
