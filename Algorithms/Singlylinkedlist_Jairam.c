#include<stdio.h>
struct node
{
	int data;
	struct node *next;
}*start=NULL,*q,*t;
void display()
{	
	printf("\n\n");
    if(start==NULL)
    {
        printf("List is empty");
    }
    else
    {
        q=start;
        printf("The linked list is:\n");
        while(q!=NULL)
        {
            printf("%d->",q->data);
            q=q->next;
        }
    }
	printf("\n\n");
}
void insertBeg(){
	int num;
	t = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the element: ");
	scanf("%d",&num);
	t->data=num;
	if (start == NULL)
	{
		t->next = NULL;
		start = t;
	}
	else
	{
		t->next = start;
		start=t;
	}
	printf("element inserted at begining is\n");
	display();
}
int insertMid()
{
	int pos,i,no;
	if(start == NULL)
	{
	printf("The list is EMPTY!\n");
	return 0;	
	}
	t = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the element: ");
	scanf("%d",&no);
	printf("\nEnter the position! ");
	scanf("%d",&pos);
	t->data = no;
	q = start;
	for(i=0;i<pos-1;i++){
		if(q->next ==NULL){
			printf("\nOVERFLOW!");
			return 0;
		}
		q=q->next;
	}
	t->next = q->next;
	q->next = t;
	printf("Element inserted at the middle!\n");
}
void insertEnd()
{
    int num;
    t=(struct node*)malloc(sizeof(struct node));
   	 printf("Enter info:");
   	 scanf("%d",&num);
   	 t->data=num;
   	 t->next=NULL;
   	 if(start==NULL)       
        		start=t;
    	else
    	{
        	q=start;
        	while(q->next!=NULL)
				q=q->next;
       		 q->next=t;
    	}
	printf("element inserted at the end!\n");
}

int delete()
{
	if (start == NULL)
	{
		printf("\nThe list is EMPTY! [UNDDERFLOW!]\n");
		return 0;
	}
	else
	{
		q = start;
		while(q->next->next !=NULL)
			q = q->next;
		t = q->next;
		q->next = NULL;
		printf("Deleted element is: %d\n",t->data);
	}
}
void main()
{
	int ch='y', action, pos;
	while(ch=='y')
	{
		printf("\t\t\tMAIN MENU\n\n");
		printf("1. Insert\n2. Delete\n3. Print\n\nenter the option number!\n\t");
		scanf("%d",&action);
		if(action ==1)
		{
			printf("From where would you like to insert?\n");
			printf("1. Begining \n2. Middle \n3. End\n");
			scanf("%d",&pos);
			if(pos==1)
				insertBeg();
			else if(pos==2)
				insertMid();
			else if(pos==3)
				insertEnd();
			else 
				printf("Invalid choice");
		}
		else if(action == 2)
			delete();
		else if(action == 3)
			display();
		else 
				printf("Invalid choice");
		printf("Would you like to continue (y/n)");
		scanf("%c",&ch);
	}
}