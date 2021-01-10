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
#include <iterator>
#include <algorithm>
#include "Data.hpp"

namespace communication
{
    class SocketWrapper 
    {
        
    public:
        SocketWrapper(std::vector<char>& aMessageBuffer, void(&aErrorCallback)(std::string), void(&aDebugCallback)(std::string));
        ~SocketWrapper();
        int initServer(int port);
        int initClient(std::string serverAddress, int port);
        int serverListen();
        int clientConnect();
        int serverAccept();
        int sendMessage(int clientSocketFd, const std::pair<void *, size_t>&);
        std::pair<void *, size_t> receiveMessage(int clientSocketFd);
        int serverGetClientSocketFd(int count);
        int getSocketFd();
        int getClientsCount();
        void closeFd(int fd);
        
        
    private:
        
        void (&errorCallback)(std::string);
        void (&debugCallback)(std::string);
        
        int sokcetFd;
        std::vector<int> clientsSocketFd;
        struct sockaddr_in address;
        std::vector<char>& messageBuffer;
    };
} // namespace communication
#endif /* SOCKETWRAPPER_HPP */

