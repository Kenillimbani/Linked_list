#include<stdio.h>
#include<stdlib.h>

struct linked_list
{
	int data;
	struct linked_list *lptr;
	struct linked_list *rptr;
};

typedef struct linked_list node;
node *L,*R;

void insertion();
void deletion();
void search();
void display();
void create();
void reverse();
int count=0;
main()
{
		L=(node *)malloc(sizeof(node));
		R=(node *)malloc(sizeof(node));

	//head=NULL;
	int n,x;
	x:
	printf("\n1 - Create\n");
	printf("2 - deletion\n");
	printf("3 - searching\n");
	printf("4 - display\n");
	printf("5 - Insertion\n");
	printf("6 - reverse\n");
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
			insertion();
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
	if(count==0)
	{
		L->data=d;
		printf("%d",L->data);
		L->rptr=L->lptr=NULL;
		count++;
	}
	else
	{
		node *save,*new;
		new=(node *)malloc(sizeof(node));
		save=(node *)malloc(sizeof(node));
		save=L;
		while(save->rptr!=NULL)
		{
			save=save->rptr;
		}
		new->rptr=NULL;
		new->lptr=save;
		new->data=d;
		save->rptr=new;
		R=new;
		printf("%d",R->data);
		count++;
	}
}

void display()
{
	node *save;
	save=(node *)malloc(sizeof(node));
	save=L;
	
	while(save->rptr!=NULL)
	{
		printf("%d <-->",save->data);
		save=save->rptr;
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
		save=L;
		
		for(i=1;i<p;i++)
		{
			save=save->rptr;
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
		new->rptr=NULL;
		new->lptr=NULL;
	if(p>count+1 || p<0)
	{
		printf("\nEntered wrong position\n");
	}
	else if(p==1)
	{
		new->rptr=L;
		new->lptr=NULL;
		L=new;
		count++;
	}
	else
	{
		node *save;
		save=(node *)malloc(sizeof(node));
		save=L;
		
		for(i=1;i<p-1;i++)
		{
			save=save->rptr;
		}
		if(p==count+1)
		{
			new->lptr=save;
			new->rptr=NULL;
			save->rptr=new;
			R=new;
		}
		else
		{
			new->rptr=save->rptr;
			new->lptr=save;
			save->rptr=new;
			new->rptr->lptr=new;
		
		printf("%d",new->data);
		printf("%d\n",new->rptr->data);
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
		
	if(count==0)
	{
		printf("Linked_list is empty");
		
	}
	else
	{
		 if(p>count || p<0)
		{
			printf("\nEntered wrong position\n");
		}
		else if(count==1)
		{
			free(L);
			count--;
		}
		else if(p==1)
		{
			t=L;
			L=L->rptr;
			L->lptr=NULL;
			free(t);
			count--;
		}
		else
		{
			node *save;
			save=(node *)malloc(sizeof(node));
			save=L;
			
			for(i=1;i<p-1;i++)
			{
				save=save->rptr;
			}
		
			t=save->rptr;
			
			if(p==count)
			{
				save->rptr=NULL;
				R=save;
			}
			
			
			else
			{
			save->rptr=save->rptr->rptr;
			save->rptr->lptr=save;
			
			}
			
			free(t);
			count--;
			
		}
	}
}


void reverse()
{
	node *t,*save,*pre;
	
	save=L->rptr;
	t=L;
	t->rptr=NULL;
	save->lptr=NULL;
	
	while(save->rptr!=NULL)
	{
		pre=save;
		save=save->rptr;
		save->lptr=NULL;
		
		pre->rptr=t;
		t->lptr=pre;
		t=pre;
	}
	save->rptr=t;
	L=save;
		
}
