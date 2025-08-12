#include<stdio.h>
#include<stdlib.h>
void ifsll();
void iesll();
void dispsll();
void desll();
void dfsll();
void dssll();
void csll();
void imsll();
int search(int n);
struct sll{ 
	struct sll *link;
	int data;	
};
struct sll *start=NULL;
int main(){
	int n;
	printf("\n->Welcome to Singly linked list<-\n");
	printf("\nEnter Choice\n");
	while(1){
		printf("\n1 to Insert at Front \t2 to Insert at End \t3 To Insert in the Middle/Specific Point\n4 to Display\n5 to Delete at Start \t 6 to Delete at End\t7 to Delete by Number\t8 to Count\t9 to Exit\n");
		scanf("%d",&n);
		switch(n){
		case 1:{
				ifsll();
				break;
			}
			case 2:{
				iesll();
				break;
			}
			case 3:{
				imsll();
				break;
			}
			case 4:{
				dispsll();
				break;
			}
			case 5:{
				dfsll();
				break;
			}
			case 6:{
				desll();
				break;
			}
			case 7:{
				dssll();
				break;
			}
			case 8:{
				csll();
				break;
			}
			case 9:{
				exit(0);
				break;
			}
			default:{
				printf("\nInvalid entry\n");
				break;
			}
		}		
	}
}
void ifsll(){
	struct sll *p;
	int el;
	p=(struct sll *)malloc(sizeof(struct sll));
	if(p==NULL){
		printf("\nMemory Not Allocated\n");
		return;
	}
	else{
		printf("\nEnter data : \n");
		scanf("%d",&el);
		p->data=el;
		if(start==NULL){
			p->link=NULL;
			start=p;
		}
		else{
			p->link=start;
			start=p;
		}
	}
}
void iesll(){
	struct sll *p,*q;
	int el;
	p=(struct sll *)malloc(sizeof(struct sll));
	if(p==NULL){
		printf("\nMemory Not Allocated\n");
		return;
	}
	else{
		printf("\nEnter data : \n");
		scanf("%d",&el);
		p->data=el;
		if(start==NULL){
			p->link=NULL;
			start=p;
		}
		else{
			q=start;
			while(q->link!=NULL){
				q=q->link;
			}
			q->link=p;
			p->link=NULL;
		}
	}
}
void dfsll(){
	if(start==NULL){
		printf("\nSll is empty\n");
		return;
	}
	else{
		if(start->link==NULL){
			printf("Data deleted : %d",start->data);
			start=NULL;
		}
		else{
			printf("Data deleted : %d",start->data);
			start=start->link;
		}
	}
}
void desll(){
	struct sll *q;
	if(start==NULL){
		printf("\nSll is empty\n");
		return;
	}
	else{
		if(start->link==NULL){
			printf("Data deleted : %d",start->data);
			start=NULL;
		}
		else{
			q=start;
			while(q->link->link!=NULL){
				q=q->link;
			}
			printf("Data deleted : %d",q->link->data);
			q->link=NULL;
		}
	}
}
void dispsll(){
		struct sll *p;
	if(start==NULL){
		printf("\nSll is empty\n");
		return;
	}
	else{
		p=start;
		while(p->link!=NULL){
			printf("\nAddress of the Link part is : %u \t Data part : %d \t Link part : %u",&p->link,p->data,p->link);	
					p=p->link;
		}
		printf("\nAddress of the Link part is : %u \t Data part : %d \t Link part : %u",&p->link,p->data,p->link);
	}
}


void csll(){
	int c=1;
	struct sll *p;
	if(start==NULL){
		printf("\nSll is Empty\n");
		return;
	}
	else{
		p=start;
		while(p->link!=NULL){
			c++;
			p=p->link;
		}
		printf("\nThe total number of elements in Sll is : %d\n",c);
	}
}
void dssll(){
	int n,s;
	struct sll *r,*q;
	if(start==NULL){
		printf("\nDll is empty\n");
		return;
	}
		dispsll();
		printf("\n\nWhich number do you want to delete?\n");
		scanf("%d",&n);
		s=search(n);
		if(s==1){
			if(start->data==n && start->link==NULL ){
			printf("Data deleted : %d",start->data);
			start=NULL;
			return;
			}
				if(start->data==n){
				printf("Data deleted : %d ",start->data);
				start=start->link;
				return;
				}
				else{
				q=start;
				while(q->link!=NULL){
					if(q->link->data==n){
					printf("Data deleted: %d",q->link->data);
					q->link=q->link->link;
					return;	
					}
				q=q->link;
				}
		}
}
else{
	printf("\nNumber not found\n");
}
 }
int search(int n){
	struct sll *p;
	p=start;
	while(p->link!=NULL){
		if(p->data==n){
			return 1;
		}
		p=p->link;
	}
	if(p->data==n){
		return 1;
	}
	return 0;
}
void imsll(){
	int n,s,el;
	struct sll *r,*q,*p;
	p=(struct sll *)malloc(sizeof(struct sll));
	if(p==NULL){
		printf("\nMemory Not Allocated\n");
		return;
	}
	printf("Enter data:\t");
	scanf("%d",&el);
	p->data=el;
	if(start==NULL){
		p->link=NULL;
		start=p;
		printf("\nData Inserted\n");
		return;
	}
	dispsll();
	printf("\n\n\n\n\nAfter  which node do you want to insert the new node?\n");
	scanf("%d",&n);
		s=search(n);
		if(s==1){
			if(start->data==n && start->link==NULL){
				printf("\nData Inserted\n");
				start->link=p;
				p->link=NULL;
				return;
			}
			else if(start->data==n && start->link!=NULL){
				printf("\nData Inserted\n");
				q=start->link;
				start->link=p;
				p->link=q;
				return;
			}	
				else{
				r=start;
				q=start->link;
				while(r->link!=NULL){
					if(r->data==n){
						r->link=p;
						p->link=q;
					printf("\nData Inserted\n");
					return;
					}
				r=r->link;
				q=q->link;
				}
				if(r->data==n){
						r->link=p;
						p->link=q;
					printf("\nData Inserted\n");
			}
	}
		}else{
	printf("\nNumber not found\n");
}
 }
