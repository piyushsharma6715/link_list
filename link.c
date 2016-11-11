#include<stdio.h>
#include<stdlib.h>
struct node* insert_start(struct node *);
struct node* insert_end(struct node *);
struct node* insert_middle(struct node *);
struct node* delete_first(struct node *);
void delete_end(struct node *);
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
		printf("\n ENTER \n 1. FOR INSERTION  \n 2. FOR DELETION\n 3. FOR DISPLAY\n 4. FOR EXIT\n");
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
				printf("\n ENTER \n1. FOR INSERTION AT START\n 2. FOR INSERTION AT END\n 3. FOR INSERTION AT MIDDLE");
				scanf(" %d",&ch1);
				if(ch1==1)
				start=insert_start(start);
				else if(ch1==2)
				start=insert_end(start);
				else if(ch1==3)
				start=insert_middle(start);
				else
				printf("YOU HAVE ENTERED A WRONG VALUE FOR INSERTION");
			}
		}
		else if(ch==2)
		{
			printf("\nENTER \n1.DELETION AT START\n2.DELETION AT END");
			scanf("\n%d",&ch1);
			if(ch1==1)
				start=delete_first(start);
			else if(ch1==2)
				delete_end(start);
		}
		else if(ch==3)
		{
			display(start);
		}
	}while(ch!=4);
}
struct node* insert_start(struct node *start)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->next=NULL;
	printf("ENTER THE NUMBER");
	scanf(" %d",&temp->data);
	temp->next=start ;
	start=temp;
	return start;
}
struct node* insert_end(struct node *start)
{
	struct node *temp,*temp1;
	temp=(struct node*)malloc(sizeof(struct node));
	temp1=(struct node*)malloc(sizeof(struct node));
	temp->next=NULL;
	printf("ENTER THE NUMBER ");
	scanf("%d",&temp->data);
	temp1=start;
	while(1)
	{
	if(temp1->next!=NULL)
	temp1=temp1->next;
	else
	break;
	}
	temp1->next=temp;
	return start;
}
struct node* insert_middle(struct node *start)
{
	struct node *temp,*temp1;
	int d,e,f=0;
	temp=(struct node *)malloc(sizeof(struct node));
	temp1=(struct node *)malloc(sizeof(struct node));
	temp->next=NULL;
	temp1->next=NULL;
	printf("ENTER THE NUMBER");
	scanf("%d",&temp->data);
	printf("ENTER THE POSITION OF INSERTION");
	scanf("%d",&d);
	temp1=start;
	e=d;
	while(1)
	{
	     if(e==1)
		  break;
	     else
	     {
		while(f!=e-2)
		{
			temp1=temp1->next;
			f++;
		}
		e=1;
	     }
	}
	if(d==1)
	{
		temp->next=temp1;
		start=temp;
	}
	else
	{
		temp->next=temp1->next;
		temp1->next=temp;
	}
	return start;
}
struct node* delete_first(struct node *start)
{
struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
temp=start;
start=start->next;
free(temp);
return start;
}
void delete_end(struct node *start)
{
	int n=-1;
	struct node *temp,*temp1;
	temp=(struct node*)malloc(sizeof(struct node));
	temp1=(struct node*)malloc(sizeof(struct node));
	temp=start;
	while(temp!=NULL)
	{
		temp=temp->next;
		n++e;
	}
	temp=start;
	while((n-1)!=0)
	{
		temp=temp->next;
		n--;
	}
	temp1=temp->next;
	temp->next=NULL;
	free(temp1);
}
void display(struct node *start)
{
	if((start->data==NULL)&&(start->next==NULL))
	{
		printf("NULL");
	}
	else if(start->next==NULL)
	{
		printf("%d",start->data);
	}
	else
	{
	      while(start!=NULL)
		{
			printf(" %d ----->",start->data);
			start=start->next;
		}
	}
}
