#include<stdio.h>
#include<stdlib.h>
int main ()
{
  int i, j, n, k, l, m, p, q, x = 1, y = 0, t;
  printf ("enter no of vertices");
  scanf ("%d", &n);
  int e[n][n];
  int *c = (int *) calloc (n, sizeof (int));
  printf ("enter no of edges to be added");
  scanf ("%d", &t);
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
        e[i][j] = 0;
    }


  for (i = 0; i < t; i++)
    {
      printf ("enter edge");
      scanf ("%d%d", &l, &m);
      e[l - 1][m - 1] = 1;
      e[m - 1][l - 1] = 1;
    }
  c[0] = 1;
  for (i = 1; i < n; i++)
    {
      int *d = (int *) calloc (i, sizeof (int));
      for (j = 0; j < i; j++)
        {
          if (e[i][j] == 1)
            {
              d[j] = c[j];
            }
        }
      for (p = 1; p < n; p++)
        {
          x = -1;
          for (q = 0; q < i; q++)
            {
              if (p == d[q])
                {
                  x = 1;
                  break;
                }
            }
          if (x == -1)
            break;
        }
      c[i] = p;
    }
  for (i = 0; i < n; i++)
    {
      printf ("%d ", c[i]);
      if (c[i] > y)
        {
          y = c[i];
        }
    }
  printf ("\nminimom colors required=%d", y);
  return 0;
}
