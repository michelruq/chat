#pragma once

#include <iostream>
#include <unistd.h>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "buffer.h"

#define PORT 7777
#define MESSAGE_LENGTH 1024

class TcpClient
{
   public:
      TcpClient() : oBuffer(MESSAGE_LENGTH)
      {	      
         socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
         if(socket_file_descriptor == -1)
         {
            std::cout << "Creation of Socket failed!" << std::endl;
	    std::exit(1);
         }

         serveraddress.sin_addr.s_addr = inet_addr("127.0.0.1");
         serveraddress.sin_port = htons(PORT);
         serveraddress.sin_family = AF_INET;
         int connection = connect(socket_file_descriptor, (struct sockaddr*)&serveraddress, sizeof(serveraddress));
        if(connection == -1)
        {
           std::cout << "Connection with the server failed.!" << std::endl;
	   std::exit(1);
        }
      }

      ~TcpClient()
      {
	 std::cout << "Connection with the server closed.!" << std::endl;
         close(socket_file_descriptor);
      }

      ssize_t sendTo(std::string incomingString)
      {
	 oBuffer.serialize(incomingString);
         return write(socket_file_descriptor, oBuffer.getPointerToBuffer(), oBuffer.getBufferSize());
      }	

      void recieveFrom(std::string & outgoingString)
      {
         oBuffer.clear();
         read(socket_file_descriptor, oBuffer.getPointerToBuffer(), oBuffer.getBufferSize());
	 oBuffer.deserialize(outgoingString); 
      } 	 

   private:
      int socket_file_descriptor;
      struct sockaddr_in serveraddress;

      Buffer oBuffer;
      
};

