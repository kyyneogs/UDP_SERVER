#include <server.h>

int main() {
    UdpServer server(8080);
    int serverOK = server.init();
    if (serverOK != 0){
        std::cout << "server Init Failed.";
        return 0;
    }
    
    std::cout << "Server Listener Started!\n";

    while(1){
        server.recvMessage();
    }
}