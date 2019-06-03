#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

int main(int argc, char* argv[]){
  FILE* fp1,fp2;
  char buffer[1024];
  char filepass[1024];  
  char command[] = "ls";
  int res;
  if(argc < 2){
    printf("Error");
    return 1;
  }
  snprintf(command,argv);
  
  res = system(command);
  
  if((fp1 = fopen(./passlist.txt,"r")) == NULL){
    printf("Pass File open Error.\n")
    return 1;
  }
  while(fgets(filepass,1024,fp1) != NULL){
    
    if((fp2 = fopen(filepass , "r")) == NULL){
      printf("File Open Error.\n");
      return 1;
    }
  
    while(fgets(buffer,1024,fp2) != NULL){
      printf("%s",buffer);
    }
    fclose(fp2);
  }
  fclose(fp1);

  return 0;
}
