#include <stdio.h>

int main ()
{
  char str [80];
  float f; int d;
  FILE * pFile;

  pFile = fopen ("grammar.txt","r");
 while(!feof(pFile)) {fscanf (pFile, "%d", &d); printf("%d",d);}
  
  fclose (pFile);
  
  return 0;
}
