#include <stdio.h>
#include <stdlib.h>

/*
PCB has 6 fields
PID: process ID
PC : Points to the the current line reached for that program
PC_page: which page the process is currently on
PC_offset: which line within the page the process is currently on
pages_max: total number of pages within this process
pageTable: index is the page number; values stored in each cell are the frame numbers
*/
typedef struct PCB
{
    int PID;
    int PC;
    int PC_page;
    int PC_offset;
    int pages_max;
    int pageTable[10];
}PCB;

int PID = 0;

/*
Passes 2 parameters (start , end)
This method creates a PCB with fields set as this:
PC = start
start = start
end = end
*/
PCB* makePCB(int numPages){
    PCB* pcb = (PCB*)malloc(sizeof(PCB));
    pcb->PID = PID;
    pcb->PC = 0;
    pcb->PC_page = 0;
    pcb->PC_offset = 0;
    pcb->pages_max = numPages;

    PID++;

    return pcb;
}

/*
Function to allow memory manager to access the current PID of the most recently made PCB
so it can name the backing store file appropriately
*/
int getCurrentPID() {
    return PID;
}


