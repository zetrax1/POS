#include <iostream>
#include <functional>
#include "communication/Client.hpp"
#include "communication/Server.hpp"
#include "communication/Data.hpp"


int main()
{
    char choice;
    std::cout<<"stlac s pre server a c pre klienta"<<std::endl;
    std::cin>>choice; 
    if(choice == 's')
    {
        communication::Server server;
        
        
        while(true)
        {
            std::pair<Data, int> data = server.getFromReadQueue();
            std::cout<<"data from client FD number<"<<data.second<<">--|"<<data.first.a<<" "<<data.first.b<<"|--"<<std::endl;
            server.sendMsg(Data(data.first.a+1, data.first.a+1));
        }
    }
    else
    {
        communication::Client client;
        client.sendMsg(Data(20, 'M'));

        while(true)
        {
            Data data = client.getFromReadQueue();
            std::cout<<"data from server: "<<data.a<<" "<<data.b<<"||--"<<std::endl;
        }
    }
    
    return 0;
}


