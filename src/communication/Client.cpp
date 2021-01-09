#include "Client.hpp"

#define DEFAULT_PORT 8080
#define DEFAULT_IP "127.0.0.1"
#define DEFAULT_MESSAGE_BUFFER_SIZE 1024

namespace communication
{

    Client::Client() : 
        clientSocketWrapp(DEFAULT_MESSAGE_BUFFER_SIZE, errcallback, dbgcallback)
    {
        serverIp = DEFAULT_IP;
        port = DEFAULT_PORT;
        messageBufferSize = DEFAULT_MESSAGE_BUFFER_SIZE;
    }

    Client::Client(std::string serverIp, int port, size_t messageBufferSize) : clientSocketWrapp(messageBufferSize, errcallback, dbgcallback)
    {
        serverIp = serverIp;
        port = port;
        messageBufferSize = messageBufferSize;

    }

    void Client::dbgcallback(std::string msg)
    {
        std::cout << "dbg client> " << msg << std::endl;
    }

    void Client::errcallback(std::string msg)
    {
        std::cout << "err client> " << msg << std::endl;
        exit(EXIT_FAILURE);
    }

    void Client::connectToServer()
    {
        clientSocketWrapp.initClient(serverIp, port);
        clientSocketWrapp.clientConnect();
        readMessagesInThread();
    }

    

    bool Client::isConectionActive()
    {
        if (clientSocketWrapp.getSocketFd() > 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    


    
    void Client::readMessagesInThread() 
    {
        std::thread(&Client::readMessagesInLoop, this).detach();
    }

} // namespace communication

