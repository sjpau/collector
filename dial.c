#include <stdio.h>
#include <ncurses.h>
#include <time.h>


#define MAXLENGTH 100

#define BORDER '-'


static char sen[] = "This is a fucking sentence BLYAT";
static int sen_length = 0;

int calc_sen_lentgh(char local_sen_len[]){
  for (int i = 0; i < MAXLENGTH; i++){
    sen_length += 1;
      if (local_sen_len[i+1] == '\0'){
        break;
      }
    }
  return (sen_length);
}

void print_sent(char local_sen_print[]){
  calc_sen_lentgh(sen); /*here sentence is put for further operation*/
  move(1, 0);
    for (int i = 0; i < sen_length; i++){
      addch(local_sen_print[i]);
      nanosleep((const struct timespec[]){{0, 50000000L}}, NULL);
      refresh();
    }
}

void print_border(){
  mvhline(0, 0, BORDER, COLS);
  refresh();
}

