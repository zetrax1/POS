#include <iostream>
#include <functional>
#include "communication/Client.hpp"
#include "communication/Server.hpp"
#include "communication/Data.hpp"


int main()
{


    // controler::Hra hra;

    // model::Postava postava;
    // postava.setPozicia(50 ,100 );
    // hra.addNewPostava(postava);
    // hra.init_hra();


    char choice;
    std::cout<<"stlac s pre server a c pre klienta"<<std::endl;
    std::cin>>choice; 
    if(choice == 's')
    {
        communication::Server server;
        //std::pair<Data, int> data = server.getFromReadQueue;
        while(true)
        {}
    }
    else
    {
        communication::Client client;
        client.sendMsg(Data());
        while(true)
        {}
    }
    
    return 0;
}


