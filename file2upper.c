#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include<ctype.h>
const static int size = 1024;
int main(int argc, char* argv[]){
  FILE* fp1;
  FILE* fp2;
  char buffer[1024];
  int chr; 
 /* if(argc != 2){
    printf("Error\n");
    return 1;
  }*/
  
    if((fp1 = fopen("./corpusMG/mg001.txt", "r")) == NULL){
      printf("File Open Error.\n");
      return 1;
    }
    if((fp2 = fopen("./tmp.txt" , "w")) == NULL){
      printf("File Open Error.\n");
      return 1;
    }
    chr = fgetc(fp1);
    while((chr = fgetc(fp1)) != EOF){
      fputc((char)toupper(chr),fp2);    
    }
    
    fclose(fp1);
    fclose(fp2);
    return 0;
}
