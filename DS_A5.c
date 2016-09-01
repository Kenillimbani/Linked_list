#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"simply.h"
#include"doubly.h"



//ordered linklist menu
void OLL()
{
	struct node *head;
	head = NULL;
	int choice=1;
	while(choice<=4)
	{
		printf("\n\n\n\nOrdered Linear linked list\n");
		printf("1.Insert\n2.Display\n3.Search\n4.Delete\nOthers to exit.");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: head=inso(head); break;
			case 2: display(head); break;
			case 3:	search(head);	break;
			case 4: head=dele(head); break;
		}	
	}
}


//Linear linked list menu
void LL()
{
	struct node *head;
	head = NULL;
	int choice=1;
	while(choice<=4)
	{
		printf("\n\n\n\nLinear linked list\n");
		printf("1.Insert\n2.Display\n3.Search\n4.Delete\nOthers to exit.");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					printf("\n\nEnter at \n1.Beginning\n2.End\n3.In the middle.\n");
					scanf("%d",&choice);
					switch(choice)
					{
						case 1: head=insert(head,0); break;
						case 2: head=insert(head,-1); break;
						case 3: printf("\nEnter the location:");
								scanf("%d",&choice);
								head=insert(head,choice);
								choice=3;
								break;
						default:printf("\nYou entered the wrong option.");		
					}
					choice=1;
					break;
				 } 
			
			case 2: display(head); break;
			case 3:	search(head);	break;
			case 4: head=dele(head); break;
		}	
	}
}


//circular linklist
void CLL()
{
	struct node *head;
	head = NULL;
	int choice=1 , count=0;    //count keeps track of number of nodes present for the circular queue
	while(choice<=4)
	{
		printf("\n\n\n\nCircular Linear linked list\n");
		printf("1.Insert\n2.Display\n3.Search\n4.Delete\nOthers to exit.");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					printf("\n\nEnter at \n1.Beginning\n2.End\n3.In the middle.\n");
					scanf("%d",&choice);
					switch(choice)
					{
						case 1: head=insc(head,0,count); count++;break;
						case 2: head=insc(head,-1,count); count++;break;
						case 3: printf("\nEnter the location:");
								scanf("%d",&choice);
								head=insc(head,choice,count);
								count++;
								choice=3;
								break;
						default:printf("\nYou entered the wrong option.");		
					}
					choice=1;
					break;
				 } 
			
			case 2: disp_c(head,count); break;
			case 3:	search_c(head,count);	break;
			case 4: head=dele_c(head,&count); break;
		}	
	}
}


void DLL()
{
	struct dnode *L , *R ;
	L=R=NULL;
	int choice=1;
	while(choice<=4)
	{
		printf("\n\n\n\nDoubly linked list\n");
		printf("1.Insert\n2.Display\n3.Search\n4.Delete\nOthers to exit.");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					printf("\n\nEnter at \n1.Beginning\n2.End\n3.In the middle.\n");
					scanf("%d",&choice);
					switch(choice)
					{
						case 1: L=dinsert(L,R,0); break;
						case 2: L=dinsert(L,R,-1); break;
						case 3: printf("\nEnter the location:");
								scanf("%d",&choice);
								L=dinsert(L,R,choice);
								choice=3;
								break;
						default:printf("\nYou entered the wrong option.");		
					}
					choice=1;
					break;
				 } 
			case 2 : disp_d(L,R);break;
			case 3 : search_d(L,R); break;
			case 4 : L=dele_d(L,R); break;
		}	
	}
}


void CDLL()
{
	struct dnode *L , *R ;
	L=NULL;
	R=NULL;
	int choice=1,count=0;
	while(choice<=4)
	{
		printf("\n\n\n\nDoubly linked list\n");
		printf("1.Insert\n2.Display\n3.Search\n4.Delete\nOthers to exit.");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					printf("\n\nEnter at \n1.Beginning\n2.End\n3.In the middle.\n");
					scanf("%d",&choice);
					switch(choice)
					{
						case 1: L=cdins(L,R,0,&count);break;
						case 2: L=cdins(L,R,-1,&count); break;
						case 3: printf("\nEnter the location:");
								scanf("%d",&choice);
								L=cdins(L,R,choice,&count);
								choice=3;
								break;
						default:printf("\nYou entered the wrong option.");		
					}
					choice=1;
					break;
				 } 
			case 2 : csdisp(L,R,count);break;
			case 3 : cssearch(L,R,count); break;
			case 4 : L=csdele(L,R,&count); break;
		}	
	}
}



//main function 
void main ()
{
	int choice=1;
	printf("\nAccess what type of linklist?\n1.Linear linklist.\n2.Ordered linear link list.");
	printf("\n3.Circular linked list.\n4.Doubly linked lists.\n5.Circular doubly linked list.");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: LL(); break;
		case 2: OLL(); break;
		case 3: CLL(); break;
		case 4: DLL(); break;
		case 5: CDLL(); break;
	}
}

