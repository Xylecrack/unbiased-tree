#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getGcd(int a, int b) {
  int temp;
  while (b != 0) {
    temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}
int getModInverse(int a) {
  for (int i = 1; i < 26; i++) {
    if ((a * i) % 26 == 1) {
      return i;
    }
  }
  return -1;
}
void encrypt(char *text, int a, int b) {
  for (int i = 0; text[i] != '\0'; i++) {
    if (text[i] >= 'a' && text[i] <= 'z') {
      text[i] = 'a' + (a * (text[i] - 'a') + b) % 26;
    } else if (text[i] >= 'A' && text[i] <= 'Z') {
      text[i] = 'A' + (a * (text[i] - 'A') + b) % 26;
    }
  }
  printf("cipher text => %s\n", text);
}

void decrypt(char *text, int a, int b) {
  int a_inv = getModInverse(a);
  for (int i = 0; text[i] != '\0'; i++) {
    if (text[i] >= 'a' && text[i] <= 'z') {
      text[i] = 'a' + (a_inv * (text[i] - 'a' - b + 26)) % 26;
    } else if (text[i] >= 'A' && text[i] <= 'Z') {
      text[i] = 'A' + (a_inv * (text[i] - 'A' - b + 26)) % 26;
    }
  }
  printf("decrypted text => %s\n", text);
}

int main(int argc, char *argv[]) {
  if (argc != 5) {
    printf("insufficient args\n");
    return 1;
  }
  char *mode = argv[1];
  char text[100];
  strcpy(text, argv[2]);

  int a = atoi(argv[3]);
  int b = atoi(argv[4]);
  if (getGcd(a, 26) != 1) {
    printf("invalid key: a must be coprime with 26\n");
    return 1;
  }
  if (strcmp(mode, "encrypt") == 0)
    encrypt(text, a, b);
  else if (strcmp(mode, "decrypt") == 0)
    decrypt(text, a, b);
  else {
    printf("invalid operation\n");
    return 1;
  }
  return 0;
}