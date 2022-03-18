/*
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is NOT part of the mingw-w64 runtime package.
 * No warranty is given.
 * Using this file for any commercial use is not prohibited, but we are
expecting credits.
Copyright Disclaimer under Section 107 of the copyright act 1976, allowance is
made for fair use for allowance is made for fair use for purposes such as
criticism, comment, news reporting, scholarship, and research. Fair use is a use
permitted by copyright statute that might otherwise be infringing. Non-profit,
educational or personal use tips the balance in favour of fair use. Fair use or
fair dealing is an exception to the Act of an infringement. The Act does not
define the term fair use. The meaning of the fair use is always interpreted by
the courts depending on the facts of each case. When any person uses any
copyrighted materials for fair dealings, he does not require any prior
authorisation from the owner and such act will not be considered as an
infringement.
*/

#include <iostream>
#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#include "src/headers/termiWin.h"

#elif __linux__
#include <sys/ioctl.h>
#include <termios.h>
#elif __unix__
#include <sys/ioctl.h>
#include <termios.h>
#else
printf("Unidentified OS, Cannot Perform a \"CLEAR\" :( \n");
#endif

typedef struct
{
  int width;
  int height;
} terminalSize;

terminalSize currentTerm;

#define gotoxy(x, y) printf("\033[%d;%dH", (y), (x))

// the following are UBUNTU/LINUX, and MacOS ONLY terminal color codes.
#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */
#define BOLD "\033[1m"                /* Bold */
#define UNDERLINE "\u001b[4m"         /* Underline */
#define REVERSE "\u001b[7m"           /* Reverse */
// Background
#define TC_BG_NRM "\x1B[40m"
#define TC_BG_RED " \x1B[41m"
#define TC_BG_GRN "\x1B[42m"
#define TC_BG_YEL "\x1B[43m"
#define TC_BG_BLU "\x1B[44m"
#define TC_BG_MAG "\x1B[45m"
#define TC_BG_CYN "\x1B[46m"
#define TC_BG_WHT "\x1B[47m"

void universalClear()
{
#ifdef _WIN32
  system("cls");
#elif __linux__
  system("clear");
#elif __unix__
  system("clear");
#else
  printf("Unidentified OS, Cannot Perform a \"CLEAR\" :( \n");
#endif
}

//  stringS
void addstr(string str)
{
  // Add a  string to the screen.
  cout << str;
}

void addstr(string str, char format)
{
  // Add a  string to the screen.
  if (format == 'b' || format == 'B')
  {
    cout << BOLD << str << RESET;
  }
  else if (format == 'u' || format == 'U')
  {
    cout << UNDERLINE << str << RESET;
  }
  else if (format == 'r' || format == 'R')
  {
    cout << REVERSE << str << RESET;
  }
  else
  {
    cout << str;
  }
}

void addstr(int lines, int characters, string str)
{
  // Add a Lines to the screen.
  for (int i = 0; i < lines; i++)
  {
    cout << endl;
  }
  // Add a Character Spaces to the screen.
  for (int i = 0; i < lines; i++)
  {
    cout << " ";
  }
  // Add a  string to the screen.
  cout << str;
}

void addstr(int lines, int characters, string str, char color)
{
  // Add a Lines to the screen.
  for (int i = 0; i < lines; i++)
  {
    cout << endl;
  }
  // Add a Character Spaces to the screen.
  for (int i = 0; i < lines; i++)
  {
    cout << " ";
  }
  // Add a  string to the screen.
  if (color == 'b' || color == 'B')
  {
    cout << BOLD << str << RESET;
  }
  else
  {
    cout << str;
  }
}

// SPACES
void gimmeSomeSpace(int lines, int characters)
{
  // Add a Lines to the screen.
  for (int i = 0; i < lines; i++)
  {
    cout << endl;
  }
  // Add a Character Spaces to the screen.
  for (int i = 0; i < characters; i++)
  {
    cout << " ";
  }
}

void gimmeSomeSpace(int lines)
{
  // Add a Lines to the screen.
  for (int i = 0; i < lines; i++)
  {
    cout << endl;
  }
}

void blackStr(string str) { cout << BLACK << str << RESET; }
void redStr(string str) { cout << RED << str << RESET; }
void greenStr(string str) { cout << GREEN << str << RESET; }
void yellowStr(string str) { cout << YELLOW << str << RESET; }
void blueStr(string str) { cout << BLUE << str << RESET; }
void magentaStr(string str) { cout << MAGENTA << str << RESET; }
void cyanStr(string str) { cout << CYAN << str << RESET; }
void whiteStr(string str) { cout << WHITE << str << RESET; }

void boldBlackStr(string str) { cout << BOLDBLACK << str << RESET; }
void boldRedStr(string str) { cout << BOLDRED << str << RESET; }
void boldGreenStr(string str) { cout << BOLDGREEN << str << RESET; }
void boldYellowStr(string str) { cout << BOLDYELLOW << str << RESET; }
void boldBlueStr(string str) { cout << BOLDBLUE << str << RESET; }
void boldMagentaStr(string str) { cout << BOLDMAGENTA << str << RESET; }
void boldCyanStr(string str) { cout << BOLDCYAN << str << RESET; }
void boldWhiteStr(string str) { cout << BOLDWHITE << str << RESET; }

#define clearScreen() puts("\x1B[2J")

#define moveCursor(X, Y) printf("\033[%d;%dH", Y, X)

// void tc_get_cols_rows(int *cols, int *rows);

#define startNewInstance() puts("\033[?1049h\033[H")
#define endNewInstance() puts("\033[?1049l")

int termSize()
{
  /*
    USE: currentTerm.width, currentTerm.height
    to access width and height respectively.
  */
#ifdef _WIN32
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  int columns, rows;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
  rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
  currentTerm.width = columns;
  currentTerm.height = rows;
  // printf("width: %d, height: %d", currentTerm.width, currentTerm.height);
#elif __linux__ || __unix__
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  int columns = w.ws_row;
  int rows = w.ws_col;
  currentTerm.width = columns;
  currentTerm.height = rows;
  // printf("width: %d, height: %d", currentTerm.width, currentTerm.height);
#endif
}

void wait(int number_of_seconds)
{
  // Converting time into milli_seconds
  int milli_seconds = 100 * number_of_seconds;

  // Storing start time
  clock_t start_time = clock();

  // looping till required time is not achieved
  while (clock() < start_time + milli_seconds)
    ;
}

void centerText(string text)
{
  int h = currentTerm.height / 2;
  int w = currentTerm.width / 2;
  moveCursor(w, h);
  addstr(text);
}

void processBar(int value, int delay, string message)
{
  int h = currentTerm.height;
  int w = currentTerm.width;
  moveCursor(w, h);
  redStr("\n|");
  int percCords = (w / 2) - 3;

  if (value % 10 == 1)
  {
    for (int i = 0; i < w - 4; i++)
    {
      if (i == percCords)
      {
        cout << YELLOW << value << "%" << RESET;
      }
      else
      {
        greenStr("=");
        wait(delay);
      }
    }
  }
  else
  {
    for (int i = 0; i < w - 5; i++)
    {
      if (i == percCords)
      {
        cout << YELLOW << value << "%" << RESET;
      }
      else
      {
        greenStr("=");
        wait(delay);
      }
    }
  }

  redStr("|\n");
  blueStr(message);
}