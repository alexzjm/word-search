#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void readWordPuzzle(const int Size, char puzzle[][Size]);
char* readWord(int* wordSize);
void printWordPuzzle(const int Size, char puzzle[][Size]);
void printWord(char* word, const int wordSize);

void search(const int Size,
            char puzzle[][Size],
            const int wordSize,
            char* word);

bool inBounds(int row, int col, const int Size);

int main(void) {
  const int Size = 20;
  char puzzle[Size][Size];
  readWordPuzzle(Size, puzzle);
  int wordSize = 0;
  char* word = readWord(&wordSize);
  printWordPuzzle(Size, puzzle);
  printf("The word you are looking for is\n");
  printWord(word, wordSize);
  printf("\n");
  printf("Do you want to search? (Y or N)\n");
  char isSearch;
  scanf(" %c", &isSearch);
  if (isSearch == 'Y' || isSearch == 'y') {
    search(Size, puzzle, wordSize, word);
  }
  free(word);
  return 0;
}

void search(const int Size,
            char puzzle[][Size],
            const int wordSize,
            char* word) {
                int rowCoordinate = -1, colCoordinate = -1, direction = 0;

                for (int r = 0; r < Size; r++){
                    for (int c = 0; c < Size; c++){

                        bool rowMax = (r + wordSize - 1 < Size); // does not hit max row
                        bool colMax = (c + wordSize - 1 < Size); // does not hit max col
                        bool rowMin = (r - wordSize + 1 > -1); // does not hit 0 row
                        bool colMin = (c - wordSize + 1 > -1); // does not hit 0 col
                        bool foundWord;

                        //southeast 1
                        if (rowMax && colMax && direction == 0){
                            foundWord = true;
                            for (int i = 0, j = 0; i < wordSize, j < wordSize; i++, j++){
                                if (puzzle[r + i][c + j] != word[i]){
                                    foundWord = false;
                                }
                            }
                            if (foundWord){
                                rowCoordinate = r;
                                colCoordinate = c;
                                direction = 1;
                            }
                        }

                        //south 2
                        if (rowMax && direction == 0){
                            foundWord = true;
                            for (int i = 0, j = 0; i < wordSize, j < wordSize; i++, j++){
                                if (puzzle[r + i][c] != word[i]){
                                    foundWord = false;
                                }
                            }
                            if (foundWord){
                                rowCoordinate = r;
                                colCoordinate = c;
                                direction = 2;
                            }
                        }
                        
                        //southwest 3
                        if (rowMax && colMin && direction == 0){
                            foundWord = true;
                            for (int i = 0, j = 0; i < wordSize, j < wordSize; i++, j++){
                                if (puzzle[r + i][c - j] != word[i]){
                                    foundWord = false;
                                }
                            }
                            if (foundWord){
                                rowCoordinate = r;
                                colCoordinate = c;
                                direction = 3;
                            }
                        }

                        //west 4
                        if (colMin && direction == 0){
                            foundWord = true;
                            for (int i = 0, j = 0; i < wordSize, j < wordSize; i++, j++){
                                if (puzzle[r][c - j] != word[i]){
                                    foundWord = false;
                                }
                            }
                            if (foundWord){
                                rowCoordinate = r;
                                colCoordinate = c;
                                direction = 4;
                            }
                        
                        }

                        //northwest 5
                        if (rowMin && colMin && direction == 0){
                            foundWord = true;
                            for (int i = 0, j = 0; i < wordSize, j < wordSize; i++, j++){
                                if (puzzle[r - i][c - j] != word[i]){
                                    foundWord = false;
                                }
                            }
                            if (foundWord){
                                rowCoordinate = r;
                                colCoordinate = c;
                                direction = 5;
                            }
                        }

                        //north 6
                        if (rowMin && direction == 0){
                            foundWord = true;
                            for (int i = 0, j = 0; i < wordSize, j < wordSize; i++, j++){
                                if (puzzle[r - i][c] != word[i]){
                                    foundWord = false;
                                }
                            }
                            if (foundWord){
                                rowCoordinate = r;
                                colCoordinate = c;
                                direction = 6;
                            }
                        }

                        //northeast 7
                        if (rowMin && colMax && direction == 0){
                            foundWord = true;
                            for (int i = 0, j = 0; i < wordSize, j < wordSize; i++, j++){
                                if (puzzle[r - i][c + j] != word[i]){
                                    foundWord = false;
                                }
                            }
                            if (foundWord){
                                rowCoordinate = r;
                                colCoordinate = c;
                                direction = 7;
                            }
                        }

                        //east 8
                        if (colMax && direction == 0){
                            foundWord = true;
                            for (int i = 0, j = 0; i < wordSize, j < wordSize; i++, j++){
                                if (puzzle[r][c + j] != word[i]){
                                    foundWord = false;
                                }
                            }
                            if (foundWord){
                                rowCoordinate = r;
                                colCoordinate = c;
                                direction = 8;
                            }
                        }
                    }
                }
                for(int i = 0; i < wordSize; i++){
                    printf("%c", word[i]);
                }

                if (direction == 0){
                    printf(" cannot be found!");
                }
                else if (direction == 1){
                    printf(" can be found at row , col = (%d, %d) in the south-east direction.", rowCoordinate + 1, colCoordinate + 1);
                }
                else if (direction == 2){
                    printf(" can be found at row , col = (%d, %d) in the south direction.", rowCoordinate + 1, colCoordinate + 1);
                }
                else if (direction == 3){
                    printf(" can be found at row , col = (%d, %d) in the south-west direction.", rowCoordinate + 1, colCoordinate + 1);
                }
                else if (direction == 4){
                    printf(" can be found at row , col = (%d, %d) in the west direction.", rowCoordinate + 1, colCoordinate + 1);
                }
                else if (direction == 5){
                    printf(" can be found at row , col = (%d, %d) in the north-west direction.", rowCoordinate + 1, colCoordinate + 1);
                }
                else if (direction == 6){
                    printf(" can be found at row , col = (%d, %d) in the north direction.", rowCoordinate + 1, colCoordinate + 1);
                }
                else if (direction == 7){
                    printf(" can be found at row , col = (%d, %d) in the north-east direction.", rowCoordinate + 1, colCoordinate + 1);
                }
                else if (direction == 8){
                    printf(" can be found at row , col = (%d, %d) in the east direction.", rowCoordinate + 1, colCoordinate + 1);
                }
            }

char* readWord(int* wordSize) {
  printf("How many characters are there in the word?");
  scanf("%d", wordSize);

  printf("What is the word that you are looking for?");
  char* wordArr = (char*)malloc(*wordSize * sizeof(char));
  for(int i = 0; i < *wordSize; i++){
    scanf(" %c", &wordArr[i]);
  }

  return wordArr;
}

void readWordPuzzle(const int Size, char puzzle[][Size]) {
  printf("Please enter the word puzzle:\n");
    for (int i = 0; i < Size; i++){
      for (int j = 0; j < Size; j++){
        scanf(" %c", &puzzle[i][j]);
      }
    }
}

bool inBounds(int row, int col, const int Size) {}

void printWordPuzzle(const int Size, char puzzle[][Size]) {
  printf("The word puzzle entered is\n");
  for (int i = 0; i < Size; i++){
    for (int j = 0; j < Size; j++){
      printf("%c ", puzzle[i][j]);
    }
    printf("\n");
  }
}

void printWord(char* word, const int wordSize) {
  for (int i = 0; i < wordSize; i++){
    printf("%c ", word[i]);
  }
}
