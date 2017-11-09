#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

static void sighandler(int signo){
	if(signo == SIGINT){
		int output_fi = open("output.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
		//printf("%d\n", output_fi);
		char msg[32] = "System exited due to SIGINT\n";
		int error = write(output_fi, msg, sizeof(msg));
		if(error == -1){
			printf("ERROR: %s\n", strerror(errno));
		}
		close(output_fi);
		exit(1);
	}

	if(signo == SIGUSR1){
		printf("PID IS: %d\n", getpid());
	}
}

int main(){
	signal(SIGINT, sighandler);
	signal(SIGUSR1, sighandler);

	while(1){
		printf("Wowzers Trousers my PID is %d\n", getpid());
		sleep(1);
	}
}
