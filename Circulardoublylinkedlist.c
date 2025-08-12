#include<stdio.h>
#include<stdlib.h>
struct cdll{
	struct cdll *lf;
	int data ;
	struct cdll *rl;
};
struct cdll *end=NULL;
void insertfcdll();
void insertecdll();
void insertscdll();
void deletefcdll();
void deleteecdll();
void deletescdll();
void displayscdll();
void displayecdll();
void countcdll();
void search();
int searching(int n);
int main(){
	int n;
	printf("\t\t\t->Welcome to Circular Doubly Linked list<-\n");
	printf("\nEnter Choice\n");
	while(1){
		printf("\n1 to Insert at start \t2 to Insert at end \t3 to insert at a specific point \t4 to Delete at start \n5 to Delete at end \t6 to Delete at a specific point \t7 to Display from Start \n8 to Display from End \t9 To count \t10 to search for a Node \t11 to Exit\n");
		scanf("%d",&n);
		switch(n){
			case 1:{
				insertfcdll();
				break;
			}
			case 2:{
				insertecdll();
				break;
			}
			case 3:{
				insertscdll();
				break;
			}
			case 4:{
				deletefcdll();
				break;
			}
			case 5:{
				deleteecdll();
				break;
			}
			case 6:{
				deletescdll();
				break;
			}
			case 7:{
				displayscdll();
				break;
			}
			case 8:{
				displayecdll();
				break;
			}
			case 9:{
				countcdll();
				break;
			}
			case 10:{
				search();
				break;
			}
			case 11:{
				exit(0);
				break;
			}
			default:{
				printf("\n\nInvalid Entry\n\n");
				break;
			}
		}
		
	}	
}
void insertfcdll(){
	 struct cdll *p,*q;
	 int el;
	 p=(struct cdll *)malloc(sizeof(struct cdll));
	 if(p==NULL){
	 	printf("\nMemory not Allocated\n");
	 }
	 printf("\nEnter Data:\t");
	 scanf("%d",&el);
	 p->data=el;
	 if(end==NULL){
	 	p->lf=p;
	 	p->rl=p;
	 	end=p;
	 }
	 else{
	 	q=end->rl;
		 p->rl=q;
		 q->lf=p;
		 p->lf=end;
		 end->rl=p;
	 }
}
void insertecdll(){
	int el;
	struct cdll *p,*q;
	p=(struct cdll *)malloc(sizeof(struct cdll));
	if(p==NULL){
		printf("\nMemory Not allocated\n");
		return;
	}
	printf("\nEnter data:\t");
	scanf("%d",&el);
	p->data=el;
	if(end==NULL){
		p->lf=p;
		p->rl=p;
		end=p;
	}
	else{
		q=end->rl;
		p->lf=end;
		end->rl=p;
		p->rl=q;
		q->lf=p;
		end=p;
	}
}
void insertscdll(){
	int n,el,s;
	struct cdll *p,*q,*r;
	p=(struct cdll *)malloc(sizeof(struct cdll));
	if(p==NULL){
		printf("\nMemory Not Allocated\n");
		return;
	}
	if(end==NULL){
			printf("\nCDLL is Empty\n");
			return;
		}
	else{
	printf("\nEnter data of the Node after which you want to insert data:\t");
	scanf("%d",&n);
	s=searching(n);
	if(s==1){
		printf("\nEnter data:\t");
		scanf("%d",&el);
		p->data=el;
		if(end->data==n && end->lf==end && end->rl==end){
			p->lf=end;
			end->rl=p;
			p->rl=end;
			end->lf=p;
			end=p;
			return;
		}
		if(end->data==n){
			q=end->rl;
			p->lf=end;
			end->rl=p;
			p->rl=q;
			q->lf=p;
			end=p;
			return;
			}
		else{
			q=end->rl;
			r=end->rl->rl;
			while(q->data!=n){
				q=q->rl;
				r=r->rl;
			}
			p->lf=q;
			p->rl=r;
			r->lf=p;
			q->rl=p;
			
		}
	}
	else{
		printf("\nNumber not FOund\n");
		return;
	}
	}
}
void deletefcdll(){
	if(end==NULL){
	printf("\nCDLL is empty\n");
	return;
}
else{
	if(end->lf==end && end->rl==end){
		printf("\nData Deleted: %d",end->data);
		end=NULL;
	}
	else{
	printf("\nData deleted: %d\n",end->rl->data);
	end->rl=end->rl->rl;
	end->rl->lf=end;
}
}
}
void deleteecdll(){
	struct cdll *p;
	if(end==NULL){
		printf("\nCDLL is Empty\n");
		return;
	}
	else{
		if(end->lf==end && end->rl==end){
			printf("\nData Deleted: %d\n",end->data);
			return;
		}
		else{
			printf("Data deleted: %d",end->data);
			p=end->rl;
			end=end->lf;
			end->rl=p;
			p->lf=end;
		}
	}
}
void deletescdll(){
	struct cdll *p,*q;
	int s,n;
	if(end==NULL){
		printf("\nCDLL is Empty\n");
		return;
	}
	else{
		printf("\nEnter data of the node you want to delete:\t");
		scanf("%d",&n);
		s=searching(n);
		if(s==1){
			if(end->data==n && end->rl==end && end->lf==end){
				printf("\nData deleted: %d\n",end->data);
				end=NULL;
				return;
			}
			if(end->data==n){
				p=end->rl;
				printf("\nData deleted: %d\n",end->data);
				end=end->lf;
				end->rl=p;
				p->lf=end;
				return;
			}
			if(end->rl->data==n){
				printf("\nData deleted: %d\n",end->rl->data);
				end->rl=end->rl->rl;
				end->rl->lf=end;
				return;
			}
			else{
				p=end->rl;
				q=end->rl->rl->rl;
				while(p->rl->data!=n){
					p=p->rl;
					q=q->rl;
				}
				printf("\nData deleted: %d\n",p->rl->data);
				p->rl=q;
				q->lf=p;
				
			}
		}else{
			printf("\nNumber Not found\n");
		}
	}
}
void displayscdll(){
	struct cdll *p;
	if(end==NULL){
		printf("\nCDLL is empty\b");
		return;
	}
	else{
		p=end->rl;
		printf("\nAddress stored in end is: %u\n",end);
		while(p->rl!=end->rl){
			printf("\nAddress of Left Link part is : %u \t Value stored in the Left link part is:%u\nData part is : %d \t Address of data part is: %u \nAddress of Right Link part is : %u \t Value stored in the Right link part is:%u\n",&p->lf,p->lf,p->data,&p->data,&p->rl,p->rl);
			p=p->rl;
		}
			printf("\nAddress of Left Link part is : %u \t Value stored in the Left link part is:%u\nData part is : %d \t Address of data part is: %u \nAddress of Right Link part is : %u \t Value stored in the Right link part is:%u\n",&p->lf,p->lf,p->data,&p->data,&p->rl,p->rl);
	}
	
}
void displayecdll(){
	struct cdll *p;
	if(end==NULL){
		printf("\nCDLL is empty\b");
		return;
	}
	else{
		p=end;
		printf("\nAddress stored in end is: %u\n",end);
		while(p->lf!=end){
			printf("\nAddress of Left Link part is : %u \t Value stored in the Left link part is:%u\nData part is : %d \t Address of data part is: %u \nAddress of Right Link part is : %u \t Value stored in the Right link part is:%u\n",&p->lf,p->lf,p->data,&p->data,&p->rl,p->rl);
			p=p->lf;
		}
			printf("\nAddress of Left Link part is : %u \t Value stored in the Left link part is:%u\nData part is : %d \t Address of data part is: %u \nAddress of Right Link part is : %u \t Value stored in the Right link part is:%u\n",&p->lf,p->lf,p->data,&p->data,&p->rl,p->rl);
	}
	
}
void countcdll(){
	struct cdll *p;
	int c=1;
	if(end==NULL){
		printf("\nCDLL is Empty\n");
		return;
	}
	else{
		p=end->rl;
		while(p->rl!=end->rl){
			c++;
			p=p->rl;
		}
		printf("\nThe number of elements in the CDLL is : %d\n",c);
	}
	
}
void search(){
	int n,s;
	if(end==NULL){
		printf("\nCDLL is empty\n");
		return;
	}
	else{
		printf("\nEnter data of the node you want to find:\t");
		scanf("%d",&n);
		s=searching(n);
		if(s==1){
			printf("\nNumber found\n");
		}
		else{
			printf("\nNumber not found\n");
		}
	}
}
int searching(int n){
	struct cdll *p=end->rl;
	while(p->rl!=end->rl){
		if(p->data==n){
			return 1;
		}
		p=p->rl;
	}
	if(p->data==n){
		return 1;
	}
	else{
		return 0;
	}
}
