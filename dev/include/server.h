#ifdef _WIN32
#include <WS2tcpip.h>

#else
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#endif

#define RECV_BUFF 1024

class UdpServer {
 private:
  int port;
  int serverSock;
  struct sockaddr_in serverAddr, clientAddr;
#ifdef _WIN32
  int clientLen;
#else
  socklen_t clientLen;
#endif

 public:
  UdpServer(int port);
  ~UdpServer();
  void init();
  void recvMessage(unsigned char* recvBuff);
};