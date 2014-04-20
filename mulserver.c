#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "debug.h"
#include "data.h"

/*declaring all the globals here*/
int g_fifo_fd;

/*start of the main function*/
int main(int argc, char *argv[])
{
    int sock;
    char* multicast_ip;
    unsigned short multicast_port;
    unsigned char multicast_ttl=1;
    struct sockaddr_in multicast_addr;
    int choice;
    PROTOCOL pro;

    if (argc != 3)
    {
        log_err( "Usage: %s Multicast_IP Multicast_Port\n", argv[0]);
        exit(1);
    }

    multicast_ip = argv[1];       /* arg 1: multicast IP address */
    multicast_port     = atoi(argv[2]); /* arg 2: multicast port number */
    /*pro = udp;
    create_socket(&sock,udp);*/
    /* create a socket*/
    if ((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
    {
        log_err("Socket creation failed");
        exit(1);
    }
    debug("socket_server is [%d]",sock);

    /* set the TTL (time to live/hop count) for the send */
    if ((setsockopt(sock, IPPROTO_IP, IP_MULTICAST_TTL, (void*) &multicast_ttl, sizeof(multicast_ttl))) < 0)
    {
        log_err("setsockopt() failed");
        exit(1);
    }

    memset(&multicast_addr, 0, sizeof(multicast_addr));
    multicast_addr.sin_family      = AF_INET;
    multicast_addr.sin_addr.s_addr = inet_addr(multicast_ip);
    multicast_addr.sin_port        = htons(multicast_port);

    //debug("Type the message below (Press Enter to send, ctrl-C to quit):\n");

    while (1)
    {
        log_info("ENTER YOUR CHOICE\n1:send Message\n2:Assign task\n3:Read data\n4:quit");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                log_info("Please enter the message to clients");
                send_message_to_clients(&sock,multicast_addr); /*sending message to all clients*/
            break;

            case 2:
                log_info("Yet to implement");
                assign_task();
            break;
            case 3:
                log_info("Yet to implement");
            break;
            case 4:
                log_info("SERVER exiting");
                exit(1);
            break;
            default:
                log_info("Unidentified case");
                exit(1);
                break;
        }
    }

    close(sock);

    exit(0);
}