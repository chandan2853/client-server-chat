#include "../include/server.h"
#include <thread>
void Server::validateSocket()
{
    if((sock=socket(AF_INET,SOCK_STREAM,0))==0)
    {
        errorHandling("Socket ERROR");
    }
}
void Server::setIP()
{
    memset(&serverAddr,'0',sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(Port);
}
void Server::validateBind()
{
    if (bind(sock, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0) 
    {
        errorHandling("ERROR on binding");
    }
    listen(sock,5);
    clientAddrLen = sizeof(clientAddr);
}
void Server::createChildProcess()
{
    while (1) 
    {
        newsock = accept(sock, (struct sockaddr *) &clientAddr, &clientAddrLen);
        if (newsock < 0) 
        {
            errorHandling("ERROR on accept the socket");
        }
        pid = fork();
        if (pid < 0) 
        {
            errorHandling("ERROR on fork");
        }
        if (pid == 0) 
        {
            close(sock);
            messageOperations(newsock);
            exit(0);
        }
        else 
        {
            close(newsock);
        }
        
    }
}
void Server::messageOperations(int sock)
{
    while(1)
    {
        int flag;
        char buffer[256];
        flag=read(sock,buffer,255);
        if(flag<0) 
        {
            errorHandling("ERROR reading from socket");
        }
        std::cout<<"Message from "<<buffer<<std::endl;
        memset(&buffer,0,sizeof(buffer));
        std::cin>>buffer;
        flag=write(sock,buffer,strlen(buffer));
        memset(&buffer,0,sizeof(buffer));
        if(flag<0) 
        {
            errorHandling("ERROR writing to socket");
        }
    }
}
void Server::errorHandling(const std::string errorMessage)
{
    std::cerr<<errorMessage<<std::endl;
    exit(1);
}