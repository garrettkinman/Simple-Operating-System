#include <stdio.h>
#include "pcb.h"

/*

*/
int launcher(FILE *p) {
    // TODO
    // 1) Copy the entire file into the backing store. (set filename as the PID)
    // 2) Close the file pointer pointing to the original file.
    // 3) Open the file in the backing store.
    // 4) Our launch paging technique defaults to loading two pages of the program into RAM
        // when it is first launched. A page is 4 lines of code.
        // If the program has 4 or fewer lines of code, then only one page is loaded.
        // If the program has more than 8 lines of code, then only the first two pages are loaded.
        // To do this, use the below helper functions.

    // creates a text file with name of format PCB#.txt where # is the PID of the PCB for program
    int PID = getCurrentPID();
    char filename[15];
    sprintf(filename, "PCB%d.txt", PID);
    FILE *copy = fopen(filename, "w+");

    if (copy == NULL) {
        // TODO: return error code
    }

    // copy the file contents
    char c;
    while (!feof(p)) {
        c = fgetc(p);
        fputc(c, copy);
    }

    int numPages = countTotalPages(copy);
    if (numPages <= 1) {
        // load the page into ram
    } else if (numPages <= 2) {
        // load both pages into ram
    } else {
        // load first two pages into ram
    }
    
    
}

/*
Returns the total number of pages needed by the program
If it has 4 or fewer lines of code, return 1
If it has 5 to 8 lines of code, return 2
Etc...
*/
int countTotalPages(FILE *f) {
    int lines = 0;
    while (!feof(f)) {
        char c = fgetc(f);
        if (c == '\n') {
            lines++;
        }
    }

    // if 7 lines, there should be 2 pages
    // if 
    if ((lines % 4) == 0) {
        return lines / 4;
    } else {
        return (lines / 4) + 1;
    }
}

/*

*/
void loadPage(int pageNumber, FILE *f, int frameNumber) {
    // TODO
}

/*
Uses FIFO algorithm to search ram for a 
*/
int findFrame() {
    // TODO
}

/*

*/
int findVictim(PCB *p) {
    // TODO
}

/*

*/
int updatePageTable(PCB *p, int pageNumber, int frameNumber, int victimFrame) {
    // TODO
}