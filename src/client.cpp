#include "../include/client.h"

void Client::validateSocket()
{
   if((sock=socket(AF_INET,SOCK_STREAM,0))==0)
   {
      errorHandling("Socket ERROR");;
   }
}

void Client::setIP()
{
   memset(&serv_addr,'0',sizeof(serv_addr));
   serv_addr.sin_family=AF_INET;
   serv_addr.sin_port=htons(Port);
}

void Client::validateConnection()
{
   if(inet_pton(AF_INET,IPaddr,&serv_addr.sin_addr)<=0)
   {
      errorHandling("Invalid IP");;
   }
   if(connect(sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
   {
      errorHandling("Connection ERROR");;
   }
}

void Client::sendMsg()
{
   while(true)
   {
      std::string msg;
      getline(std::cin,msg);
      if(msg=="exit")
      {
         exit(1);
      }
      msg="["+name+"] :"+msg;
      memset(&buffer,0,sizeof(buffer));
      strcpy(buffer,msg.c_str());
      send(sock,buffer,strlen(buffer),0);
      memset(&buffer,0,sizeof(buffer));
   }
}
void Client::recvMsg()
{
   while(true)
   {
      memset(&buffer,0,sizeof(buffer));
      read(sock,buffer,1000);
      std::cout<<"Message from server :"<<buffer<<"\n";
      memset(&buffer,0,sizeof(buffer));
   }
}

void Client::errorHandling(const std::string errorMessage)
{
    std::cerr<<errorMessage<<std::endl;
    exit(1);
}