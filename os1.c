#include<stdio.h>
#include"os.h"
#include<string.h>
#include<stdlib.h>


struct process *pq=NULL,*pq3=NULL,*curr,*temp,*curr1,*temp1,*pri,*sh,*pq1=NULL,*loc,*locp,*start,*ptr,*ptrp,*tr;
int timer=0;


//function for creating process for queue 1 which run according to priority and if higher priority process arrives 
//current process will move to queue 2 
void create_processpq(int p_id,int priority,int burst_time,int arrival_time)
{
    temp=(struct process*)(malloc (sizeof(struct process)));
    if(temp==NULL)
    {
        printf("memory not allocated\n");
        
    }
    else
    {
        
        temp->p_id=p_id;
        temp->arrival_time=arrival_time;
        temp->burst_time=burst_time;
        temp->priority=priority;
        temp->next=NULL;
        if(pq==NULL)
        {
            
            pq=temp;
            curr=temp;
        }
        else
        {
           
            curr->next=temp;
            curr=temp;
        }
    }
    printf("process created\n");
    
   
    
}

//function for creating process for queue 2 which runs process according to round robin algorithm
void create_processpq1(int p_id,int priority,int burst_time,int arrival_time)
{
    temp=(struct process*)(malloc (sizeof(struct process)));
    if(temp==NULL)
    {
        printf("memory not allocated\n");
        
    }
    else
    {
        
        temp->p_id=p_id;
        temp->arrival_time=arrival_time;
        temp->burst_time=burst_time;
        temp->priority=priority;
        temp->next=NULL;
        if(pq1==NULL)
        {
            
            pq1=temp;
            curr1=temp;
        }
        else
        {
            
            curr1->next=temp;
            curr1=temp;
        }
    }
    printf("process created\n");
}
//function for showing process for queues
void show_process(struct process *arg)
{
    sh=arg;
    do
    {
        printf("p_id :%-20d\n",sh->p_id);
        printf("priority :%-20d\n",sh->priority);
        printf("burst_time :%-20d\n",sh->burst_time);
        printf("arrival_time :%-20d\n\n\n",sh->arrival_time);
        sh=sh->next;
    }while(sh!=NULL);

}
//it delete process of queue 1
void del_processpq()
{
    printf("process : %d   is finished \n\n\n",pq->p_id);
    curr=pq;
    pq=pq->next;
    if(pq!=NULL)
     printf("new process :  %d  \n",pq->p_id);
    else
     {printf("finished all process of queue 1\n");
     printf("==============================\n\n\n\n");}
    free(curr);
}
//this function delete process of queue 2
struct process* del_processpq1()
{
    
    start=pq1;
    if(start==NULL)
    {
        return NULL;
    }
    if(start->burst_time==0)
    {
        
        if(start->next==NULL)
        {
            pq1=NULL;
            printf("finished all process of queue 2  \n");
            printf("\n******************************\n");
            free(start);
            return NULL;
        }
        else
        {
            
            temp=pq1;
            pq1=pq1->next;
            //printf("new process :  %d  \n",start->next->p_id);
            free(temp);
            return pq1;
        }
        
    }
    ptrp=start;
    ptr=start->next;
    
    while(ptr!=NULL)
    {
        if(ptr->burst_time==0)
        {
            loc=ptr;
            locp=ptrp;
            break;
            
        }
        else
        {
            ptrp=ptr;
            ptr=ptr->next;
        }
        
        

    }
    if(loc->next==NULL)
    {
        temp=loc;
        locp->next=NULL;
        free(temp);
        return locp;
    }
    else
    {
        temp=loc;
        locp->next=loc->next;
        free(temp);
        return locp->next;
    }
    
    
}
// function for adding process in queue 2 which is preempted by queue 1 when higher priority process comes
void preempt()
{
    if(pq3==NULL)
    {
        pq3=pq;
        pq=pq->next;
        curr1=pq3;
        curr1->next=NULL;
    }
    else
    {
        curr1->next=pq;
        pq=pq->next;
        curr1=curr1->next;
        curr1->next=NULL;
    }
    
    

}

