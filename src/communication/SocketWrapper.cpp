#include "SocketWrapper.hpp"

namespace communication
{

    SocketWrapper::SocketWrapper(size_t bufferSize, void(&aErrorCallback)(std::string), void(&aDebugCallback)(std::string)):
        errorCallback (aErrorCallback),
        debugCallback (aDebugCallback),
        messageBuffer (new char[bufferSize]),
        messageBufferSize (bufferSize)
    {
        //todo: init client init server
    }

    SocketWrapper::~SocketWrapper()
    {
        delete [] messageBuffer;
        close(sokcetFd);
        if(clientsSocketFd.size() > 0)
        {
            for (size_t i = 0; i < clientsSocketFd.size(); i++)
            {
                close(i);
            }
            
        }
    }


    int SocketWrapper::initServer(int port)
    {
        // Creating socket file descriptor 
        int ret = sokcetFd = socket(AF_INET, SOCK_STREAM, 0);
        
        if (ret < 1)
        {
            if (errorCallback) errorCallback("socket failed");
            return 1;
        }
        
        if (debugCallback) debugCallback("socket init");
            
        
        // Forcefully attaching socket to the port 8080 
        int opt =1;
        
        ret = setsockopt(sokcetFd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
        
        if (debugCallback) debugCallback("options init");    
        

        address.sin_family = AF_INET; 
        address.sin_addr.s_addr = INADDR_ANY; 
        address.sin_port = htons( port ); 
        
        ret = bind(sokcetFd, (struct sockaddr *)&address, sizeof(address));
        
        if (ret < 0)
        {
            if (errorCallback) errorCallback("bind failed");
            return 1;
        }
        if (debugCallback) debugCallback("bind");
        
        return 0;
    }

    int SocketWrapper::initClient(std::string serverAddress, int port)
    {
        int ret = sokcetFd = socket(AF_INET, SOCK_STREAM, 0);
        
        if(ret < 0)
        {
            if (errorCallback) errorCallback("socket failed");
            return 1;
        }
        
        if (debugCallback) debugCallback("socket init");
        
        address.sin_family = AF_INET; 
        address.sin_port = htons(port);
        
        
        // Convert IPv4 and IPv6 addresses from text to binary form 
        
        ret = inet_pton(AF_INET, serverAddress.c_str(), &address.sin_addr);
        if(ret <= 0) 
        {
            if (errorCallback) errorCallback("invalid address");
            return 1;
        }
        if (debugCallback) debugCallback("address init");
        
        return 0;
    }

    int SocketWrapper::serverListen()
    {
        int ret = listen(sokcetFd, SOMAXCONN);
        
        if (ret < 0)
        {
            if (errorCallback) errorCallback("listen failed");
            return 1;
        }
        
        if (debugCallback) debugCallback("listen");
        
        return 0;
    }

    int SocketWrapper::clientConnect()
    {
        int ret = connect(sokcetFd, (struct sockaddr *)&address, sizeof(address));
        if (ret < 0) 
        { 
            if (errorCallback) errorCallback("connect failed");
            return 1;
        }
        
        if (debugCallback) debugCallback("conected");
        
        return 0;
    }

    int SocketWrapper::serverAccept()
    {
        socklen_t addrlen = sizeof(address);
        
        int newKlient = accept(sokcetFd, (struct sockaddr *)&address, &addrlen);    
        
        if(newKlient < 0)
        {
            if (errorCallback) errorCallback("accept failed");
            return 1;
        }
        if (debugCallback) debugCallback("accept");
        
        clientsSocketFd.push_back(newKlient);
        
        return 0;
    }

    int SocketWrapper::sendMessage(int clientSocketFd, const Data& message)
    {
        if (debugCallback) debugCallback("sent");
        return send(clientSocketFd, &message, sizeof(message), 0);
    }

    Data SocketWrapper::receiveMessage(int clientSocketFd)
    {    
        int len = read(clientSocketFd, messageBuffer, messageBufferSize);
        if(len > 0)
        {
            if (debugCallback) debugCallback("received");

            //return std::string(messageBuffer, len);
            Data* data = (Data*)messageBuffer;
            return *data;
        }

        return {};
    }

    int SocketWrapper::serverGetClientSocketFd(int number)
    {
        return this->clientsSocketFd[number];
    }

    int SocketWrapper::getSocketFd()
    {
        return sokcetFd;
    }
    
    int SocketWrapper::getClientsCount() 
    {
        return this->clientsSocketFd.size();
    }
    
    void SocketWrapper::closeFd(int fd) 
    {
        close(fd);
    }
}

