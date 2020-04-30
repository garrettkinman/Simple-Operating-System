/*
Copies file to backing store and loads first two pages of program into ram
*/
int launcher(FILE *p);

/*
Loads the 4 lines of code from the page into the frame
*/
void loadPage(int pageNumber, FILE *f, int frameNumber);

/*
Searches for an empty frame
Returns index of the frame
Returns -1 if all frames are taken
*/
int findFrame();

/*
Picks a random frame number
If that frame does not belong to the active PCB (i.e., it is not in its page table), return it
Else, increment (modulo-wise) until find one that works
*/
int findVictim(PCB *p);

/*
When load page to or unload page from ram, need to update the page table of the PCB to reflect that
*/
int updatePageTable(PCB *p, int pageNumber, int frameNumber, int victimFrame);