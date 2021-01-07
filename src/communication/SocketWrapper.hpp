#ifndef SOCKETWRAPPER_HPP
#define SOCKETWRAPPER_HPP

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>

namespace communication
{
    class SocketWrapper 
    {
        
    public:
        SocketWrapper(size_t bufferSize);
        ~SocketWrapper();
        void initCallbacks(void(*aErrorCallback)(std::string), void(*aMessageCallback)(std::string), void(*aDebugCallback)(std::string));
        int initServer(int port);
        int initClient(std::string serverAddress, int port);
        int serverListen();
        int clientConnect();
        int serverAccept();
        int sendMessage(int clientSocketFd, std::string);
        std::string receiveMessage(int clientSocketFd);
        int serverGetClientSocketFd(int count);
        int clientGetServerSocketFd();
        
        
    private:
        
        void (*errorCallback)(std::string);
        void (*messageCallback)(std::string);
        void (*debugCallback)(std::string);

        int sokcetFd;
        std::vector<int> clientsSocketFd;
        struct sockaddr_in address;
        char* messageBuffer;
        size_t messageBufferSize;
    };
} // namespace communication
#endif /* SOCKETWRAPPER_HPP */

