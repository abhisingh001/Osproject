#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//structure for process
struct process
    {
        int p_id;
        int priority;
        int brust_time;
        int arrival_time;
        struct process *next;
        
    };


/* function to swap arrival_time of two processs a and b*/
void swap(struct process *a, struct process *b) 
{ 
    printf("swapp is runnung\n");
    int arrival_time = a->arrival_time; 
    int p_id=a->p_id;
    int burst_time=a->brust_time;
    int priority=a->priority;
    a->arrival_time = b->arrival_time; 
    a->p_id=b->p_id;
    a->brust_time=b->brust_time;
    a->priority=b->priority;
    b->arrival_time = arrival_time;; 
    b->p_id=p_id;
    b->priority=priority;
    b->brust_time=burst_time;
} 

//sorting process on basis of arrival time
void bubbleSort(struct process *start) 
{ 
    int swapped, i; 
    struct process *ptr1; 
    struct process *lptr = NULL; 
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
  





