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
  char str[1024];
  bool catch1 = false,catch2 = false;
  //検索用変数
  int WORD = 0,FIG = 0;
  char w_name[256], w2_name[256],f_name[256];
  if(argc < 3){
    printf("Parameter error\n");
    return 1;
  }
  /*質問入力*/
 
  for(int i=0;i<1;){
    printf("検索する言葉を選択してください(1:オリンピック 2:東京 3:IOC 4:なし)\n");
    scanf("%d",&WORD);
    printf("なにを知りたいか数字を入力してください(1: 年 2: 季節 3:世紀)\n");
    scanf("%d", &FIG);

    switch(WORD){
    case 1:
      strcpy(w_name, "OLYMPIC");
      strcpy(w2_name,"OLYMPICS");
    case 2: 
      strcpy( w_name, "TOKYO");        
    case 3: 
      strcpy(w_name,"IOC");
    }
    if(FIG > 0 && WORD > 0) break;
  }
   
  for(int i=1;i<argc;i++){
    if((fp = fopen(argv[i], "r")) == NULL){
      printf("File open error\n");
      return 1;
    }
    /*リセット*/
    catch1 = false;
    catch2 = false;
    bool  Olympic = false, figure = false, season = false,century = false;
    count = 0;
    while(fgets(buffer,sizeof(buffer),fp) != NULL){
      strcpy(str,buffer);
      int j = 0;
      while(buffer[j] !=  '\0'){
	    buffer[j] = toupper(buffer[j]);
	    j++;
      }

      buffer[strlen(buffer)-1] = '\0';
      s = strtok(buffer,delimiter);
      if(s != NULL && (strcmp(s,w_name) == 0)){
	    catch1 = true;
	    count++;
      }
      /*年月日時（数字）または季節を検索*/
      if(FIG == 1){//年
	for(int i=48;i<10;i++){
	  if(strstr(buffer,i) != NULL) figure = true;
	}
      }else if(FIG == 2){//季節
	if(strstr(buffer,"WINTER") != NULL || strstr(buffer ,"SUMMER") != NULL) season = true;
      }else if(FIG == 3){
	if(strstr(buffer,"CENTURY") != NULL)century=true;
      }else{
	printf("規定の数字が入力されてません\n");
	exit(1);
      }
      while((s = strtok(NULL,delimiter)) != NULL){
	if(strcmp(s,w_name) == 0){
	  catch1 = true;
	}
	/*年月日時（数字）または季節を検索*/
	if(FIG == 1){//年
	  for(int i=48;i<10;i++){
	    if(strstr(buffer,i) != NULL) figure = true;
	  }
	}else if(FIG == 2){//季節
	  if(strstr(buffer,"WINTER") != NULL || strstr(buffer ,"SUMMER") != NULL) season = true;
	}else if(FIG == 3){
	  if(strstr(buffer,"CENTURY") != NULL)century=true;
	}else{
	  printf("規定の数字が入力されてません\n");
	  exit(1);
	}

      }
    }    
    switch(FIG){
    case 1:
      if(catch1 && figure){ printf("%s",str);printf("\n");}
    case 2:
      if(catch1 && season){ printf("%s",str);printf("\n");}
    case 3:
      if(catch1 && century){ printf("%s",str);printf("\n");}
      
    }
    if(!figure) printf("figure error\n");
  }

    fclose(fp);
    printf("\n");
    return 0;
} 
