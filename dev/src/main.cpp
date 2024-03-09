#include "../include/server.hpp"

int main() {
    UdpServer Server;
    Server.setPort(8080);
    int serverOK = Server.sockInit();
    if (serverOK != 0){
        std::cout << "server Init Failed.";
        return 0;
    }
    
    std::cout << "Server Listener Started!\n";

    while(1){
        Server.recvMessage();
    }
}