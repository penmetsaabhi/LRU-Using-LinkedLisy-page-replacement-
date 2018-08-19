#include<stdio.h>
#include<stdlib.h>
static fsize=0;
int e=0,hit=0,fal=0;

struct node {
	int val,c;
	struct node *next;
};
int insert(struct node **head,int val){
	int k=0;
	struct node *newnode,*ptr=*head,*q;
	newnode=(struct node*)malloc(sizeof(struct node));
	int f=0;
	newnode->val=val;
	if(*head==NULL){
		newnode->c=1;
		newnode->next=NULL;
		*head=newnode;
	}
	else{
		while(ptr!=NULL && f==0){
			if(ptr->val==val){
				(ptr->c)++;
				f=1;
				k=1;
			}
			q=ptr;
			ptr=ptr->next;
			
		}
		if(f==0){
			newnode->c=1;
			newnode->next=NULL;
			q->next=newnode;
		}
	}
	return k;
}
void insertlast(struct node **head,int val,int c){
	struct node *ptr=*head,*newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->val=val;
	newnode->c=c;
	newnode->next=NULL;
	while(ptr->next!=NULL){
		ptr=ptr->next;		
	}
	ptr->next=newnode;
}
void premove(struct node **head,int val){
	struct node *ptr=*head,*preptr;
	if(ptr->val==val){
		ptr=ptr->next;
		*head=ptr;
	}
	else{
		while(ptr->next!=NULL){
			if(ptr->val==val){
				break;
			}
			preptr=ptr;
			ptr=ptr->next;
		}
		if(ptr->next==NULL){
			preptr->next=NULL;
		}
		else{
			preptr->next=ptr->next;
		}
	}
}
int lfu(struct node **head1,struct node **head2,int val){
	struct node *ptr1=*head1,*ptr2=*head2,*newnode;
	int p,min=100,k=0;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->val=val;
	int f=0;
	while(ptr2!=NULL){
		if(ptr2->val==val){
			f=1;
			k=1;
			(ptr2->c)++;
			newnode->c=ptr2->c;
			break;
		}
		ptr2=ptr2->next;
	}
	ptr2=*head2;
	if(f==1){
		premove(head2,val);
		insertlast(head2,val,newnode->c);
		while(ptr1!=NULL){
			if(ptr1->val==val){
				ptr1->c++;
				break;
			}
			ptr1=ptr1->next;
		}
		
	}
	else{
		ptr2=*head2;
		ptr1=*head1;
		while(ptr2!=NULL){
			if(min>ptr2->c){
			p=ptr2->val;
			min=ptr2->c;	
			}	
			ptr2=ptr2->next;	
		}
		premove(head2,p);
		while(ptr1!=NULL){
			if(ptr1->val==val){
				ptr1->c++;
				f=1;
				newnode->c=ptr1->c;
				break;
			}
			ptr1=ptr1->next;
		}
		if(f==1){
			insertlast(head2,val,newnode->c);
		}else{
			insertlast(head2,val,1);
		}
	}
	return k;
}
void display(struct node **head){
	struct node *ptr=*head;
	while(ptr!=NULL){
		printf("%d %d\n",ptr->val,ptr->c);
		ptr=ptr->next;
	}
}
int  main(){
	int c,val,k;
	struct node *head=NULL,*head2=NULL;
	while(1){
		printf("Choose from the below options\n");
		printf("1.insert 2.display 3.Increment of Frame size 4.hist&faults 5.exit\n");
		scanf("%d",&c);
		switch(c){
			case 1:
				printf("Enter a value:");
				scanf("%d",&val);
				if(head==NULL){
					printf("Enter Frame size:");
					scanf("%d",&fsize);
				}
				if(e==fsize){
					k=lfu(&head,&head2,val);
					if(k==1){
						hit++;
					}else{
						fal++;
					}
				}
				else{
				k=insert(&head,val);
				k=insert(&head2,val);
				if(k==1){
						hit++;
					}else{
						fal++;
						e++;
					}
				}
				break;
			case 2:
				display(&head2);
				break;
			case 5:
				return 0;
			case 3:
				fsize=fsize+1;
				break;
			case 4:
				printf("%d %d\n",hit,fal);
			default:
				printf("Enter Numbers 1-4");
				
		}
	}
}
