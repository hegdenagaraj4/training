#ifndef _data_h
#define _data_h

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LEN  1024
#define MAX_GROUPS 10
#define MAX_CLIENTS_IN_EACH_GROUP 10
typedef struct _group_info_
{
    uint8_t client_index;
    uint8_t group_index;
}GROUP_INFO;

typedef enum
{
    tcp=0,
    udp
}PROTOCOL;

int send_message_to_clients(int* sock,struct sockaddr_in multicast_addr);
int create_socket(int *sock,PROTOCOL protocol);
void assign_task();
#endif
