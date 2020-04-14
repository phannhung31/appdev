// In this file, we have a set of screen manipulation functions  These 
//functions can change fore- back-ground colors, clearscreen, restore 
// default setting, etc,.. //To enable screen manipulations, we need to use 
//VT100 escape sequences. //Link: 
// http://www.termsys.demon.co.uk/vtansi.htm
#include <stdio.h>
#include "screen.h"	
// for printf() function include "screen.htains constants used in this file
//function definitions // a function name is an indentifier in C, an 
// identifier should start with a letter or an underscore, and followed
int devicestatus(void){
	printf("%c[5n", ESC);
	char status[40];
	scanf("%s", status);
	int ret;
	char dum;
	sscanf(status, "%c%c%d%c", &dum, &dum, &ret, &dum);
	return ret;
} 
void setfgcolor(int fg){
	printf("%c[1;%dm", ESC, fg);
}

void setbgcolor(int bg){
	printf("%c[1;%dm", ESC, bg);
}
void setcolors(int f, int b){
	setfgcolor(f);
	setbgcolor(bg(b));
}
void clearscreen(void){
	printf("%c[2J",ESC);
}
void resetcolors(void){
	printf("%c[0m",ESC);
}
void gotoXY(int row, int col){
	printf("%c[%d;%dH", ESC, row, col);
}
void drawbar(int col, int height){
	int i;
	for(i=1; i<=height; i++){
		gotoXY(i, col);
#ifdef UNICODE
	printf("%s", BAR);
#else
	printf("%c",'|');
#endif
	}
}

Position getscreensize(void){
	Position p;
	char ret[100] = "\0";	//make an empty string for query return
	int r, c;
	gotoXY(999,999);	//move cursor to the right-bottom corner
	printf("%c[6n",ESC);	// send query sequence to the terminal
	scanf("%s",ret);
#ifdef DEBUG
	printf("%s\n",ret);
#endif
#include <string.h>
	// the following code will be decode the return string from terminal
	if(strlen(ret)>0){
		char dum; //dummy char to consume the chars in ret string
		sscanf(ret,"%c%c%d%c%d%c", &dum, &dum, &r, &dum, &c, &dum);
		p.row = r;
		p.col = c;
	}
	else {
		p.row=0;
		p.col=0;
	}
	return p;
}
