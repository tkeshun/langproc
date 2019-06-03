#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(int argc ,char* argv[]){
  FILE* fp;
  char buffer[1024];
  char* delimiter = " .,:;?!()";
  int count_word = 0;
  char *s;

  if(argc < 2){
    printf("Parameter error\n");
    return 1;
  }
for(int i=0;i<argc;i++){
  if((fp = fopen(argv[i], "r")) == NULL){
    printf("File Open Error\n");
    return 1;
  }
  
  while(fgets(buffer,sizeof(buffer),fp) != NULL){
    buffer[strlen(buffer) - 1] = '\0';
    s = strtok(buffer,delimiter);
    if(s != NULL){
      count_word++;
    }
    while((s = strtok(NULL,delimiter)) != NULL){
      count_word++;  
    }
  }
}
  printf("Number of words: %d\n",count_word);
  fclose(fp);
  return 0;
}   
    
