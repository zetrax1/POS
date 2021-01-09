#include "Server.hpp"

namespace communication
{
    Server::Server() : serverSocketWrapp(DEFAULT_MESSAGE_BUFFER_SIZE, errcallback, dbgcallback)
    {
        port = DEFAULT_PORT;
        messageBufferSize = DEFAULT_MESSAGE_BUFFER_SIZE;
    }

    Server::Server(int port, size_t messageBufferSize) : serverSocketWrapp(messageBufferSize, errcallback, dbgcallback)
    {
        port = port;
        messageBufferSize = messageBufferSize;
    }

    void Server::createServer()
    {
        serverSocketWrapp.initServer(port);
        listenClientsInThread();
        readMessagesInThread();
    }

    void Server::sendMsg(int clientIndex, const Data& msg)
    {
        if (serverRunning())
        {
            serverSocketWrapp.sendMessage(serverSocketWrapp.serverGetClientSocketFd(clientIndex), msg);
        }
    }
    
    void Server::sendMsg(const Data& msg) 
    {
        if (serverRunning())
        {
            for(int i = 0; i != serverSocketWrapp.getClientsCount(); i++) 
            { 
                serverSocketWrapp.sendMessage(serverSocketWrapp.serverGetClientSocketFd(i), msg);
            }
        }
    }
    
    void Server::readMessages() 
    {
        while(serverRunning())
        {
            for(int i = 0; i < serverSocketWrapp.getClientsCount(); i++) 
            {
                if(serverSocketWrapp.serverGetClientSocketFd(i) > 0)
                {
                    Data incommingMsg = serverSocketWrapp.receiveMessage(serverSocketWrapp.serverGetClientSocketFd(i));
                    if (sizeof(incommingMsg) != 0)
                    {
                        readQueue.push(incommingMsg);
                        std::cout << "msg server> " << sizeof(incommingMsg) << std::endl;
                    }
                }
            }
        }
    }
    
    void Server::readMessagesInThread() 
    {
        std::thread(&Server::readMessages, this).detach();
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