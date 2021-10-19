#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}*start=NULL, *q,*t;

void display()
{
	printf("\n\n");
    if(start==NULL)
        printf("List is empty");
    else
    {
        q=start;
        printf("The linked list is:\n\n");
        while(q!=NULL)
        {
            printf("%d->",q->data);
            q=q->next;

        }
    }
	printf("\n");
}
int delete()
{
	if (start == NULL)
	{
		printf("\n[UNDDERFLOW]\n");
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
		return 0;
	}
}

int insert(){
	int num;
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	printf("Enter the element:");
	scanf("%d",&num);
	newNode->data = num;
	newNode->next = start;
	start = newNode;
	return 0;
	}
	
void reverse()
{
	struct node* current = (struct node*) malloc(sizeof(struct node));
	struct node* prev = (struct node*) malloc(sizeof(struct node));
	struct node* next = (struct node*) malloc(sizeof(struct node));
	current = start;
	prev = NULL;
	next = NULL;
	while(current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	start = prev;
} 

void main()
{
	int ch='y', dec, pos;
	while(ch=='y')
	{
		printf("   MENU\n");
		printf("1. Insert\n2. Delete\n3. Print\n4. Reverse\n\nenter your choice\n\t");
		scanf("%d",&dec);
		if(dec ==1)
			insert();
		else if(dec == 2)
			delete();
		else if(dec == 3)
			display();
		else if(dec == 4)
			reverse(start);
		else 
			printf("Invalid Choice\n")
		printf("Would you like to continue? (y/n)");
		scanf("%c",&ch);
	}

}