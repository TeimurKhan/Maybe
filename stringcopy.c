#include<stdio.h> 
#include<stdlib.h>


void string_copy(char dest[], char source[]) {
  int iter = 0;
   
  while (source[iter] != '\0') {
    dest[iter] = source[iter];
    iter++;
  }
  dest[iter] = '\0';
}

//test driver function copying str1 to str2
int main(){
  char str1[200]="C Test for Whyd to copy strings\n", str2[200];
  string_copy(str2,str1);
  printf("%s",str2);

  return 0;
}