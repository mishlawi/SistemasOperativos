#include <sys/types.h>
#include <unistd.h> /*chamadas ao sistema: defs e decls essenciais*/
#include <fcntl.h>  /*O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <stdlib.h>
#include <stdio.h>
#define SIZE 1024

//int     open(const char*path, int oflag [, mode]);
//ssize_t read(int fildes, void*buf, size_t nbyte);
//ssize_t write(int fildes, const void*buf, size_t nbyte);
//off_t   lseek(int fd, off_t offset, int whence);
//int     close(int fildes);

/*

implemente em C um programa mycat com funcionalidade similares ao comando cat,  que lê do seu stdin 
e escreve para o seu stdout.


 file descriptor input = 0;
 file descriptor output = 1;

*/

int main (int argc , char *argv[]){
char buffer[SIZE];

	int fd1 = 0;
	int fd2 = 1;

	
	int l;


	//similar a fazer <<	while((l=read(0,buffer,SIZE))>0	  >>
	
	while((l=read(fd1,buffer,SIZE))>0)
	{
	write(fd2,buffer,l);
	}



}	
