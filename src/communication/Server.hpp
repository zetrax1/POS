#ifndef SERVER_HPP
#define SERVER_HPP

#include "SocketWrapper.hpp"
#include <thread>
#include "Queue.hpp"
#include "Data.hpp"
#include <vector>
#include <mutex>

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
        std::pair<Data, int>  getFromReadQueue();
        
    private:
        
        int port;
        size_t messageBufferSize;
        Queue<std::pair<Data, int> > readQueue;
        std::vector<char> messageBuffer;
        SocketWrapper serverSocketWrapp;
        std::mutex mutex_;

        bool serverRunning();
        void listenAcceptClientInLoop();
        void listenClientsInThread();
        void readMessages(int index);
        void readMessagesInThread();

        static void errcallback(std::string msg);
        static void dbgcallback(std::string msg);
    };
} // namespace communication
#endif /* SERVER_HPP */
