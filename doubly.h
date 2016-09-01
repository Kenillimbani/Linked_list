//doubly linklist structure
struct dnode
{
	char name[30];
	int CGPA;
	int roll;
	struct dnode *lptr;
	struct dnode *rptr;
};


//doubly linklist input fields
void dinput (struct dnode *p)
{
	printf("Enter the CGPA:");
	scanf("%d",&p->CGPA);
	printf("Enter the roll:");
	scanf("%d",&p->roll);
	printf("Enter the name:");	
	scanf("%s",p->name);
}



/*insertion in a doubly linklist
pos =0, for insertion at very left
pos =-1, for insertion at very right
any other input is regarded as it's position from the leftmost node*/ 
struct dnode *dinsert(struct dnode *L,struct dnode *R, int pos)
{
	struct dnode *NEW;
	NEW=(struct dnode*)malloc(sizeof(struct dnode));
	dinput(NEW);
	//for an empty doubly linked list
	if(pos<-1)
		{	printf("Invalid location."); return L;	}
	else if (L==NULL&&R==NULL)
	{
		L=R=NEW;
		return L;
	}
	else if (pos==0)
	{
		NEW->rptr=L;
		NEW->lptr=NULL;
		L->lptr=NEW;
		L=NEW;
		return L;		
	}
	else if(pos==-1)
	{
		NEW->lptr=R;
		NEW->rptr=NULL;
		R->rptr=NEW;
		R=NEW;
		return L;
	}
	else 
	{
		int co=0;
		struct dnode *temp;
		temp=L;
		while (co!=pos)
		{
				co++;
				if(temp->rptr==NULL) {	printf("Invalid location, does not exist"); return L;	}
				else
				{
					temp=temp->rptr;
					if(co==pos)
					{  //Insertion process begins here
						NEW->lptr=temp;
						NEW->rptr=temp->rptr;
						(temp->rptr)->lptr=NEW;
						temp->rptr=NEW;
						return L;
					}
				}
		}
	}
}



//Display function for doubly linked list
//designed to diplay from left to right, it can be easily reversed
void disp_d(struct dnode *L,struct dnode *R )
{
	if(L==NULL&&R==NULL) printf("The list is empty.");
	else
	{
		
		struct dnode *temp;       //temporary pointer for traversal
		temp=L;
		while(temp!=NULL)
		{
			printf("\nThe name: %s",temp->name);
			printf("\nThe roll: %d",temp->roll);
			printf("\nThe CGPA: %d",temp->CGPA);
			temp=temp->rptr;
	 	} 
	}
}




//search function , will search the list roll number wise
int search_d(struct dnode *L, struct dnode *R)
{
	if(L==NULL&&R==NULL){ printf("\nThe list is empty."); return -1;}
	else 
	{
		struct dnode *temp;
		int co=1,target;
		printf("\nEnter the target roll number:");
		scanf("%d",&target);
		temp=L;
		while(temp!=NULL)
		{
			if(temp->roll==target) 
			{	
				printf("\nThe name: %s",temp->name);
				printf("\nThe roll: %d",temp->roll);
				printf("\nThe CGPA: %d",temp->CGPA);
				printf("\nTarget found at location : %d",co);
				return co;			
			}
			else temp=temp->rptr;
		}
		printf("\nThe node was not found."); return -1;
		
	}
	printf("\nBooHoo babes, there's some error above."); return -1;
}


//For deletion in doubly linked list, utilizes the above search funtion inside it
struct dnode *dele_d(struct dnode *L, struct dnode *R)
{
	if(L==NULL&&R==NULL)
	{
		printf("\nThe list is empty. No deletion can occur here.");
	}
	else
	{
		struct dnode *temp;
		temp= L;
		int v,i;
		v=search_d(L,R);
		if(v>=0)
		{
			for (i=0;i<v;i++) temp=temp->rptr;  //Traversing convieniently to the found node.
			printf("\nThe node is deleted. ");
			(temp->rptr)=temp->rptr->rptr;    
			temp->rptr->lptr=temp;
			return L;
		}
	}
}


//insertion in circular doubly linked list
struct dnode *cdins(struct dnode *L,struct dnode *R,int pos, int *count)
{
	struct dnode *neww;
	neww=(struct dnode*)malloc(sizeof(struct dnode));
	dinput(neww);
	//for an empty doubly linked list
	if(pos < -1)
		{	printf("Invalid location."); return L;	}
	else if ((*count)==0) //if there are no elements
	{
		(*count)++;		
		L=neww;
		R=neww;
		neww->lptr=L;
		neww->rptr=R;
		return L;
	}
	else if (pos==0||pos==-1)  //inserton in the beginning and in the end
	{
		(*count)++;		
		neww->rptr=L;
		neww->lptr=R;
		R->rptr=neww;
		L->lptr=neww;
		if(pos==0)L=neww;
		else R=neww;
		return L;		
	}
	
	else   //insertion in the desired position
	{
		int co=0;
		struct dnode *temp;
		temp=L;
		while (co!=pos)
		{
				co++;
				if(co>(*count)) {	printf("Invalid location, does not exist"); return L;	}
				else
				{
					temp=temp->rptr;
					if(co==pos)
					{  //Insertion process begins here
						(*count)++;						
						neww->lptr=temp;
						neww->rptr=temp->rptr;
						(temp->rptr)->lptr=neww;
						temp->rptr=neww;
						return L;
					}
				}
		}
	}
	printf("BOOHOO ERROR :P");
}

//Display in circular doubly linked list
void csdisp(struct dnode *L, struct dnode *R, int count)
{
	if(count==0) printf("The list is empty.");
	else
	{
		
		struct dnode *temp;       //temporary pointer for traversal
		temp=L;
		int c=0;
		while(c!=count)
		{
			printf("\nThe name: %s",temp->name);
			printf("\nThe roll: %d",temp->roll);
			printf("\nThe CGPA: %d",temp->CGPA);
			temp=temp->rptr; c++;
	 	} 
	}
}


//searching inside a doubly linked list
int cssearch(struct dnode *L ,struct dnode *R , int count)
{
		if(count==0){ printf("\nThe list is empty."); return -1;}
	else 
	{
		struct dnode *temp;
		int co=1,target;
		printf("\nEnter the target roll number:");
		scanf("%d",&target);
		temp=L;
		while(co!=count)
		{
			co++;			
			if(temp->roll==target) 
			{	
				printf("\nThe name: %s",temp->name);
				printf("\nThe roll: %d",temp->roll);
				printf("\nThe CGPA: %d",temp->CGPA);
				printf("\nTarget found at location : %d",co);
				return co;			
			}
			else temp=temp->rptr;
		}
		printf("\nThe node was not found."); return -1;
		
	}
	printf("\nBooHoo babes, there's some error above."); return -1;
}

//deletion inside a doubly linked list
struct dnode *csdele(struct dnode *L, struct dnode *R, int *count)
{
	if(*count==0)
	{
		printf("\nThe list is empty. No deletion can occur here.");
	}
	else
	{
		struct dnode *temp;
		temp= L;
		int v,i;
		v=cssearch(L,R,*count);
		if(v>=0)
		{
			for (i=0;i<v;i++) temp=temp->rptr;  //Traversing convieniently to the found node.
			printf("\nThe node is deleted. ");
			*count--;
			(temp->rptr)=temp->rptr->rptr;    
			temp->rptr->lptr=temp;
			return L;
		}
	}
}


