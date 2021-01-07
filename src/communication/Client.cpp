#include "Client.hpp"

#define DEFAULT_PORT 8080
#define DEFAULT_IP "127.0.0.1"
#define DEFAULT_MESSAGE_BUFFER_SIZE 1024

Client::Client()
{
    serverIp = DEFAULT_IP;
    port = DEFAULT_PORT;
    messageBufferSize = DEFAULT_MESSAGE_BUFFER_SIZE;
    socketFd = -1;
}

Client::Client(std::string serverIp, int port, size_t messageBufferSize)
{
    serverIp = serverIp;
    port = port;
    messageBufferSize = messageBufferSize;
    socketFd = -1;
}

void Client::dbgcallback(std::string msg)
{
    std::cout<<"dbg client> "<<msg<<std::endl;
}

void Client::errcallback(std::string msg)
{
    std::cout<<"err client> "<<msg<<std::endl;
    exit(EXIT_FAILURE);
}

void Client::msgcallback(std::string msg)
{
    std::cout<<"msg client> "<<msg<<std::endl;
}

void Client::connectToServer()
{
    
}




