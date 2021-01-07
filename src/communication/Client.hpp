#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <iostream>
#include <stdio.h>

#include "SocketWrapper.hpp"

class Client : client{messageBufferSize}
{
    
public:
    Client();
    Client(std::string serverIp, int port, size_t messageBufferSize);
    void errcallback(std::string msg);
    void dbgcallback(std::string msg);
    void msgcallback(std::string msg);
    
    void connectToServer();
    void sendMsg(std::string);
    
private:
    SocketWrapper client;
    std::string serverIp;
    int port;
    size_t messageBufferSize;
    int socketFd;
    

};

#endif /* CLIENT_HPP */

