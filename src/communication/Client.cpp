#include "Client.hpp"

#define DEFAULT_PORT 8080
#define DEFAULT_IP "127.0.0.1"
#define DEFAULT_MESSAGE_BUFFER_SIZE 1024

namespace communication
{

    Client::Client() : 
        messageBuffer(DEFAULT_MESSAGE_BUFFER_SIZE),
        clientSocketWrapp(messageBuffer, errcallback, dbgcallback)
    {
        serverIp = DEFAULT_IP;
        port = DEFAULT_PORT;
        messageBufferSize = DEFAULT_MESSAGE_BUFFER_SIZE;
        connectToServer();
    }

    Client::Client(std::string serverIp, int port, size_t messageBufferSize) : 
        messageBuffer(DEFAULT_MESSAGE_BUFFER_SIZE),
        clientSocketWrapp(messageBuffer, errcallback, dbgcallback)
    {
        serverIp = serverIp;
        port = port;
        messageBufferSize = messageBufferSize;
        connectToServer();
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
    
    void Client::readMessagesInLoop()
    {
        while(isConectionActive())
        {
            std::unique_lock<std::mutex> mlock(mutex_);
            std::pair<void*, size_t> incommingMsg = clientSocketWrapp.receiveMessage(clientSocketWrapp.getSocketFd());
            if (incommingMsg.second > 0)
            {
                Data* data = (Data*)incommingMsg.first;
                readQueue.push(*data);
                std::cout << "msg server> "<< incommingMsg.second<<" Bytes"<<std::endl;
            }
            mlock.unlock();
        }
    }


    void Client::sendMsg(const Data& msg) 
    {
        if(isConectionActive())
        {
            clientSocketWrapp.sendMessage(clientSocketWrapp.getSocketFd(), std::pair((void*)&msg, (size_t)sizeof(msg)));
        }
    }

    
    void Client::readMessagesInThread() 
    {
        std::thread(&Client::readMessagesInLoop, this).detach();
    }
    
    Data Client::getFromReadQueue() 
    {
        return readQueue.pop();
    }

} // namespace communication

