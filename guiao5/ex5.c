#include <sys.wait.h>
#include <stdio.h>
#include <unistd.h>

#define NUM_COM 4

int main(){
int p[2];

pipe(p);
/*
n processo = n-1 pipes
	ver prints
	
	p[n-1] [2];
*/


int main (int argc, char* ragv[]) {


char comandos[][100]= {
	{"grep -v ^# /etc/passwd"},
	{"cut -f7 -d:"},
	{"uniq"},
	{"wc -l"}

};

char buffer [10];
int c;
int status, bytes_read , pid, i;


int p[NUM_COM-1][2];


for(c=0;i<NUM_COM;i++){

	if(c==0){
		//1o comando
			if(pipe(p[c])==-1){
			perror("pipe");
			return -1;	
			}

	switch((pid=fork())){

	case -1: perror("fork");
		 return -1;
	case 0 : 
		 close(p[c][0]); //p[0][0]
		 dup2(p[c][1],1);
		 close(p[c][1]);
		 exec_command(comandos[c]);
		  _exit(-1);
	default:
		 close(p[c][1]);



	}
	
	if(c==NUM_COM-1){
		//ultimo comando
		switch((pid=fork())){
		case -1:
			perror("Erro fork");
			return -1;

		case 0:
			dup2(p[c][0],0);
			close(p[c][0]);
			exec_command(comandos[c]);
			_exit(-1);

		default:
			close(p[c][0]);
		
		}



	}
	else{

	}

}



}


}



}
