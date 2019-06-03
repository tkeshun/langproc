#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct Word_tag {
  char *name;
  int count;
  struct Word_tag *next;
} Word;
static char *my_strdup(char *src){
  char *dest;
  dest = malloc(sizeof(char) * (strlen(src)+1));
  strcpy(dest,src);
  return dest;
}
/*Word構造体を新しく作る*/
static Word *create_word(char *name){
  Word  *new_word;
  new_word = malloc(sizeof(Word));
  new_word->name = my_strdup(name);
  new_word->count = 1;
  new_word->next = NULL;

  return new_word;
}
Word *word_header = NULL;
void word_initialize(void){
  word_header = NULL;
}
void add_word(char *word)
{
    Word        *pos;
    Word        *prev;  /* posの後をひとつ遅れて付いていくポインタ */
    Word        *new_word;
    int         result;

    prev = NULL;
    for (pos = word_header; pos != NULL; pos = pos->next) {
        result = strcmp(pos->name, word);
        if (result >= 0)
            break;

        prev = pos;
    }
    if (word_header != NULL && result == 0) {
        /* 同一の単語が見付かった */
        pos->count++;
    } else {
        new_word =  create_word(word);
        if (prev == NULL) {
            /* 冒頭に挿入 */
            new_word->next = word_header;
            word_header = new_word;
        } else {
            new_word->next = pos;
            prev->next = new_word;
        }
    
    }
}
void dump_word(FILE *fp){
  Word *pos;
  for(pos = word_header;pos;pos = pos->next){
    fprintf(fp,"%s\t\t%d\n",pos->name,pos->count);
  }
}
void word_finalize(void)
{
    Word        *temp;

    /* 登録されている単語を全てfree()する */
    while (word_header != NULL) {
        temp = word_header;
        word_header = word_header->next;

        free(temp->name);
        free(temp);
    }
}


int main(int argc ,char* argv[]){
  FILE* fp;
  char buffer[1024];
  char* delimiter = " .,:;?!()";
  char *s;
  
  if(argc < 2){
    printf("Parameter error\n");
    return 1;
  }
  for(int i=1;i<argc;i++){
    if((fp = fopen(argv[i], "r")) == NULL){
      printf("File Open Error\n");
      return 1;
    }
    /*初期化*/
    word_initialize();

    while(fgets(buffer,sizeof(buffer),fp) != NULL){
      buffer[strlen(buffer) - 1] = '\0';
      s = strtok(buffer,delimiter);
      if(s != NULL){
        add_word(s);
      }
      while((s = strtok(NULL,delimiter)) != NULL){
        add_word(s);  
      }
    }
    fclose(fp);
  }
  dump_word(stdout);
  fclose(fp);
  word_finalize();
  return 0;
}   
    
