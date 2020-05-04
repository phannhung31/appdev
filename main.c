
#include <stdio.h>
#include <unistd.h>
#include "screen.h"
#include "comm.h"
#include "sound.h"

int main(void) {  
	 
	FILE *fp;
	fp = fopen("test.wav", "r"); // open the wav file 
	WAVheader h = readwavhdr(fp); // read the first four line
	displayWAVhdr(h);
	clearscreen();
	wavdata(h,fp);	// to calculate dB values and display them
	fclose(fp);	// close the file
	getchar();  
}

