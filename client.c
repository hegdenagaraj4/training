#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include  <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "debug.h"


int request_client()
{
	int client_sock,s;
	int rv=0;
	struct sockaddr_in port;
	struct sockaddr clientAddr;
	char echoString[25]="Message from client";
	char readBuff[255];

	log_info("ENTRY");
	client_sock = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP	);
	debug("socketid is %d",client_sock);

	port.sin_family			= AF_INET;
	port.sin_port			= htons(3400);
	port.sin_addr.s_addr	= inet_addr("127.0.0.1");

	rv = connect(client_sock,(struct sockaddr *)&port,sizeof(port));
	if(rv==-1)
	{
		log_err("connect() failed");
	}
	else
	{
		debug("connected to server client_sock is %d",client_sock);
		if(write(client_sock,"echoString from client",30)<0)
		{
			log_err("send() to server failed");
		}
		else
		{
			debug("sent message to server");
			rv=read(client_sock,readBuff,strlen(readBuff));
			if(rv<0)
			{
				log_err("read() failed");
			}
			else{
				debug("Message from server is %s",readBuff);
			}
			sleep(10);
			close(client_sock);
		}
		

		/**/

	}
	

	log_info("EXIT");
	return rv;

}


int main()
{
	int rv;
	rv = request_client();
	if(rv==-1)
	{
		log_err("request_client failed");
	}
	return 0;

}