#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(){



int status;
char buffer[100];
int p[2];
ssize_t n;
pipe(p);
	if (!fork()){


	close(p[1]);
	dup2(p[0],0);
	close(p[0]);
	read(p[0],buffer,100);
	execlp("wc","wc",NULL);
	_exit(-1);

	}

	else{
	wait(&status);
	close(p[0]);
	dup2(p[1],1);
	
	while((n=read(0,buffer,10))>0){

		write(p[1],buffer,n);
	
	}
	close(p[1]);
	wait(&status);
	}

return 0;
}
