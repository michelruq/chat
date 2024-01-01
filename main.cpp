#include <iostream>
#include <memory>

#include "screen/screen.h"
#include "chat/chat.h"

using tChat = Chat<ScreenContext<Screen>, InvitationScreen>;

int main(int argc, char* argv[])
{
	std::unique_ptr<tChat> pChat = std::make_unique<tChat>();
	while (pChat->Run());
	return 0;
}