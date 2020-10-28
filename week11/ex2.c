#include <stdio.h>
#include <unistd.h>

#define BUFFER_LENGTH 1024

int main() {
  char buff[BUFFER_LENGTH];
  setvbuf(stdout, buff, _IOLBF, BUFFER_LENGTH);

  printf("%c", 'H');
  sleep(1);
  printf("%c", 'e');
  sleep(1);
  printf("%c", 'l');
  sleep(1);
  printf("%c", 'l');
  sleep(1);
  printf("%c", 'o');
  sleep(1);
  return 0;
}