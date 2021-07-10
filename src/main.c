#include <stdio.h>
#include <stdlib.h>
#define VERSION "alpha0.9.3\n"
extern void mainMenu();
int main(int args, char *argv)
{
	printf(VERSION);
	mainMenu();
}