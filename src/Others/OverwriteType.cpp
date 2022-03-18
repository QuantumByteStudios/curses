#include "../curses.h"

int main()
{
  universalClear();
  string str;
  blueStr("This is some Text. Which will be Overwritten!");
  gotoxy(0, 0);
  cout << RED;
  getline(cin, str);
  cout << RESET;
  greenStr(str);
  return 0;
}