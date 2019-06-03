#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int func_str(char *buffer,char *query,int n){  
  if(strstr(buffer,query) != NULL) n++;
  return n;
}
void strUpper(char *str){
   for(int i=0;str[i] != '\0';i++){
    str[i] = toupper(str[i]);
   }
}

int main(int argc, char **argv){
  FILE *fp;
  char buffer[1024];
  char query[256];
  int n=0;
  if(argc != 3){
    printf("p_Error\n");
    exit(1);
  }
  strcpy(query,argv[1]);
  strUpper(query);
  if((fp = fopen(argv[2],"r")) == NULL){
    printf("file open error\n");
    exit(1);
  }
  
  while(fgets(buffer,1024,fp) != NULL){
    buffer[strlen(buffer)-1] = '\0';
    strUpper(buffer); 
    n = func_str(buffer,query,n);
  } 
  if(n > 0){ 
    printf("The file cintains \"%s\"\n",query);
  }else{
    printf("Not Found \"%s\"\n",query);
  }
  fclose(fp);
 return 0; 
}
  
