#include <iostream>
#include <memory>

#include "screen/screen.h"
#include "chat/chat.h"
#include "tcpclient/tcpclient.h"

using tChat = Chat<tScreenContext, MainMenuScreen, tContainerForMessage, tMessageFactory, tContainerForUser, tUserManager>;

int main(int argc, char* argv[])
{
        TcpClient oTcpClient;	
	std::unique_ptr<tChat> pChat = std::make_unique<tChat>();
	pChat->Init(&oTcpClient);
	while (pChat->Run());
	oTcpClient.sendTo("end");
	return 0;
}
