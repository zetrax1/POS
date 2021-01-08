#include "Client.hpp"

#define DEFAULT_PORT 8080
#define DEFAULT_IP "127.0.0.1"
#define DEFAULT_MESSAGE_BUFFER_SIZE 1024

namespace communication
{

    Client::Client() : 
        clientSocketWrapp(DEFAULT_MESSAGE_BUFFER_SIZE), 
        aErrorCallback(errcallback), 
        aErrorCallback(msgcallback), 
        dbgcallback
    {
        serverIp = DEFAULT_IP;
        port = DEFAULT_PORT;
        messageBufferSize = DEFAULT_MESSAGE_BUFFER_SIZE;
    }

    Client::Client(std::string serverIp, int port, size_t messageBufferSize) : clientSocketWrapp(messageBufferSize)
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

    void Client::msgcallback(std::string msg)
    {
        if (msg.size() > 0)  std::cout << "msg client> " << msg << std::endl;
    }

    void Client::connectToServer()
    {
        clientSocketWrapp.initCallbacks(errcallback, msgcallback, dbgcallback);
        clientSocketWrapp.initClient(serverIp, port);
        clientSocketWrapp.clientConnect();
    }

    

    bool Client::isConectionActive()
    {
        if (clientSocketWrapp.getSocketFd() < 1)
        {
            return false;
        }
        else
        {
            return true;
        }
        
    }
    
    void Client::readMessagesInLoop() 
    {
        while(isConectionActive())
        {
            std::string incomingMsg = clientSocketWrapp.receiveMessage(clientSocketWrapp.getSocketFd());
            //todo: call callback function
        }
    }

    void Client::sendMsg(std::string msg) 
    {
        if(isConectionActive())
        {
            clientSocketWrapp.sendMessage(clientSocketWrapp.getSocketFd(), msg);
        }
    }

    
    void Client::readMessages() 
    {
        std::thread(&Client::readMessagesInLoop, this).detach();
    }

} // namespace communication

