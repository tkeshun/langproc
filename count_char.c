#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[]){
  FILE* fp;
  char buffer[1024];
  int c;
  int count = 0;
  if(argc != 2){
    printf("Error");
    return 1;
  }
  if((fp = fopen(argv[1] , "r")) == NULL){
    printf("File Open Error.\n");
    return 1;
  }
 /* c = fgetc(fp);
  while(c != EOF){
    count++;
    c = fgetc(fp);
  }
 */
  while(fgets(buffer,sizeof(buffer),fp) != NULL){
    count+= (strlen(buffer) - 1);
  }
  
  fclose(fp);
  printf("Number of character: %d\n",count);
  return 0;
}
               
