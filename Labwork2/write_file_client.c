/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "write_file.h"
#include <unistd.h>

void
transfer_prog_1(char *host, char name[1024], char file_content[1024])
{
	CLIENT *clnt;
	int  *result_1;
	data  transfer_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, TRANSFER_PROG, TRANSFER_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	transfer_1_arg.file_name[1024] = name;
	transfer_1_arg.file_data[1024] = file_content;
	
	result_1 = transfer_1(&transfer_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	while (1) {
        	// after connected, it's client turn to chat

        	// send some data to server
        	char s[1024];
        	printf("client> Enter filename to send: ");
        	scanf("%s", s);
        
       	if( access( s, F_OK ) == 0 ) {
       		FILE *fp;
       		char data[1024]={0};
       		fp = fopen(s, "rb+");
       		 while(fread(data, 1,1024, fp) != 0){
       		 	transfer_prog_1 (host, s, data);
       		 	bzero(data, 1024);
		       }
       		printf("Sent to server\n");
		} else {
    			printf("File doesn't exist!\n");
		}
	}
	return 0;
};
