#ifndef SERVER_HPP
#define SERVER_HPP

#include "SocketWrapper.hpp"
#include <thread>
#include "Queue.hpp"

#define DEFAULT_PORT 8080
#define DEFAULT_MESSAGE_BUFFER_SIZE 1024


namespace communication
{
    template <typename T> 
    class Server
    {
    public:
        Server();
        Server(int port, size_t messageBufferSize);
        void createServer();
        void sendMsg(int clientIndex, const T&);
        void sendMsg(const T&);
        
        

    private:
        SocketWrapper<T> serverSocketWrapp;
        int port;
        size_t messageBufferSize;
        Queue<std::pair<int, T> > readQueue;

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
