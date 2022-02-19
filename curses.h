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
// using namespace std;

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

// std::stringS
void addstr(std::string str)
{
  // Add a std::string to the screen.
  std::cout << str;
}

void addstr(std::string str, char color)
{
  // Add a std::string to the screen.
  if (color == 'b' || color == 'B')
  {
    std::cout << BOLD << str << RESET;
  }
  else if (color == 'u' || color == 'U')
  {
    std::cout << UNDERLINE << str << RESET;
  }
  else if (color == 'r' || color == 'R')
  {
    std::cout << REVERSE << str << RESET;
  }
  else
  {
    std::cout << str;
  }
}

void addstr(int lines, int characters, std::string str)
{
  // Add a Lines to the screen.
  for (int i = 0; i < lines; i++)
  {
    std::cout << std::endl;
  }
  // Add a Character Spaces to the screen.
  for (int i = 0; i < lines; i++)
  {
    std::cout << " ";
  }
  // Add a std::string to the screen.
  std::cout << str;
}

void addstr(int lines, int characters, std::string str, char color)
{
  // Add a Lines to the screen.
  for (int i = 0; i < lines; i++)
  {
    std::cout << std::endl;
  }
  // Add a Character Spaces to the screen.
  for (int i = 0; i < lines; i++)
  {
    std::cout << " ";
  }
  // Add a std::string to the screen.
  if (color == 'b' || color == 'B')
  {
    std::cout << BOLD << str << RESET;
  }
  else
  {
    std::cout << str;
  }
}

// SPACES
void gimmeSomeSpace(int lines, int characters)
{
  // Add a Lines to the screen.
  for (int i = 0; i < lines; i++)
  {
    std::cout << std::endl;
  }
  // Add a Character Spaces to the screen.
  for (int i = 0; i < characters; i++)
  {
    std::cout << " ";
  }
}

void gimmeSomeSpace(int lines)
{
  // Add a Lines to the screen.
  for (int i = 0; i < lines; i++)
  {
    std::cout << std::endl;
  }
}

void blackStr(std::string str) { std::cout << BLACK << str << RESET; }
void redStr(std::string str) { std::cout << RED << str << RESET; }
void greenStr(std::string str) { std::cout << GREEN << str << RESET; }
void yellowStr(std::string str) { std::cout << YELLOW << str << RESET; }
void blueStr(std::string str) { std::cout << BLUE << str << RESET; }
void magentaStr(std::string str) { std::cout << MAGENTA << str << RESET; }
void cyanStr(std::string str) { std::cout << CYAN << str << RESET; }
void whiteStr(std::string str) { std::cout << WHITE << str << RESET; }

void boldBlackStr(std::string str) { std::cout << BOLDBLACK << str << RESET; }
void boldRedStr(std::string str) { std::cout << BOLDRED << str << RESET; }
void boldGreenStr(std::string str) { std::cout << BOLDGREEN << str << RESET; }
void boldYellowStr(std::string str) { std::cout << BOLDYELLOW << str << RESET; }
void boldBlueStr(std::string str) { std::cout << BOLDBLUE << str << RESET; }
void boldMagentaStr(std::string str) { std::cout << BOLDMAGENTA << str << RESET; }
void boldCyanStr(std::string str) { std::cout << BOLDCYAN << str << RESET; }
void boldWhiteStr(std::string str) { std::cout << BOLDWHITE << str << RESET; }
