#include <stdio.h>
#include "pcb.h"
#include "kernel.h"

/*
Copies file to backing store and loads first two pages of program into 
Creates PCB and adds it to the ready queue
*/
int launcher(FILE *p) {

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
    PCB *pcb = makePCB(numPages);
    int frameNumber;
    int isVictimless;

    // if this program requires 2 or fewer pages (i.e., 8 or fewer lines of code)
    // load all pages into ram
    // else, load just the first two into ram
    // then update PCB page tables as necessary
    if (numPages <= 2) {
        for (int i = 0; i < numPages; i++) {
            isVictimless = 1;
            frameNumber = findFrame();
            if (frameNumber < 0) {
                isVictimless = 0;
                frameNumber = findVictim(pcb);
            }
            loadPage(i, copy, frameNumber);
            if(isVictimless) {
                updatePageTable(pcb, i, frameNumber, NULL);
            } else {
                updatePageTable(pcb, i, frameNumber, frameNumber);
            }
        }
    } else {
        for (int i = 0; i < 2; i++) {
            isVictimless = 1;
            frameNumber = findFrame();
            if (frameNumber < 0) {
                isVictimless = 0;
                frameNumber = findVictim(pcb);
            }
            loadPage(i, copy, frameNumber);
            if(isVictimless) {
                updatePageTable(pcb, i, frameNumber, NULL);
            } else {
                updatePageTable(pcb, i, frameNumber, frameNumber);
            }
        }
    }
    
    fclose(copy);

    // TODO: error codes
    return 0;
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
Loads the 4 lines of code from the page into the frame
*/
void loadPage(int pageNumber, FILE *f, int frameNumber) {
    // TODO
}

/*
Searches for an empty frame
Returns index of the frame
Returns -1 if all frames are taken
*/
int findFrame() {
    // TODO
}

/*
Picks a random frame number
If that frame does not belong to the active PCB (i.e., it is not in its page table), return it
Else, increment (modulo-wise) until find one that works
*/
int findVictim(PCB *p) {
    // TODO
}

/*
When load page to or unload page from ram, need to update the page table of the PCB to reflect that
*/
int updatePageTable(PCB *p, int pageNumber, int frameNumber, int victimFrame) {
    // TODO
}