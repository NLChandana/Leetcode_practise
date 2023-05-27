/*
Singly Linked List:-

=> collection of nodes 

node 

10  2000    12  3000   15  NULL 
 1000        2000        3000
 head 


head = 1000 

head = NULL 


10  NULL
 1000
newnode 

10  NULL
 1000
 head 
 
head = 1000 

10  2000    12  3000   15  NULL 
 1000        2000        3000
 head 

40  NULL
 4000
newnode 

current= 3000
newnode =4000

current->next = newnode;

10  2000    12  3000   15  4000 
 1000        2000        3000
 head 

40  NULL
 4000
newnode 


head = 1000


  10
 2000
100000

int a =10;
int *p=&a;
int **q=&p;

q = 100000
*q= 2000
**q = 10 

*/




#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node* next;
};
void add_node(int element,struct node** head_ref)
{
    struct node *newnode,*current = *head_ref;
    newnode =(struct node*)malloc(sizeof(struct node));
    newnode->data = element;
    newnode->next = NULL;
    if(*head_ref == NULL)
        *head_ref = newnode;
    else
    {
        for( ;current->next!=NULL;current=current->next);
        current->next = newnode;
    }
}
void display(struct node *current)
{
    while(current)
    {
        printf("%d ",current->data);
        current =current->next;
    }
}
int main()
{
    struct node* head = NULL;
    add_node(10,head);
    add_node(14,&head);
    add_node(13,&head);
    add_node(12,&head);

    int num;
    while(1)
    {
        scanf("%d",&num);
        if(num==-1)
            break;
        add_node(num,&head);
    }
    display(head);
    return 0;
}

/*
10  2000    12  3000   15  4000 
 1000        2000        3000
 head 
 
 
 5  NULL 
  500
 newnode 
 
10  2000    12  3000   15  4000 
 1000        2000        3000
 
 newnode->next = *head_ref;
 *head_ref = newnode;
 
 5  1000  
  500
 head  
 
 
 head = NULL 
 
 10  NULL 
  1000 
  head 
  
  
10  2000    12  3000   15  4000   18   NULL 
 1000        2000        3000       4000 
 head 
 
13  NULL 
 2500 
newnode 

prev = 2000
current = 3000 

prev = current
current = current->next 

10  2000    12  2500   15  4000   18   NULL 
 1000        2000        3000       4000 
 head 
 
13  3000 
 2500 
newnode 

10  2000    12  3000   15  4000   18   5000
 1000        2000        3000       4000 
 head 
 
30  NULL 
 5000 
newnode 

prev = 4000
current = NULL 
newnode = 5000 

*/

#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node* next;
};
void add_node(int element,struct node** head_ref)
{
    struct node *newnode,*current = *head_ref,*prev;
    newnode =(struct node*)malloc(sizeof(struct node));
    newnode->data = element;
    newnode->next = NULL;
    if(*head_ref == NULL||newnode->data<(*head_ref)->data)
    {
        newnode->next = *head_ref;
        *head_ref = newnode;
    }
    else
    {
        while(current!=NULL && current->data <= newnode->data)
        {
            prev = current;
            current=current->next;
        }
        prev->next = newnode;
        newnode->next = current;
    }
}
void display(struct node *current)
{
    while(current)
    {
        printf("%d ",current->data);
        current =current->next;
    }
}
int main()
{
    struct node* head = NULL;
    int num;
    while(1)
    {
        scanf("%d",&num);
        if(num==-1)
            break;
        add_node(num,&head);
    }
    display(head);
    return 0;
}




