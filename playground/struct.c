#include <stdio.h>

struct a_struct {
  char char_one; // 1 byte
  char char_two; // 1 byte
  int int_one;   // 4 byte
};

int main() {
  printf("%zu:size of char\n", sizeof(char));
  printf("%zu:size of int\n", sizeof(int));

  // address of int has to be aligned to 4 bytes, so compiler pads two bytes
  // after allocation of two char. size of struct is 8 bytes : 1 + 1 + 2
  // (padding) + 4
  printf("%zu:size of sruct \n", sizeof(struct a_struct));

  struct a_struct s;

  // address of char_one and two are consecutive
  // address of int_one has offset of +2 from char_two
  printf("%p:s.char_one\n"
         "%p:s.char_two\n"
         "%p:s.int_one\n",
         &s.char_one, &s.char_two, &s.int_one);

  return 0;
}
