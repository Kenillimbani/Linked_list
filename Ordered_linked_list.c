#include<stdio.h>
#include<stdlib.h>

struct linked_list
{
	int data;
	struct linked_list *next;
};

typedef struct linked_list node;
node *head;

void reverse();
void deletion();
void search();
void display();
void create();

int count=0;
main()
{
		head=(node *)malloc(sizeof(node));
	//head=NULL;
	int n,x;
	x:
	printf("\n1 - Create\n");
	printf("2 - deletion\n");
	printf("3 - searching\n");
	printf("4 - display\n");
	printf("5 - Insertion\n");
	printf("6 - Reverse\n");
	printf("7 - Exit\n");
	printf("Enter choice: ");
	scanf("%d",&n);
	
	switch(n)
	{
		case 1:
			create();
			break;
		case 2:
			deletion();
			break;
		case 3:
			search();
			break;
		
		case 4:
			display();
			break;
		case 5:
			create();
			break;
		case 6:
			reverse();
			break;
		case 7:
			exit(0);
			break;
		default:
			printf("Entered wrong choice..");
			break;
	}
	goto x;	
}

void create()
{
	int d;
		printf("Enter your data: ");
		scanf("%d",&d);
		
			node *new,*save,*pre;
		new=(node *)malloc(sizeof(node));
		
		new->data=d;
		new->next=NULL;
	
	if(count==0)
	{
		head->data=d;
		printf("%d",head->data);
		head->next=NULL;
		count++;
	}
	else
	{
		if(new->data < head->data)
		{
			new->next=head;
			head=new;
			count++;	
		}
		else
		{	save=head;
			while(new->data > save->data && save->next!=NULL)
			{	
				//pre=save;
				save=save->next;
			}
			//printf("%d",pre->data);
			if(new->data > save->data)
			{
				save->next=new;
			}
			else
			{
				new->next=pre->next;
				pre->next=new;
			}
			count++;
		}
	}
	
}

void display()
{
	node *save;
	save=(node *)malloc(sizeof(node));
	save=head;
	while(save->next!=NULL)
	{
		printf("%d-->",save->data);
		save=save->next;
	}
	printf("%d",save->data);
	printf("\n no.of nodes:%d\n",count);
}


void search()
{
	int p,i;
	printf("\nEnter position: ");
	scanf("%d",&p);
	
	if(p>count || p<0)
	{
		printf("\nEntered wrong position\n");
	}
	else
	{
		node *save;
		save=(node *)malloc(sizeof(node));
		save=head;
		
		for(i=1;i<p;i++)
		{
			save=save->next;
		}
		printf("Value at node %d is: %d",p,save->data);
	}
}




void deletion()
{
		int p,i;
		node *t;
		printf("\nEnter your position: ");
		scanf("%d",&p);
	if(p>count || p<0)
	{
		printf("\nEntered wrong position\n");
	}
	else if(p==1)
	{
		t=head;
		head=head->next;
		free(t);
		count--;
	}
	else
	{
		node *save;
		save=(node *)malloc(sizeof(node));
		save=head;
		
		for(i=1;i<p-1;i++)
		{
			save=save->next;
		}
	
		t=save->next;
		
		if(p==count)
		{
			save->next=NULL;
		}
		
		
		else
		{
		save->next=save->next->next;
		}
		
		free(t);
		count--;
		
	}
		
}

void reverse()
{
	node *t,*save,*pre;
	
	save=head->next;
	t=head;
	t->next=NULL;
	
	while(save->next!=NULL)
	{
		pre=save;
		save=save->next;
		
		pre->next=t;
		t=pre;
	}
	save->next=t;
	head=save;
}





