int main()
{
    int p_id,priority,burst_time, arrival_time;
    printf("\nenter process for queue 1\n\n");
    for(int i=0;i<5;i++)
    {
        printf("\nenter p_id\n");
        scanf("%d",&p_id);
        printf("enter priority\n");
        scanf("%d",&priority);
        printf("enter burst time\n");
        scanf("%d",&burst_time);
        printf("enter arrival time\n");
        scanf("%d",&arrival_time);
        create_processpq(p_id,priority,burst_time, arrival_time);
        

    }
    printf("\n\n\nenter process for queue 2\n\n\n");
    for(int i=0;i<5;i++)
    {
        printf("\nenter p_id\n");
        scanf("%d",&p_id);
        //printf("enter priority\n");
        //scanf("%d",&priority);
        printf("enter burst time\n");
        scanf("%d",&burst_time);
        printf("enter arrival time\n");
        scanf("%d",&arrival_time);
        create_processpq1(p_id,0,burst_time, arrival_time);
        

    }

    //sorting queue 1 according to their arrival time    
    bubbleSort(pq);
   show_process(pq);
   //show_process(pq1);
   

    printf("\n\n\n\n\n\nqueue 1 starts executing by priority\n");
    printf("\n******************************\n\n\n\n");
    pri=pq;
    
    while(1)
    {
        if(pri->arrival_time>timer)
        {
            timer++;
            printf("timer %d       cpu is idle\n",timer);
            continue;
        }
        pri=pq;
        printf("running process %d\n",pri->p_id);
        timer=timer+1;
        pri->burst_time--;
        printf("timer %d       burst_time left %d\n",timer,pri->burst_time);
        temp1=pri->next;
        if(temp1!=NULL)
        {
            while(temp1->arrival_time<=timer && temp1!=NULL)
            {
                
                if(temp1->priority<pri->priority)
                {
                    printf("process  p_id   %d is preempting by process  p_id  %d\n\n",pri->p_id,temp1->p_id);
                    preempt();
                    
                }
               
                temp1=temp1->next;
                if(temp1==NULL)
                {
                    break;
                }
                
            }
            
        }
        
        if(pri->burst_time==0)
        {
            
            del_processpq();
            
        }
        if(pq==NULL)
            {
                break;
            }
        if(pq->arrival_time>timer)
        {
            while(1)
            {
                timer++;
                printf("timer %d       cpu is idle\n",timer);
                if(pq->arrival_time==timer)
                break;
            }
        }
    }
   


    //round robin
    bubbleSort(pq1);
    curr1->next=pq1;
    pq1=pq3;
    show_process(pq1);
    printf("\n\n\n\nqueue 2 starts executing by round robin\n");
    printf("\n============================\n\n\n\n\n");
    pri=pq1;
   
    while(1)
    {
        if(pri->arrival_time>timer)
        {
            timer++;
            printf("timer  %d         cpu is idle\n",timer);
            continue;

        }
        
        printf("process id %d    running\n",pri->p_id);
        timer++;
        pri->burst_time--;
        printf("timer %d         brust_left  %d\n",timer,pri->burst_time);
        if(pri->burst_time==0)
        {
            printf("\nprocess p_id  %d   is finished\n\n\n\n",pri->p_id);
            tr=del_processpq1();
            if(tr==NULL)
            {
                break;
            }
            else
            {
                pri=tr;
                continue;
            }
            
        }
        if(pq1==NULL)
        {
            
            break;

        }
        else
        {
            
            if(pri->next==NULL)
            {
                pri=pq1;
            }
            else
            {
                if(pri->next->arrival_time>timer)
                {
                    pri=pq1;
                }
                else
                {
                    pri=pri->next;
                }
            }
            
            
            
            
            
        }
        
        





    }
    
    
    
}
