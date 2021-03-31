#include <stdio.h>
#include <string.h>

void *func(){
  int pass = 0;
  char buff[15];
  gets(buff);
  if(strcmp(buff, "thegeekstuff")) {
    printf ("\n Wrong Password. \n");
  }
  else {
    printf ("\n Correct Password.\n");
    pass = 1;
  }

  if(pass) {  // do somelhing priviledged stuff
    printf ("\n Root privileges given to the user.\n");
  }
  return buff;
}

int main(void) {
  printf("\n Enter the password : \n");
  func();
  return 0;
}
