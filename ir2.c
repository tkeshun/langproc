#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
int main(int argc,char *argv[]){
  FILE *fp;
  char buffer[1024];
  char *delimiter = " .,:;?!()";
  int count_word = 0;
  char *s;
  int count=0; 
  if(argc < 3){
    printf("Parameter error\n");
    return 1;
  }
  for(int i=3;i<argc;i++){
    if((fp = fopen(argv[i], "r")) == NULL){
      printf("File open error\n");
      return 1;
    }
    bool catch1 = false, catch2 = false;
    count = 0;
    while(fgets(buffer,sizeof(buffer),fp) != NULL){
      
      buffer[strlen(buffer)-1] = '\0';
      s = strtok(buffer,delimiter);
       if(s != NULL && (strcmp(s,argv[1]) == 0)){
         catch1 = true;
         count++;
       }
       if(s != NULL && (strcmp(s,argv[2]) == 0)){
         catch2 = true;
         count++; 
      }
      while((s = strtok(NULL,delimiter)) != NULL){
        if(strcmp(s,argv[1]) == 0){
          catch1 = true;
          count++;
        }
        if(strcmp(s,argv[2]) == 0){
          catch2 = true;
          count++;
        }  
      }
    }

    if(catch1 && catch2) printf("%s %d\n",argv[i],count);
    }
  fclose(fp);
  printf("\n");
  return 0;
} 
