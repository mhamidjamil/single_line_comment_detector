#include <stdio.h>

int main() {
  char c;
  int totalCommentsDetected = 0;
  int commentDetected = 0;
  FILE *file = fopen("test.txt", "r");
  FILE *fw = fopen("WrittenFile.txt", "w");
  if (file == NULL) {
    printf("File not found");
  } else {
    while ((c = fgetc(file)) != EOF) {
      if (c == '/') {
        if (commentDetected == 0) {
          commentDetected = 1;
        } else if (commentDetected == 1) {
          commentDetected = 2;
        }
      } else if (c == '\n') {
        if (commentDetected == 2) {
          commentDetected = 0;
          totalCommentsDetected++;
        } else {
          printf("%c", c);
          fputc(c, fw);
        }
      }
    }
    else if (!(commentDetected == 2)) {
      printf("%c", c);
      fputc(c, fw);
    }
  }
  fclose(file);
  fclose(fw);
  printf("Total comments detected : %d", totalCommentsDetected);
  return 0;
}
