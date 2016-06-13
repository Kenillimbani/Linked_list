

//Simple linklist
struct node 
{
	char name[30];
	int CGPA;
	int roll;
	struct node *next;
};




//Input function, this works for simple linklist
void input(struct node *p)
{
	printf("Enter the CGPA:");
	scanf("%d",&p->CGPA);
	printf("Enter the roll:");
	scanf("%d",&p->roll);
	printf("Enter the name:");	
	scanf("%s",p->name);
}


//for linear link list

//pos = 0 for the beginning  -1 for the end and rest for thier respective positions   
struct node *insert(struct node *head, int pos)
{
	//for an empty linklist	
	if(pos<-1)
	{
		printf("\nThis location deos not exist.");
		return head;
	}
	
	if(head==NULL)
	{	
		head=(struct node*)malloc(sizeof(struct node));
		input(head);
		head->next=NULL;
		return head;
	}
	else 
	{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if(pos==0)//insertion in the beginning
		{
			input(temp);
			temp->next=head; //attach node that are behind
			head=temp;       //swap head and temp
			return head;		
		}
	else if(pos==-1)//insertion at the end
		{
			struct node *temp1;			
			input(temp);
			temp->next=NULL;
			temp1=head;
			while(temp1->next!=NULL)
				temp1=temp1->next;
			temp1->next=temp;
			return head;
		}
	else  //rest of the position
		{
			struct node *temp1; int count=1;			
			temp1=head;
			while(count!=pos)	
			{
				count++;
			if (temp1->next== NULL ) {printf("Unable to find the location."); return head;}
			else temp1=temp1->next;
			}
					
				input(temp);
				temp->next=temp1->next;
				temp1->next=temp;
				return head;
			 
		}
	}
	printf("Insertion failure.");
}



//display function applies to all the various types of nodes
void display(struct node *head)
{
	if(head==NULL) printf("The list is empty.");
	else 
	{
		struct node *temp;
		temp = head;
		while(temp!=NULL)
		{
			printf("\n The name : %s",temp->name);
			printf("\n The CGPA : %d",temp->CGPA);
			printf("\n The roll : %d",temp->roll);
			temp=temp->next;		
		}

	}
}


//will search roll number wise
int search(struct node *head)
{
	if(head==NULL) { printf("\nThe list is empty."); return 0;}
	else
	{
		int rn;
		printf("\nEnter the roll number to be searched:");
		scanf("%d",&rn);
		int count =0;
		struct node *temp;
		temp=head;
		while(temp!=NULL)
		{
			count++;
			if(temp->roll==rn) 
			{ 	
				printf("\n The name : %s",temp->name);
				printf("\n The CGPA : %d",temp->CGPA);
				printf("\n The roll : %d",temp->roll);
				printf("\nFound at location: %d",count);
				return count;
			}
			else temp=temp->next;
			}
		printf("\nNode not found.");	
		return 0;		
	}
	printf("BooHoo baby some other error.");
	return 0;
}




//deletes a single node on the basis of position
struct node *dele(struct node *head)
{
	//Empty list?
	if (head==NULL) {printf("The list is empty."); return head;	}
	int target;
	printf("\nEnter the position from you want to delete:");
	scanf("%d",&target);
	switch(target)
	{
		case 1 : head = head->next; printf("\nDeletion Success."); return head; break;
		default : struct node *temp,*pre;
				  int a=0;
				  temp=head;
			  	  pre=head;
				  while(temp!=NULL)
					{
						
						temp=temp->next;
						if(a==target){	printf("\nDeletion Success."); pre->next=temp->next; return head;}
						pre=temp; a++;
					}
	}
	

	printf("\nThe roll number was not found.");
}


