#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char alp[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','y'};
int main(int argc, char* argv[]){
  FILE* fp;
  char buffer[1024];
  int c;
  int count[256] = {0};
  int index; 
  if(argc != 2){
    printf("Error");
    return 1;
  }
  if((fp = fopen(argv[1] , "r")) == NULL){
    printf("File Open Error.\n");
    return 1;
  }
  c = fgetc(fp);
  while(c != EOF){
    if((64 < c && c < 91) || (96 < c && c < 123)) count[c]++;
    c = fgetc(fp);
  }

 /* while(fgets(buffer,sizeof(buffer),fp) != NULL){
    count+= (strlen(buffer) - 1);
  }
  */
  fclose(fp);
  for(int i=0;i<256;i++){
    if((64 < i && i < 91) || (96 < i && i < 123)){
      printf("%c %d\n",(char)i,count[i]);
    }
  }
  return 0;
}
               
