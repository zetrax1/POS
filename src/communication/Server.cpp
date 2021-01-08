#include "Server.hpp"

namespace communication
{
    Server::Server() : serverSocketWrapp(DEFAULT_MESSAGE_BUFFER_SIZE)
    {
        port = DEFAULT_PORT;
        messageBufferSize = DEFAULT_MESSAGE_BUFFER_SIZE;
    }

    Server::Server(int port, size_t messageBufferSize) : serverSocketWrapp(messageBufferSize)
    {
        port = port;
        messageBufferSize = messageBufferSize;
    }

    void Server::createServer()
    {
        serverSocketWrapp.initCallbacks(errcallback, msgcallback, dbgcallback);
        serverSocketWrapp.initServer(port);
        listenClients();
    }

    void Server::sendMsg(int clientIndex, const std::string& msg)
    {
        if (serverRunning())
        {
            serverSocketWrapp.sendMessage(serverSocketWrapp.serverGetClientSocketFd(clientIndex), msg);
        }
    }
    
    void Server::readMessages(int clientIndex) 
    {
        while(serverSocketWrapp.serverGetClientSocketFd(clientIndex) > 0)
        {
            std::string incommingMsg = serverSocketWrapp.receiveMessage(serverSocketWrapp.serverGetClientSocketFd(clientIndex));
            //todo: call callback function
        }
    }

    void Server::listenClients()
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
            readMessages(serverSocketWrapp.serverGetClientSocketFd(serverSocketWrapp.getClientsCount()-1));
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

    void Server::msgcallback(std::string msg)
    {
        if (msg.size() > 0) std::cout << "msg server> " << msg << std::endl;
    }

} // namespace communication