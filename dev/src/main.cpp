#include <iostream>
#include <server.h>

int main() {
    UdpServer server(8080);
    server.init();
    
    std::cout << "Server Listener Started!\n";

    while(1){
        server.recvMessage();
    }
}