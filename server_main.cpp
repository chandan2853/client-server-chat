#include "./src/server.cpp"

int main() 
{
   Server server;
   server.validateSocket();
   server.setIP();
   server.validateBind();
   server.createChildProcess();
   return 0;
}

