#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
int
main (int argc, char *argv[])
{
  FILE *fp;
  char buffer[1024];
  char *delimiter = " .,:;?!()";
  int count_word = 0;
  char *s;
  int count = 0;
  char str[1024];
  bool catch1 = false, catch2 = false;
  //検索用変数
  int WORD = 0, FIG = 0;
  char w_name[256], f_name[256];
  if (argc < 2)
    {
      printf ("Parameter error\n");
      return 1;
    }
  /*質問入力 */

  for (int i2 = 0; i2 < 1;)
    {
      printf
	("検索する言葉を選択してください(1:オリンピック 2:東京 3:IOC )\n");
      scanf ("%d", &WORD);
      printf
	("なにを知りたいか数字を入力してください(1: 年 2: 季節 3:世紀)\n");
      scanf ("%d", &FIG);


      switch (WORD)
	{
	case 1:
	  strcpy (w_name, "OLYMPIC");
	  break;
	case 2:
	  strcpy (w_name, "TOKYO");
	  break;
	case 3:
	  strcpy (w_name, "IOC");
	  break;
	}
      if (FIG > 0 && WORD > 0)
	break;
    }
  for (int i3 = 1; i3 < argc; i3++)
    {
      if ((fp = fopen (argv[i3], "r")) == NULL)
	{
	  printf ("File open error\n");
	  return 1;
	}

      /*リセット */

      while (fgets (buffer, sizeof (buffer), fp) != NULL)
	{
	  catch1 = false;
	  catch2 = false;
	  bool Olympic = false, figure = false, season = false, century =
	    false;
	  count = 0;

	  strcpy (str, buffer);
	  int j = 0;
	  buffer[strlen (buffer) - 1] = '\0';
	  while (buffer[j] != '\0')
	    {
	      buffer[j] = toupper (buffer[j]);
	      j++;
	    }
	  if (s != NULL && (strstr (buffer, w_name) != NULL))
	    {
	      catch1 = true;
	      count++;
	    }
	  /*年月日時（数字）または季節を検索 */
	  char num[10] = "0123456789";
	  if (FIG == 1)
	    {			//年
	      if (strcspn (buffer, num) == 4)
		figure = true;
	    }
	  else if (FIG == 2)
	    {			//季節
	      if (strstr (buffer, "WINTER") != NULL
		  || strstr (buffer, "SUMMER") != NULL)
		season = true;
	    }
	  else if (FIG == 3)
	    {
	      if (strstr (buffer, "CENTURY") != NULL)
		{
		  century = true;
		  printf ("good\n");
		}
	    }
	  else
	    {
	      printf ("規定の数字が入力されてません\n");
	      exit (1);
	    }

	  switch (FIG)
	    {
	    case 1:
	      if (catch1 && figure)
		{
		  printf ("%s", str);
		  printf ("\n");
		}
	      break;
	    case 2:
	      if (catch1 && season)
		{
		  printf ("%s", str);
		  printf ("\n");
		}
	      break;
	    case 3:
	      if (catch1 && century)
		{
		  printf ("%s", str);
		  printf ("\n");
		}
	      break;
	    }
	}
    }
  fclose (fp);
  printf ("\n");
  return 0;
}
