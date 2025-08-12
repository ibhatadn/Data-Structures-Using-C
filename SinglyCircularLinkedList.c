#include<stdio.h>
#include<stdlib.h>
void insertscll();
void displayscll();
void insertescll();
void insertsscll();
int search(int n);
void searching();
void greatest();
void deletescll();
void deleteescll();
void deletesscll();
struct scll{
	int data;
	struct scll *next;
};
struct scll *end=NULL;
int main(){
	int n;
	printf("\n\t ->Welcome to a Singly Circular linked list<- \t\n");
	printf("\nEnter Choice\n");
	while(1){
		printf("\n1 to Insert at start \t 2 to insert at End \t 3 to insert at a Specific point \t 4 to Display \n5 to Search for a Node \t 6 to Find the Greatest Nuumber \t 7 to Delete a node at Beginning \n8 to Delete a node at End \t 9 to Delete a node at a specific point \t 10 to Exit\n");
		scanf("%d",&n);
		switch(n){
			case 1:{
				insertscll();
				break;
			}
			case 2:{
				insertescll();
				break;
			}
			case 3:{
				insertsscll();
				break;
			}
			case 4:{
				displayscll();
				break;
			}
			case 5:{
				searching();
				break;
			}
			case 6:{
				greatest();
				break;
			}
			case 7:{
				deletescll();
				break;
			}
			case 8:{
				deleteescll();
				break;
			}
			case 9:{
				deletesscll();
				break;
			}
			case 10:{
				exit(0);
				break;
			}
			default:{
				printf("\nInvalid number\n");
				break;
			}
		
		}
	}
}
void insertscll(){
	int el;
	struct scll *p;
	p=(struct scll *)malloc(sizeof(struct scll));
	if(p==NULL){
		printf("\nMemory not allocated\n");
		return;
	}
	else{
		printf("\nEnter Data: \t ");
		scanf("%d",&el);
		p->data=el;
		if(end==NULL){
			p->next=p;
			end=p;
		}
		else{
			p->next=end->next;
			end->next=p;
		}
	}
}
void insertescll(){
	int el;
	struct scll *p,*q;
	p=(struct scll *)malloc(sizeof(struct scll));
	if(p==NULL){
		printf("\nMemory not allocated\n");
		return;
	}
	else{
		printf("\nEnter Data: \t ");
		scanf("%d",&el);
		p->data=el;
		if(end==NULL){
			p->next=p;
			end=p;
		}
		else{
			q=end->next;
			end->next=p;
			p->next=q;
			end=p;
		}
	}
}
void displayscll(){
	struct scll *p;
	if(end==NULL){
		printf("SCLL is empty");
		return;
	}
	else{
		p=end->next;
		do{
			printf("\nAddress of data part: %d \t  Data part : %d \t Address stored in link part: %u\n",&p->data,p->data,p->next);
			p=p->next;
		}while(p!=end->next);
		printf("\n\nAddress stored in End : %u \t Address stored in End->Next is : %u\n\n",end,end->next);
	}
}

void insertsscll(){
	int el,s,n;
	struct scll *p,*q;
	p=(struct scll *)malloc(sizeof(struct scll));
	if(p==NULL){
		printf("\nMemory not allocated\n");
		return;
	}
	if(end==NULL){
		printf("\nSCLL is empty\n");
		return;
	}
	else{
		printf("\nEnter the Data of the node after which you want to insert a new node: \t");
		scanf("%d",&n);
		s=search(n);
		if(s==1){
		q=end->next;
			printf("\nEnter Data: \t ");
			scanf("%d",&el);
			p->data=el;
		if(end->data==n){
			end->next=p;
			p->next=q;
			end=p;
				return;
				}
			if(end->next->data==n){
				p->next=q->next;
				q->next=p;
			}	
			else{
				while(q->data!=n){
				q=q->next;
				}
				p->next=q->next;
				q->next=p;				
			}
	}else{
		printf("\nNumber Not FOund\n");
		return;
	}
}
}
int search(int n){
	struct scll *s;
	if(end==NULL){
		printf("\nSCLL is empty\n");
		return;
	}                                                                                                                                                                                                                                                               
	else{
		s=end;
	do{
			s=s->next;
			if(s->data==n)
			return 1;
		}while(s!=end);
	return 0;
	}
}
void searching(){
	int a,z;
	if(end==NULL){
		printf("\nSCLL is Empty\n");
		return;
	}
	else{
	printf("\nEnter a number :\n");
	scanf("%d",&z);
	a=search(z);
	if(a==1){
		printf("\nNumber found!\n");
		}
		else{
		printf("\nNumber not found\n");
		}
	}
	}
void greatest(){
	int max;
	struct scll *i;
	if(end==NULL){
		printf("SCLL is empty!");
		return;
	}
	else{
		i=end;
		max=i->data;
		i=i->next;
		while(i!=end){			
			if(max<i->data){
			max=i->data;
		}
		i=i->next;
			}
		}	
		printf("\nThe greatest number in the SC Linked list is : \t %d\n",max);	
	}	
void deletescll(){
	if(end==NULL){
		printf("\nSCLL is empty\n");
		return;
	}
	else{
		if(end==end->next){
			printf("\nData deleted : %d\n",end->data);
			end=NULL;
		}
		else{
			printf("\nData deleted : %d\n",end->next->data);
			end->next=end->next->next;
		}
	}
	
}
void deleteescll(){
	struct scll *p;
	if(end==NULL){
		printf("\nScll is Empty\n");
		return;
	}else{
		if(end->next==end){
			printf("\nData deleted: %d",end->data);
			end=NULL;
			return;
		}
		p=end->next;
		while(p->next!=end){
			p=p->next;
		}
		printf("\nData deleted : %d\n",p->next->data);
		p->next=end->next;
		end=p;
	}
	
}
void deletesscll(){
struct scll *p;
int n,s;
if(end==NULL){
	printf("\nSCLL is empty\n");
	return;
}
else{
	p=end->next;
	printf("\nEnter data of the node you want to delete:\t ");
	scanf("%d",&n);
	s=search(n);
	if(s==1){
		if(end->data==n && end->next==end){
			printf("\nData deleted: %d\n",end->data);
			end=NULL;
			return;
		}
		if(end->data==n){
			while(p->next!=end){
				p=p->next;
			}
			printf("Data deleted: %d",end->data);
			p->next=end->next;
			end=NULL;
			return;
		}
		if(end->next->data==n){
			printf("\nData deleted: %d\n",end->next->data);
			end->next=end->next->next;
			return;
		}
		else{
			p=end->next;
			while(p->next!=end){
				if(p->next->data==n){
					printf("\nData deleted: %d\n",p->next->data);
					p->next=p->next->next;
				}
				p=p->next;
			}
			
		}
	}
	else{
		printf("\nNumber Not Found\n");
	}
}
}
