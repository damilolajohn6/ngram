#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//-------------------------------make new Array copy----------------------------------------
void dispArr(char* myAdd, int size)
{
  size = strlen(myAdd);
  for (int i = 0; i < size; i++)
  {
    int count = 1;
    if (myAdd[i])
    {
      for (int j = i + 1; j < size; j++)
      {
        if (myAdd[i] == myAdd[j])
        {
          count++;
          myAdd[j] = '\0';
        }
      }
      printf("%c:%d\n", myAdd[i], count);
    }

  }
}
//-------------------------------sort Array----------------------------------------
void sortArr(char* myStr)
{
  char a;
  for (long unsigned int i = 0; i < strlen(myStr); i++)
  {
    for (long unsigned int j = i + 1; j < strlen(myStr); j++)
    {
      if (myStr[i] > myStr[j])
      {
        a = myStr[i];
        myStr[i] = myStr[j];
        myStr[j] = a;
      }
    }
  }
}
//-------------------------------fill Array----------------------------------------
void fillArray(char* haystack, char* needle, int leng)
{
  for (int b = 0; haystack[b] != '\0'; b++)
  {
    needle[b + leng] = haystack[b];
  }
}
//-------------------------------Program entry point--------------------------------
int main(int argc, char* argv[])
{
  int sizeOfArr = 0;
  int len = 0;
  for (int i = 1; i < argc; i++)
  {
   sizeOfArr += strlen(argv[i]);
  }
  char* myArr = malloc(sizeof(char) * (sizeOfArr + 1));
  myArr[sizeOfArr + 1] = '\0';
  for (int a = 1; a < argc; a++)
  {
    fillArray(argv[a], myArr, len);
    int status = strlen(argv[a]);
    len += status;
  }
  sortArr(myArr);
  dispArr(myArr, sizeOfArr);
}
