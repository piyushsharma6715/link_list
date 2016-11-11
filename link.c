#include<stdio.h>
#include<stdlib.h>
struct node insert_start(struct node *);
void display(struct node *);
struct node
{
	int data;
	struct node *next;
};
void main()
{
	int ch,ch1,c=0;
	struct node *start;
	start=(struct node*)malloc(sizeof(struct node));
	start->next=NULL;
	do
	{
		printf("ENTER \n 1. FOR INSERTION  \n 2. FOR DISPLAY\n 3. FOR EXIT\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			if(c==0)
			{
				printf("ENTER THE NUMBER");
				scanf("%d",&start->data);
				c=1;
			}
			else
			{
				*start=insert_start(start);
			}
		}
		else if(ch==2)
		{
			display(start);
		}
	}while(ch!=3);
}
struct node insert_start(struct node *start)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->next=NULL;
	printf("ENTER THE NUMBER");
	scanf(" %d",&temp->data);
	temp->next=start ;
printf("temp->next %d start %d",temp->next,start);
	start=temp;
	printf("temp adress %d start.data %d  start.next %d strat add %d  temp .next %d   ",temp,start->data,start->next,start,temp->next);
	return *start;
}
void display(struct node *start)
{
	if((start->data==NULL)&&(start->next==NULL))
	{
		printf("NULL");
	}
	else if(start->next==NULL)
	{
		printf(" %d ",start->data);
	}
	else
	{
	      while(start!=NULL)
		{
			printf("%d----->",start->data);
			start=start->next;
		}
	}
}
