all: server client

server: mulserver.c parse_data.c
	gcc -o server mulserver.c parse_data.c -I.
client: mulclient.c parse_data.c
	gcc -o client mulclient.c parse_data.c -I.
