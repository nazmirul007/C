#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/stat.h>

int main(){


struct stat st;
stat("text.txt", &st);	
int size = (st.st_size-1);

unsigned char buffer[size];	

FILE *write_ptr;			
write_ptr = fopen("test.bin","wb"); 	

FILE *file;
file = fopen("textt.txt","r");

if(write_ptr == NULL)			
{
    printf("Error!\n");
    exit(1);
}

if (file == NULL)
{
    printf("Error!\n");
    exit(1);
}

fread(buffer,sizeof(buffer),1,file); 	

for(int i=0;i<size;i++)			
	printf("%c",buffer[i]);		


fwrite(buffer,sizeof(buffer), 1, write_ptr );	

fclose(write_ptr);
fclose(file);


}


