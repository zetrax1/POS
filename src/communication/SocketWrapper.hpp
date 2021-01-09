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
    template <typename T> 
    class SocketWrapper 
    {
        
    public:
        SocketWrapper(size_t bufferSize, void(&aErrorCallback)(std::string), void(&aDebugCallback)(std::string));
        ~SocketWrapper();
        int initServer(int port);
        int initClient(std::string serverAddress, int port);
        int serverListen();
        int clientConnect();
        int serverAccept();
        int sendMessage(int clientSocketFd, const T&);
        T receiveMessage(int clientSocketFd);
        int serverGetClientSocketFd(int count);
        int getSocketFd();
        int getClientsCount();
        
        
    private:
        
        void (&errorCallback)(std::string);
        void (&debugCallback)(std::string);

        int sokcetFd;
        std::vector<int> clientsSocketFd;
        struct sockaddr_in address;
        char* messageBuffer;
        size_t messageBufferSize;
    };
} // namespace communication
#endif /* SOCKETWRAPPER_HPP */

