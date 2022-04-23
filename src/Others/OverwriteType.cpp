#include "../../curses.h"

int main()
{
  universalClear();
  string str;
  addstr("Press any Key To Continue...");
  getch();
  universalClear();
  blueStr("|---------------------------------------------|\n");
  blueStr("|Enter Your Name here...                      |\n");
  blueStr("|---------------------------------------------|\n");
  gotoxy(2, 2);
  cout << RED;
  getline(cin, str);
  cout << RESET;
  gotoxy(2, 2);
  int width = 48;
  int spc = width - str.length();
  string spaces;
  for (int i = 0; i < spc; i++)
  {
    spaces += " ";
  }
  greenStr(str + spaces);
  blueStr("|");

  addstr("\n\n\n");
  return 0;
}