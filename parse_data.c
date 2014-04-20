#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "debug.h"
#include "data.h"

int g_no_of_clients;

int send_message_to_clients(int* sock,struct sockaddr_in multicast_addr)
{
    char message_to_send[MAX_LEN];
    unsigned int send_len;
    memset(message_to_send, 0, sizeof(message_to_send));
    while(1)
    {
        if(fgets(message_to_send,MAX_LEN,stdin))
        {
            send_len = strlen(message_to_send);
            if(send_len>1)
            {
                log_info("send_len is %d and message to send has %s",send_len,message_to_send );
                if ((sendto(*sock, message_to_send, send_len, 0,
                (struct sockaddr *) &multicast_addr,
                sizeof(multicast_addr))) != send_len)
                {
                    log_err("Error in number of bytes");
                    return -1;
                }
                else
                {
                    memset(message_to_send, 0, sizeof(message_to_send));
                    break;
                }
            }
            else
            {
                continue;
            }
        }
    }
    return 0;
}


int create_socket(int *sock,PROTOCOL protocol)
{
    int sock_id;
    log_info("ENTRY");
    switch(protocol)
    {
        case tcp:
            log_info("Yet to implement");
        break;

        case udp:
            if(*sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)<0)
            {
                log_err("socket() failed");
                return -1;
            }
            debug("sock_id is %d",*sock);
        break;

        default:
            log_info("dafault case");
        break;
    }
    log_info("EXIT");
    return 0;
}


void assign_task()
{
    int choice;
    while(1)
    {
        debug("ENTER YOUR CHOICE for the task\n1:Add\n2:sort\n3:multiply\n4:quit");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
        }

    }
    return;
}