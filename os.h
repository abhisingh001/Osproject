#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct process
    {
        int p_id;
        int priority;
        int burst_time;
        int arrival_time;
        struct process *next;
        
    };



void swap(struct process *a, struct process *b) 
{ 
    
    int arrival_time = a->arrival_time; 
    int p_id=a->p_id;
    int burst_time=a->burst_time;
    int priority=a->priority;
    a->arrival_time = b->arrival_time; 
    a->p_id=b->p_id;
    a->burst_time=b->burst_time;
    a->priority=b->priority;
    b->arrival_time = arrival_time;; 
    b->p_id=p_id;
    b->priority=priority;
    b->burst_time=burst_time;
} 


void bubbleSort(struct process *start) 
{ 
    int swapped, i; 
    struct process *ptr1; 
    struct process *lptr = NULL; 
    //printf("bubble is runnung\n");
    /* Checking for empty list */
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->arrival_time > ptr1->next->arrival_time) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } while (swapped); 
} 
  
/* function to swap arrival_time of two processs a and b*/





