#include <iostream>
#include <functional>
#include "communication/Client.hpp"
#include "communication/Server.hpp"
#include "communication/Data.hpp"

/*
bool testLambda(const std::function<bool[& test](int)>& hocico) 
{
    bool returnValue = hocico(12);


    return returnValue;
}
*/


int main()
{
    /*
    int test = 5;
    int tets2 = 10;

    bool value1 = testLambda([&](int a) 
    {
        test = 20;
        return a > test;    
    });
    
    bool value2 = testLambda([=](int a) 
    {
        test2 = 15;
        return a < tets2;
    } );

    std::cout << value1 << std::endl << value2 << std::endl;
    */



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


