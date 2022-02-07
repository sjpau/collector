#include <stdio.h>
#include <ncurses.h>


#define MAXLENGTH 100

#define BORDER '-'


static char sen[] = "This is a fucking sentence BLYAT";
static int senLength = 0;

int CalcSentenceLength(char senToCalcLength[]){
  for (int i = 0; i < MAXLENGTH; i++){
    senLength += 1;
      if (senToCalcLength[i+1] == '\0'){
        break;
      }
    }
  return (senLength);
}

void PrintSentence(char senToPrint[]){
  CalcSentenceLength(sen); /*here sentence is put for further operation*/
  move(1, 0);
    for (int i = 0; i < senLength; i++){
      addch(senToPrint[i]);
      napms(40); 
		 	refresh();
    }
}

void PrintBorder(){
  mvhline(0, 0, BORDER, COLS);
  refresh();
}

