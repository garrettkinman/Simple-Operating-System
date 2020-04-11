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
    
}

/*

*/
int countTotalPages(FILE *f) {
    // TODO
}

/*

*/
void loadPage(int pageNumber, FILE *f, int frameNumber) {
    // TODO
}

/*

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