#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>

int main(){
	
	int fderror = open("erros.txt", O_RDWR | O_CREAT, 0666);
	int fdout = open ("saida.txt" , O_CREAT | O_RDWR , 0666);
	int fdin = open ("/etc/passwd", O_RDWR, 0666);

		dup2(1,fdout);
		dup2(2,fderror);

	write(0,"abcedf\n",7);
	
	write(1,"abcedf\n",7);

	write(2,"abcedf\n",7);

		dup2(0,fdin);



		return 0;
}

