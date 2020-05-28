#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_WORD_LENGTH 10

/* print a histogram of the lenghts of words */
int main()
{
  int c, state, max_words;
  int current_word_length;
  int matrix_word_length[MAX_WORD_LENGTH]; // max number of words set to 100

  current_word_length = 0;
  state = OUT;

  for (int i = 0; i < MAX_WORD_LENGTH; ++i)
    matrix_word_length[i] = 0;

  while ((c = getchar()) != EOF){
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
      matrix_word_length[current_word_length]++;
      current_word_length = 0;
    } else if (state == OUT) {
      state = IN;
      ++current_word_length;
    } else if (state == IN) {
      ++current_word_length;
    }
  }

  for (int i = 0; i < MAX_WORD_LENGTH; ++i) {
    printf("%d: ", i);  // 0 stands is for "new word" characters
    for (int j = 0; j < matrix_word_length[i]; ++j) {
      printf("|");
    }
    printf("\n");
  }

  return 0;
}
