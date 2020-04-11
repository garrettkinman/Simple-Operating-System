#include <stdio.h>
#include <stdlib.h>
/*
PCB has 3 fields
PC : Points to the the current line reached for that program
start: Points to first line of that program
end: Points to last line of that program

~~~NEW STUFF~~~
pageTable: index is the page number; values stored in each cell are the frame numbers
PC_page: which page the process is currently on
PC_offset: which line within the page the process is currently on
pages_max: total number of pages within this process
*/
typedef struct PCB
{
    int PC;
    int start;
    int end;
    int pageTable[10];
    int PC_page;
    int PC_offset;
    int pages_max;
}PCB;


/*
Passes 2 parameters (start , end)
This method creates a PCB with fields set as this:
PC = start
start = start
end = end
*/
PCB* makePCB(int start, int end){
    PCB* pcb = (PCB*)malloc(sizeof(PCB));
    pcb->PC = start;
    pcb->start = start;
    pcb->end = end;
    return pcb;
}