// for ordered link list
//ordered insertion
struct node *inso(struct node *head)
{
	//for an empty linklist	
	if(head==NULL)
	{	
		head=(struct node*)malloc(sizeof(struct node));
		input(head);
		head->next=NULL;
		return head;
	}
	else 
	{
	struct node *neew,*temp,*pre;
	neew=(struct node*)malloc(sizeof(struct node));
	input(neew);
	//Smallest element entered?
	if(neew->roll<=head->roll) { neew->next=head; head = neew; return head;}
	//Traversal time :D
	temp=head;
	pre=head;
	while(temp->next!=NULL)
		{
		temp=temp->next;
		if(neew->roll<=temp->roll){	neew->next=temp; pre->next=neew; return head;	}
		pre=temp;
		}
		
	temp->next=neew;
	neew->next=NULL;
	return head;
	}
	
	printf("Insertion failure.");
}

//rest of the functions remain the same.







//circular functions
//circular insertion
struct node *insc(struct node *head, int pos , int count)
{
	//for an empty linklist	
	if(count==0)
	{	
		head=(struct node*)malloc(sizeof(struct node));
		input(head);
		head->next=head; // the node points to itself
		return head;
	}
	else 
	{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if(pos==0)//insertion in the beginning
		{
			struct node *temp1;
			temp1=head;
			input(temp);
			temp->next=head; //attach node that are behind
			head=temp;       //swap head and temp
			int i;
			for (i=0; i<count; i++) temp1=temp1->next;
			temp1->next=head;
			return head;		
		}
	else if(pos==-1)//insertion at the end
		{
			struct node *temp1;			
			input(temp);
			temp->next=head;
			temp1=head;
			while(temp1->next!=head)
				temp1=temp1->next;
			temp1->next=temp;
			return head;
		}
	else  //rest of the position
		{
			struct node *temp1; int co=1;			
			temp1=head;
			while(co!=pos)	
			{
				co++;
			if (temp1->next== NULL ) {printf("Unable to find the location."); return head;}
			else temp1=temp1->next;
			}
					
				input(temp);
				temp->next=temp1->next;
				temp1->next=temp;
				return head;
			 
		}
	}
}



//circular display
void disp_c(struct node *head, int count)
{
	if(count==0) printf("The list is empty.");
	else 
	{
		struct node *temp; int c=0;
		temp = head;
		while(c!=count)
		{
			c++;
			printf("\n The name : %s",temp->name);
			printf("\n The CGPA : %d",temp->CGPA);
			printf("\n The roll : %d",temp->roll);
			temp=temp->next;		
		}

	}
}


//search in a circular link list, modified to not show infinite loop
int search_c(struct node *head,int count)
{
	if(count==0) { printf("\nThe list is empty."); return 0;}
	else
	{
		int rn;
		printf("\nEnter the roll number to be searched:");
		scanf("%d",&rn);
		int co =0;
		struct node *temp;
		temp=head;
		while(co!=count)
		{
			co++;
			if(temp->roll==rn)
			 {
			 	printf("\n The name : %s",temp->name);
				printf("\n The CGPA : %d",temp->CGPA);
				printf("\n The roll : %d",temp->roll);
				 printf("\nFound at location: %d",co);
				 return co;
				 }
			else temp=temp->next;
			}
		printf("\nNode not found.");	
		return 0;		
	}
	printf("BooHoo baby some other error.");
	return 0;
}


//circular linked list deletion, the counting variable is directly modified incase of any insertion failure
struct node *dele_c(struct node *head, int *count)
{
	//Empty list?
	if (*count==0) {printf("The list is empty."); return head;	}
	int target,co=0;
	printf("\nEnter the roll number you want to delete:");
	scanf("%d",&target);
	//First element?
	if(head->roll==target) {	head=head->next; *count--; return head;  }
	//For traversal
	struct node *temp,*pre;
	temp=head;
	pre=head;
	while(co!=*count)
	{
		co++;
		temp=temp->next;
		if(temp->roll==target){	pre->next=temp->next;	*count--;return head;}
		pre=temp;
	}
	printf("\nThe roll number was not found.");
}

