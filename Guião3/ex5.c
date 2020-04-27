#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main (int argc, char * argv[]){
	
pid_t pid;
int status;

	for(int i=1; i<argc ; i++){
		
		if ((pid=fork())==0){
		printf("execl:\n");	
			execlp(argv[i],argv[i],NULL);

		}

	_exit(i);
	}
		
	for(int i=1;i<argc;i++){
	 
		wait(NULL);
		printf("pai chegou\n");

	}
	


return 0;
}
