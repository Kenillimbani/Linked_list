#include<stdio.h>
#include<stdlib.h>

struct linked_list
{
	int data;
	struct linked_list *next;
};

typedef struct linked_list node;
node *head;

void insertion();
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
	printf("6 - Exit\n");
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
			insertion();
			break;
		case 6:
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
	if(count==0)
	{
		head->data=d;
		printf("%d",head->data);
		head->next=head;
		count++;
	}
	else
	{
		node *save,*new;
		new=(node *)malloc(sizeof(node));
		save=(node *)malloc(sizeof(node));
		save=head;
		while(save->next!=head)
		{
			save=save->next;
		}
		new->next=head;
		new->data=d;
		save->next=new;
	
	
		count++;
	}
}

void display()
{
	node *save;
	save=(node *)malloc(sizeof(node));
	save=head;
	while(save->next!=head)
	{
		printf("%d-->",save->data);
		save=save->next;
	}
	printf("%d-->HEAD",save->data);
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

void insertion()
{
	
	int d,p,i;
		node *new;
		new=(node *)malloc(sizeof(node));
		
		printf("Enter your data: ");
		scanf("%d",&d);
		printf("\nEnter your position: ");
		scanf("%d",&p);
		
		new->data=d;
		new->next=head;
	
		node *save;
		save=(node *)malloc(sizeof(node));
		save=head;
		
	if(p>count+1 || p<0)
	{
		printf("\nEntered wrong position\n");
	}
	else if(p==1)
	{
		while(save->next!=head)
		{
			save=save->next;
			}
		
		new->next=head;
		head=new;
		save->next=head;
		count++;
	}
	else
	{
		for(i=1;i<p-1;i++)
		{
			save=save->next;
		}
		if(p==count+1)
		{
			save->next=new;
			
		}
		else
		{
		
		new->next=save->next;
		save->next=new;
		/*printf("%d",new->data);
		printf("%d\n",new->next->data);*/
		}
		count++;
	}
}


void deletion()
{
		int p,i;
		node *t;
		printf("\nEnter your position: ");
		scanf("%d",&p);
		
		node *save;
		save=(node *)malloc(sizeof(node));
		save=head;
		
	if(p>count || p<0)
	{
		printf("\nEntered wrong position\n");
	}
	else if(p==1)
	{
		while(save->next!=head)
		{
			save=save->next;
			}
			t=head;
			head=head->next;
			save->next=head;
			free(t);
			count--;
	}
	else
	{
	
		
		for(i=1;i<p-1;i++)
		{
			save=save->next;
		}
	
		t=save->next;
		
		if(p==count)
		{
			save->next=head;
		}
		
		
		else
		{
		save->next=save->next->next;
		}
		
		free(t);
		count--;
		
	}
		
}







