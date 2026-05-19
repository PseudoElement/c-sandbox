#include <stdio.h>
#include <stdlib.h>

int main() {
  int counter = 111;
  float floatCounter = 1.22;
  char symbol = "Z272323"[0];
  int myNum = 25;
  char email[] = "new-user@gmail.com";

  double doubleNum = 19.99;

  myNum++;

  floatCounter += 1.66;
  counter++;

  int x = 5, y = 6, z = 50;
  printf("comma separated %d!\n", x + y + z);

  printf("symbol %c!\n", symbol);
  printf("float %.1f!\n", floatCounter);
  printf("myNum log %d!\n", myNum % 4);
  printf("email log %s!\n", email);

  return 0;
}
