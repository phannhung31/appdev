// we test function of screen.c
#include <stdio.h>
#include <unistd.h>
#include "screen.h"
#include "comm.h"
#include "sound.h"

int main(void) {
	FILE *fp;
	fp = fopen("test.wav", "r");
	WAVheader h = readwavhdr(fp);
	displayWAVhdr(h);
	clearscreen();
	wavdata(h,fp);	// to calculate dB values and display them

	fclose(fp);
	getchar();
}

