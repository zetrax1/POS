#ifndef SERVER_HPP
#define SERVER_HPP

#include "SocketWrapper.hpp"
#include <thread>

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
        void sendMsg(int clientIndex, const std::string&);
        void readMessages(int clientIndex);
        

    private:
        SocketWrapper serverSocketWrapp;
        int port;
        size_t messageBufferSize;

        bool serverRunning();
        void listenAcceptClientInLoop();
        void listenClients();

        static void errcallback(std::string msg);
        static void dbgcallback(std::string msg);
        static void msgcallback(std::string msg);
    };
} // namespace communication
#endif /* SERVER_HPP */
