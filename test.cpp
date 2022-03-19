#include "curses.h"
using namespace std;

int main()
{
       // termSize
       termSize();
       universalClear();
       // ramesh();

       // cout << BG_RED << WHITE << " White Text With Red Background!! \n" << RESET << BG_NRM;
       // cout << endl;
       setTitle("Hello World Program", BG_RED, WHITE);

       // processBar(101, 1, "Done!...");

       // printf("width: %d, height: %d\n", currentTerm.width, currentTerm.height);
       // startNewInstance();
       // centerText("Hello, From Center");
       // char dash = '25B0';
       // printf(dash);
       // cout << processBar;
       // boldRedStr("  _______  _____  ____________\n");
       // boldBlueStr(" / ___/ / / / _ \\/ __/ __/ __/\n");
       // boldGreenStr("/ /__/ /_/ / , _/\\ \\/ _/_\\ \\  \n");
       // boldYellowStr("\\___/\\____/_/|_/___/___/___/  \n\n");

       // greenStr("Header File");
       // addstr(" With");
       // boldCyanStr(" C");
       // boldMagentaStr("O");
       // boldBlueStr("L");
       // boldYellowStr("O");
       // boldGreenStr("R");
       // boldRedStr("S\n");

       // addstr("\nThis is a Normal String\n");
       // addstr("This is a Normal BOLD String\n", 'B');
       // addstr("This is a Normal UNDERLINE String\n\n", 'U');
       // addstr("This is a Normal REVERSE String\n\n", 'R');

       // // COLORED STRINGS
       // blackStr("This is Black color string\n");
       // redStr("This is Red color string\n");
       // greenStr("This is Green color string\n");
       // yellowStr("This is Yellow color string\n");
       // blueStr("This is Blue color string\n");
       // magentaStr("This is Magenta color string\n");
       // cyanStr("This is Cyan color string\n");
       // whiteStr("This is White color string\n");
       // // BOLD COLORED STRINGS
       // gimmeSomeSpace(2);
       // boldBlackStr("This is Bold Black color string.\n");
       // boldRedStr("This is Bold Red color string.\n");
       // boldGreenStr("This is Bold Green color string.\n");
       // boldYellowStr("This is Bold Yellow color string.\n");
       // boldBlueStr("This is Bold Blue color string.\n");
       // boldMagentaStr("This is Magenta color string.\n");
       // boldCyanStr("This is Bold Cyan color string.\n");
       // boldWhiteStr("This is Bold White color string.\n");

       endNewInstance();
       getch();
       return 0;
}

// int ramesh()
// {
//        wait(1);
//        termSize();
//        printf("width: %d, height: %d\n", currentTerm.width, currentTerm.height);
//        wait(1);
//        universalClear();
//        ramesh();
// }