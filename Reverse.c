#include<stdio.h>
#include<stdlib.h>
#include <sys/stat.h>
int main(){

struct stat st;
stat("text.txt", &st);
int size = (st.st_size-1);

unsigned char buffer[size];
FILE *ptr;
ptr = fopen("test.bin","rb");  

FILE *file;
file = fopen("reverse.txt","w");
if(file == NULL)
{
    printf("Error!\n");
    exit(1);
}

if (ptr == NULL)
{
    printf("Error!\n");
    exit(1);
}

fread(buffer,sizeof(buffer),1,ptr); 


for(int i = size-1; i>=0; i--){
    fprintf(file,"%c",buffer[i]);
    
}

fclose(ptr);

}

