#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
const static int size = 1024;
int main(int argc, char* argv[]){
  FILE* fp;
  char buffer[1024];
  if(argc != 2){
    printf("Error");
    return 1;
  }
  if((fp = fopen(argv[1] , "r")) == NULL){
    printf("File Open Error.\n");
    return 1;
  }
  while(fgets(buffer,1024,fp) != NULL){
    printf("%s",buffer);
  }
  fclose(fp);
  return 0;
}
