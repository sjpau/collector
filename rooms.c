#include "rooms.h"
#include <ncurses.h>

/*TODO: allow user to choose specific char symbol*/
void print_hor(int width, int st_x, int st_y, int edge, bool right) {
  if(right) {
    for (int i = 0; i < width + edge; ++i) {
      mvaddch(st_y, st_x++, '#');
      refresh();
      napms(40);
    }
  } else {
    for (int i = 0; i < width + edge; ++i) {
      mvaddch(st_y, st_x--, '#');
      refresh();
      napms(40);
    }
  } 
}

void print_ver(int height, int st_x, int st_y, int edge, bool up) {
  if(up) {
    for (int i = 0; i < height + edge; ++i) {
      mvaddch(st_y--, st_x, '#');
      refresh();
      napms(40);
    }
  } else {
      for (int i = 0; i < height + edge; ++i) {
      mvaddch(st_y++, st_x, '#');
      refresh();
      napms(40);
   }
  }
}

void print_map(int width, int height) {
  int x;
  int y;
  
  /*allocate coordinates of the center*/
  getmaxyx(stdscr, y, x);
  int center_x = x/2;
  int center_y = y/2;

  /* should be removed after testing*/
  //mvaddch(center_y, center_x, '#');

  /*define the width and the height of squares*/
  int sq_width = width/2;
  int sq_height = height/2;

  /*selecting the starting point of drawing
   * in this case this point is bottom-right node of the map */
  int bot_right_x = center_x + sq_width + 1;
  int bot_right_y = center_y + sq_height + 1;

  /*calculating the top-right node of the map*/
  int top_right_x = bot_right_x;
  int top_right_y = bot_right_y - height - 2;

  /*calculating the top-left node of the map*/
  int top_left_x = bot_right_x - width - 2;
  int top_left_y = top_right_y;

  /*calculation the bot-left node of the map*/
  int bot_left_x = top_left_x;
  int bot_left_y = bot_right_y; 
  /*Drawing edge walls*/
  print_ver(height, bot_right_x, bot_right_y, 3, true);
  print_hor(width, top_right_x, top_right_y, 3, false);
  print_ver(height, top_left_x, top_left_y, 3, false);
  print_hor(width, bot_left_x, bot_left_y, 3, true);
}
