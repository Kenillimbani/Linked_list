#include<stdio.h>
#include<stdlib.h>

struct linked_list
{
	int data;
	struct linked_list *next;
};

typedef struct linked_list node;
node *head,*head1;

void insertion();
void deletion();
void search();
void display();
void create();
void reverse();
void value_at_kth();
int count=0;
void copy_link();
void swapping_two_nodes();
//void swap(node *,node *,node *);
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
	printf("7 - change_Value kth node\n");
	printf("8 - Copy_linked_list\n");
	printf("9 - Swapping two nodes\n ");
	printf("10- Exit\n");

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
			value_at_kth();
			break;
		case 8:
			copy_link();
			break;
		case 9:
			swapping_two_nodes();		
		case 10:
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
		head->next=NULL;
		count++;
	}
	else
	{
		node *save,*new;
		new=(node *)malloc(sizeof(node));
		save=(node *)malloc(sizeof(node));
		save=head;
		while(save->next!=NULL)
		{
			save=save->next;
		}
		new->next=NULL;
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
		new->next=NULL;
		
	if(p>count+1 || p<0)
	{
		printf("\nEntered wrong position\n");
	}
	else if(p==1)
	{
		new->next=head;
		head=new;
		count++;
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


void value_at_kth()
{
	int p,n,i;
	node *save;
	printf("Enter position:");
	scanf("%d",&p);
	
	if(p>count || p<0)
	{
		printf("\nIncorrect position...\n");
	}
	else
	{
		printf("Enter data: ");
		scanf("%d",&n);
		
		if(p==1)
		{
			head->data=n;	
		}
		
		else
		{	
			save=head;
			
			for(i=1;i<p;i++)
			{
				save=save->next;
			}
			
			save->data=n;
		}
	}
}

void copy_link()
{
		head1=(node *)malloc(sizeof(node));
		node *save,*pre,*new,*save1;
		
		save=head;
			
			head1->data=save->data;
			save=save->next;
			save1=head1;
			
		while(save->next!=NULL)
		{
			new=(node *)malloc(sizeof(node));
			pre=save;
			save=save->next;
			
			new->data=pre->data;
			save1->next=new;
			save1=save1->next;
			
		}
		new=(node *)malloc(sizeof(node));
		new->data=save->data;
		new->next=NULL;
		save1->next=new;
		
		
		save=head1;
		printf("\nCopied_linked_list : ");
	while(save->next!=NULL)
	{
		printf("%d-->",save->data);
		save=save->next;
	}
	printf("%d\n",save->data);
}


void swapping_two_nodes()
{
	node *save,*pre,*temp,*temp1;
	save=head;
	while(save->next!=NULL)
	{
		pre=save;
		
		save=save->next;
		pre->next=save->next;
		save->next=save->next->next;	
		save->next->next=save;
		save=save->next;
	}
	
}














