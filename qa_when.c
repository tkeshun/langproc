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
  char w_name[256], w2_name[256], f_name[256];
  if (argc < 3)
    {
      printf ("Parameter error\n");
      return 1;
    }
  /*質問入力 */

  for (int i = 0; i < 1;)
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
	  strcpy (w2_name, "OLYMPICS");
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

  for (int i = 1; i < argc; i++)
    {
      if ((fp = fopen (argv[i], "r")) == NULL)
	{
	  printf ("File open error\n");
	  return 1;
	}
      /*リセット */
      catch1 = false;
      catch2 = false;
      bool Olympic = false, figure = false, season = false, century = false;
      count = 0;
      while (fgets (buffer, sizeof (buffer), fp) != NULL)
	{
	  strcpy (str, buffer);
	  int j = 0;
	  buffer[strlen (buffer) - 1] = '\0';
      /*大文字化*/
	  while (buffer[j] != '\0')
	    {
	      buffer[j] = toupper (buffer[j]);
	      j++;
	    }


	  s = strtok (buffer, delimiter);
	  if (s != NULL && (strstr (buffer, w_name) != NULL))
	    {
	      catch1 = true;
	      count++;
	    }
	  /*年月日時（数字）または季節を検索 */

	  char num1[4] = "0000";
	  if (FIG == 1)
	    {			//年
	      num1[0] = '0', num1[1] = '0', num1[2] = '0', num1[3] = '0';
	      for (int i = 48; i < 51; i++)
		{
		  num1[0] = i;
		  for (int j = 48; j < 58; j++)
		    {
		      num1[1] = j;
		      for (int k = 48; k < 58; k++)
			{
			  num1[2] = k;
			  for (int l = 48; l < 58; l++)
			    {
			      num1[3] = l;
			      if (strstr (buffer, num1) != NULL)
				figure = true;
			    }
			}
		    }
		}

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
		century = true;
	    }
	  else
	    {
	      printf ("規定の数字が入力されてません\n");
	      exit (1);
	    }
	  while ((s = strtok (NULL, delimiter)) != NULL)
	    {
	      if (strcmp (buffer, w_name) == 0)
		{
		  catch1 = true;
		}
	      /*年月日時（数字）または季節を検索 */
	      char num[4] = "0000";
	      if (FIG == 1)
		{		//年
		  num[0] = '0', num[1] = '0', num[2] = '0', num[3] = '0';
		  for (int i = 48; i < 51; i++)
		    {
		      num[0] = i;
		      for (int j = 48; j < 58; j++)
			{
			  num[1] = j;
			  for (int k = 48; k < 58; k++)
			    {
			      num[2] = k;
			      for (int l = 48; l < 58; l++)
				{
				  num[3] = l;
				  if (strstr (buffer, num) != NULL)
				    figure = true;
				}
			    }
			}
		    }

		}
	      else if (FIG == 2)
		{		//季節
		  if (strstr (buffer, "WINTER") != NULL
		      || strstr (buffer, "SUMMER") != NULL)
		    season = true;
		}
	      else if (FIG == 3)
		{
		  if (strstr (buffer, "CENTURY") != NULL)
		    century = true;
		}
	      else
		{
		  printf ("規定の数字が入力されてません\n");
		  exit (1);
		}

	    }
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

  fclose (fp);
  printf ("\n");
  return 0;
}
