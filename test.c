#include<stdio.h>
#include<string.h>

int main(){
  char  s1[256],s2[256]; 
	int   d;
	char  c;

	printf("英単語２個 > ");
	scanf("%s %s", s1, s2);
	d = strcmp(s1, s2);
	if (d < 0) {
		c = '<';
	} else if (d == 0) {
		c = '=';
	} else {
		c = '>';
	}
	printf("%s %c %s\n", s1, c, s2);

	return (0);
}
