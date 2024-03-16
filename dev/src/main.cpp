#include <server.h>
#include <iostream>

int main()
{
  UdpServer server(8080);
  server.init();

  std::cout << "Server Listener Started!\n";

  unsigned char recvBuff[RECV_BUFF] = {0, };
  while (1)
  {
    server.recvMessage(recvBuff);
    if (recvBuff[0] == 0)
      break;
    std::cout << recvBuff << "\n";
  }
}