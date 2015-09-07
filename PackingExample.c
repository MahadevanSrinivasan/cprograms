/**
 * This program shows the effect of byte/word alignment
 */

#include <stdio.h>

typedef struct
{
  char *p;
  char c;
  long x;
}element;


typedef struct __attribute__((__packed__))
{
  char *p;
  char c;
  long x;
}elementP;

int main(int argc, char* argv[])
{
  element s;
  elementP s2;
  printf("p=%x, c=%x, x=%x, size=%d\n", &s.p, &s.c, &s.x, sizeof(s));
  printf("p=%x, c=%x, x=%x, size=%d\n", &s2.p, &s2.c, &s2.x, sizeof(s2));
  return 0;
}
