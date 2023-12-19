#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int data;
    struct node*next;
}node;

typedef struct
{
  node *head;
  node *tail;

}linkedlist;

linkedlist *init()
{
    linkedlist*l=malloc(sizeof(linkedlist));
    l->head=NULL;
    l->tail=NULL;
    return l;
}

node*newnode(int x)
{

    node *n=malloc(sizeof(node));
    n->data=x;
    n->next=NULL;
    return n;
}
void insertbegining(linkedlist *list,int x)
{

    node *n=newnode(x);
    if(list->head==NULL)
    {
        list->head=n;
        list->tail=n;

    }
    else
    {

        n->next=list->head;
        list->head=n;


    }


}
void insertend(linkedlist*list,int x)
{
    node *n=newnode(x);
    if(list->head==NULL)
    {

        list->head=n;
        list->tail=n;

    }
    else{


        list->tail->next=n;
        list->tail=n;
    }

}
void deletebegining(linkedlist*l)
{
    if(l->head==NULL)
    return 0;
    else
{ node* temp=l->head;

l->head=l->head->next;
free(temp);
if(l->head==NULL)
        l->tail=NULL;
}
}
void deletelastnode(linkedlist *list)
{
    if(!list->head)
    return ;
    else if(list->head->next=NULL)
       {
           free(list->head);
           list->head=NULL;
           list->tail=NULL;
        }
         else{

            node *temp=list->head;
            node *prev=NULL;
            while(temp->next!=NULL)
         {
             prev=temp;
             temp=temp->next;
        }
        prev->next=NULL;
        list->tail=prev;
        free(temp);

        }
}
void display(linkedlist*l)
{ int i=1;
    node *temp=l->head;
    printf("----------linkedlist elements----------");
    while(temp!=NULL)
    {
        printf("\nthe %d element in list=%d",i,temp->data);
        i++;
        temp=temp->next;



    }


}









int main()
{ int f;int x;char a;
linkedlist*l;
 functions:
printf("\n1)intiallize the linked list\n2)insert from begining linkedlist\n3)insert from end linkedlist\n4)delete from begining linkedlist\n5)delete from end of linked list\n6)display the linked list");


    printf("\nEnter your choice: ");
choice:
    scanf("%d",&f);
    printf("-----------------------------------------------------------------\n");

    switch (f)
    {
    case 1: //intiallize

l=init();




        f=0;
        goto functions;
        break;
    case 2:
        printf("\nenter the intger you want to insert:");

        scanf("%d",&x);
        insertbegining(l,x);

        f=0;
        goto functions;
        break;
    case 3: printf("\nenter the intger you want to insert from end:");

        scanf("%d",&x);
        insertend(l,x);

        f=0;
        goto functions;
        break;
    case 4:

        deletebegining(l);

        f=0;
        goto functions;
        break;
    case 5:
    deletelastnode(l);
        f=0;
        goto functions;
        break;
    case 6: display(l);

        f=0;
        goto functions;
        break;


    }

    return 0;
}
