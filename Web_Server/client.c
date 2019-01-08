
#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int client (char *host, int port);

int main (int argc, char *argv[])
{
	char *host, *filename;
	int port, r;

	host = "127.0.0.1";
	port = 8080;

	r = client (host, port);
	return r;
}


int client (char *host, int port)
{
	int r, s;
	struct sockaddr_in sin;
	char buf[1024];

	/* Make the connection */
	bzero (&sin, sizeof (sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons (port);
	inet_aton (host, &sin.sin_addr);
	char filename[400];

	/* Write the filename */
	while(1){
		s = socket (AF_INET, SOCK_STREAM, 0);
		connect (s, (struct sockaddr *) &sin, sizeof (sin));
		printf("Give string: ");
		scanf("%s",filename);
		printf("\n");
		write (s, filename, strlen (filename));

		/* Send the bytes that come back to stdout */
		r = read (s, buf, sizeof (buf));
		buf[r] = '\0';
		write (1, buf, strlen(buf));
		printf("\n");
		close(s);
	}

	/* Finish out */
	return 0;
}