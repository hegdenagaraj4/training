#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include  <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "debug.h"


int create_server()
{
	int socketid,s,clientLen;
	int rv=0;
	struct sockaddr_in port;
	struct sockaddr clientAddr;
	char readBuff[255]="";
	int recvMsgSize=0;

	log_info("ENTRY");
	socketid = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP	);
	debug("socketid is %d",socketid);

	port.sin_family			= AF_INET;
	port.sin_port			= htons(3400);
	port.sin_addr.s_addr	= htonl(INADDR_ANY);

	if(bind(socketid,(struct sockaddr *)&port,sizeof(port))!=-1)
	{
		debug("BIND SUCCESSFUL");
		rv = listen(socketid,10);
		if(rv!=-1)
		{
			log_info("listen() called successfuly");
			while(1)
			{
				clientLen = sizeof(clientAddr);
				s=accept(socketid,(struct sockaddr *)&clientAddr,&clientLen );
				if(s!=-1)
				{	
					log_info("accepted client socket is %d",s);
					sleep(6);
					recvMsgSize  = read(s,readBuff,255);
					if(recvMsgSize>=0)
					{
						debug("Message received is %s",readBuff);
						recvMsgSize = write(s,"I got your message",30);
						if(recvMsgSize>0)
						{
							debug("write() succesful");
						}
						else
						{
							log_err("write() failed");
						}
					}
					else
					{
						log_err("did not receive any message");
					}


				}
			}

		}
	}
	else
	{

		rv=-1;
		log_err("BIND FAILED");
	}

	log_info("EXIT");
	return rv;
}

int main()
{
	int ret_val;
	ret_val  = create_server();
	if(ret_val==-1)
	{
		log_err("SERVER COULD NOT BE CREATED");
	}



	return 0;
}

