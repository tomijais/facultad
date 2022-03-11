#include <stdio.h>

int main() {
  int num = 1, acum = 0, cont = 0;

  while (cont < 4) {
    for (int i = 1; i < num; i++) {
      if (num % i == 0) {
        acum += i;
      }
    }

    if (num == acum) {
      cont++;
      printf("%d\n", num);
    }

    acum = 0;
    num++;
  }
}