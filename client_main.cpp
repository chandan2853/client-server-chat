#include "./src/client.cpp"
#include <thread>
int main()
{
   std::cout<<"Enter name : ";
   std::cin>>name;
   std::cin.ignore();
   Client client;
   client.validateSocket();
   client.setIP();
   client.validateConnection();
   std::thread snd(&Client::sendMsg,&client);
   std::thread recv(&Client::recvMsg,&client);
   snd.join();
   recv.join();
   return 0;
}