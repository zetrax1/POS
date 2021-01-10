#include "Server.hpp"

namespace communication
{
    Server::Server() : 
    messageBuffer(DEFAULT_MESSAGE_BUFFER_SIZE),
    serverSocketWrapp(messageBuffer, errcallback, dbgcallback) 
    {
        port = DEFAULT_PORT;
        messageBufferSize = DEFAULT_MESSAGE_BUFFER_SIZE;
        createServer();
    }

    Server::Server(int port, size_t messageBufferSize) : 
    messageBuffer(messageBufferSize),
    serverSocketWrapp(messageBuffer, errcallback, dbgcallback)
    {
        port = port;
        messageBufferSize = messageBufferSize;
        createServer();
    }

    void Server::createServer()
    {
        serverSocketWrapp.initServer(port);
        listenClientsInThread();
    }

    void Server::sendMsg(int clientIndex, const Data &msg)
    {
        if (serverRunning())
        {
            serverSocketWrapp.sendMessage(serverSocketWrapp.serverGetClientSocketFd(clientIndex), std::pair((void *)&msg, sizeof(msg)));
        }
    }

    void Server::sendMsg(const Data &msg)
    {
        if (serverRunning())
        {
            for (int i = 0; i != serverSocketWrapp.getClientsCount(); i++)
            {
                serverSocketWrapp.sendMessage(serverSocketWrapp.serverGetClientSocketFd(i), std::pair((void *)&msg, sizeof(msg)));
            }
        }
    }
    
    std::pair<Data, int> Server::getFromReadQueue() 
    {
        return readQueue.pop();
    }
    
    int Server::getActiveClients() 
    {
        return serverSocketWrapp.getCountActiveClients();
    }
    
    void Server::setCallClientChangeCallback(std::function<void(int)> callFunction) 
    {
        m_callClientChangeCallback = callFunction;
    }
    
    void Server::useCallClientChangeCallback(int param) 
    {
        m_callClientChangeCallback(param);
    }

    void Server::readMessages(int index)
    {
        int fd = serverSocketWrapp.serverGetClientSocketFd(index);
        while (fd > 0)
        {
            
            std::pair<void *, size_t> incommingMsg = serverSocketWrapp.receiveMessage(fd);
            if (incommingMsg.second > 0)
            {
                std::unique_lock<std::mutex> mlock(mutex_);
                Data *data = (Data*)incommingMsg.first;
                readQueue.push(std::pair(*data, fd));
                std::cout << "msg server> " << sizeof(incommingMsg) << " " << fd << std::endl;
                mlock.unlock();
            }
        }

    }

    void Server::readMessagesInThread()
    {
        std::thread(&Server::readMessages, this, serverSocketWrapp.getClientsCount() - 1).detach();
    }
    
    void Server::deleteClient(int fd) 
    {
        int d = serverSocketWrapp.deleteClient(fd);
        if (d > 0)
        {
            useCallClientChangeCallback(-d);
        }        
    }

    void Server::listenClientsInThread()
    {
        std::thread(&Server::listenAcceptClientInLoop, this).detach();
    }

    bool Server::serverRunning()
    {
        if (serverSocketWrapp.getSocketFd() < 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    void Server::listenAcceptClientInLoop()
    {
        while (serverRunning())
        {
            serverSocketWrapp.serverListen();
            serverSocketWrapp.serverAccept();
            useCallClientChangeCallback(serverSocketWrapp.getClientsCount());
            readMessagesInThread();
        }
    }

    void Server::dbgcallback(std::string msg)
    {
        std::cout << "dbg server> " << msg << std::endl;
    }

    void Server::errcallback(std::string msg)
    {
        std::cout << "err server> " << msg << std::endl;
        exit(EXIT_FAILURE);
    }

} // namespace communication