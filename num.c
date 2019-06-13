#include<stdio.h>
int main(){
  char num[4] = "0000";
  for(int i=48;i<51;i++){
     num[0] = i ;
   for(int j=48;j<58;j++){
      num[1] = j;
      for(int k=48;k<58;k++){
        num[2] = k;
        for(int l=48;l<58;l++){
          num[3] = l;
        printf("%c%c%c%c\n",num[0],num[1],num[2],num[3]);
  }}}}
  return 0;
}
