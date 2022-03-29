#include <stdio.h>
#include <stdlib.h>
#define EMPTY 0

typedef struct node {
	int data;
	struct node* link;
}Insert;

Insert* GetNode()
{
	Insert* tmp;
	tmp = (Insert*)malloc(sizeof(Insert));
	tmp->link = EMPTY;
	return tmp;
}

void EnInsert(Insert** head, int data)
{
  Insert *tmp;
  tmp=*head;
	if (*head == EMPTY)
	{
		tmp=*head = GetNode();
    (*head)->data=data;
    (*head)->link=GetNode();
    
	}
  else
  {
    while((tmp)->link!=NULL)
    {
      tmp=tmp->link;
    }
    tmp->data=data;
    tmp->link=GetNode();
  }
  printf("%d\n",tmp->data);
}

void Output(Insert** head)
{
  if(*head!=0)
  {  
    printf("%d\n",(*head)->data);
    Output(&(*head)->link);
  }
}
void Search(Insert** head,int data)
{
  if((*head)->data==data)
  {  
    printf("%d Search!!\n",data);
    return;
  }
  if((*head)->link==0)
  {
    printf("%d not exist!!\n",data);
    return;
  }
  Search(&(*head)->link, data);
}
int main()
{
	Insert* head = EMPTY;
  EnInsert(&head,10);
  EnInsert(&head,20);
  EnInsert(&head,30);
  EnInsert(&head,40);
  Output(&head);
  Search(&head, 60);
	return 0;
}