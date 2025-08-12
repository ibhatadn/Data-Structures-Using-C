#include<stdio.h>
#include<stdlib.h>
void ifdll();
void iedll();
void dfdll();
void dedll();
void deledll();
void deleftdll();
void delsdll();
void countdll();
int search(int n);
struct dll{
	struct dll *left;
	int data;
	struct dll *right;
};
struct dll *start=NULL,*end=NULL;
int main(){
	int n;
	printf("\n->Welcome to Doubly Linked list<-\n");
	printf("\nEnter choice : \n");
	while(1){
		printf("\n1 to insert at front \t2 to insert at end \t3 to display from front \t4 to display from end\n5 to delete from front\t6 to delete from end\t7 to deleted by Number\t\t8 to count \t\t9 to exit\n");
		scanf("%d",&n);
		switch(n){
			case 1:{
				ifdll();
				break;
			}
			case 2:{
				iedll();
				break;
			}
			case 3:{
				dfdll();
				break;
			}
			case 4:{
				dedll();
				break;
			}
			case 5:{
				deleftdll();
				break;
			}
			case 6:{
				deledll();
				break;
			}
			case 7:{
				delsdll();
				break;
			}
			case 8:{
				countdll();
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
void ifdll(){
	struct dll *p;
	int el;
	p=(struct dll*)malloc(sizeof(struct dll));
	if(p==NULL){
		printf("\nMemory not allocated\n");
		return;
	}
	else{
		printf("\nEnter data : \t");
		scanf("%d",&el);
		p->data=el;
		p->left=NULL;
		if(start==NULL){
			p->right=NULL;
			start=p;
			end=p;
		}
		else{
			p->right=start;
			start->left=p;
			start=p;

		}
		}
}
void iedll(){
	struct dll *p;
	int el;
	p=(struct dll*)malloc(sizeof(struct dll));
	if(p==NULL){
		printf("\nMemory not allocated\n");
		return;
	}
	else{
		printf("\nEnter data : \n");
		scanf("%d",&el);
		p->data=el;
		p->right=NULL;
		if(start==NULL){
			p->left=NULL;
			start=p;
			end=p;
		}
		else{
			end->right=p;
			p->left=end;
			end=p;
		}
		}
	
}
void dfdll(){
	struct dll *p;
	if(start==NULL){
		printf("\n DLL is empty\n");
		return;
	}
	else{
		p=start;
		printf("\nThe address stored in start is : %u\n",start);
		printf("\nThe address stored in end is : %u\n",end);
		while(p->right!=NULL){
			printf("\n\nThe Address of the left link part is : %u\t\tThe data stored in the left link part is : %u\n\nThe Data part is : %d \t\t\t\t\tThe address of data part is : %u\n\nThe address of the right link part is : %u\t\tThe data stored in the right link part is : %u\n",&p->left,p->left,p->data,&p->data,&p->right,p->right);
			p=p->right;
		}
		printf("\n\nThe Address of the left link part is : %u\t\tThe data stored in the left link part is : %u\n\nThe Data part is : %d \t\t\t\t\tThe address of data part is : %u\n\nThe address of the right link part is : %u\t\tThe data stored in the right link part is : %u\n\n ",&p->left,p->left,p->data,&p->data,&p->right,p->right);
	}
}
void dedll(){
struct dll *p;
	if(start==NULL){
		printf("\n DLL is empty\n");
		return;
	}
	else{
		p=end;
		printf("\nThe address stored in start is : %u\n",start);
		printf("\nThe address stored in end is : %u\n",end);
		while(p->left!=NULL){
			printf("\n\nThe Address of the left link part is : %u\t\tThe data stored in the left link part is : %u\n\nThe Data part is : %d \t\t\t\t\tThe address of data part is : %u\n\nThe address of the right link part is : %u\t\tThe data stored in the right link part is : %u\n",&p->left,p->left,p->data,&p->data,&p->right,p->right);
			p=p->left;
		}
		printf("\n\nThe Address of the left link part is : %u\t\tThe data stored in the left link part is : %u\n\nThe Data part is : %d \t\t\t\t\tThe address of data part is : %u\n\nThe address of the right link part is : %u\t\tThe data stored in the right link part is : %u\n\n ",&p->left,p->left,p->data,&p->data,&p->right,p->right);
	}
	
}
void deleftdll(){
	if(start==NULL){
		printf("\nDll is empty\n");
		return;
	}
	else{
		if(start->right==NULL){
			printf("Element deleted : %d",start->data);
			start=NULL;
			end=NULL;
		}
		else{
		printf("Data deleted : %d ",start->data);
		start=start->right;
		start->left=NULL;
}
	}
	
}
void deledll(){
	if(start==NULL){
		printf("\nDll is empty\n");
		return;
	}
	else{
		if(end->left==NULL){
			printf("Element deleted : %d",end->data);
			start=NULL;
			end=NULL;
		}
			else{
			printf("Data deleted : %d ",end->data);
		end=end->left;
		end->right=NULL;
			}
	}
	
}
void delsdll(){
	int n,s;
	struct dll *p,*q;
	if(start==NULL){
		printf("\nDll is empty\n");
		return;
	}
		dfdll();
		printf("\n\nWhich number do you want to delete?\n");
		scanf("%d",&n);
		s=search(n);
		if(s==1){
		if(start->data==n && start->right==NULL){
			printf("\nData deleted : %d\n",start->data);
			start=NULL;
			end=NULL;
			return;
		}
		if(start->data==n){
			printf("\nData deleted : %d\n",start->data);
			start=start->right;
			start->left=NULL;
			return;
		}
		if(end->data==n){
			printf("\nData deleted : %d\n",end->data);
			end=end->left;
			end->right=NULL;
		}
		else{
			p=start->right->right;
			q=start;
			while(q->right->data!=n){
				q=q->right;
				p=p->right;
			}		
			printf("\n Data deleted : %d\n",q->right->data);
			p->left=q;
			q->right=p;
	}
	}else{
		printf("\nNumber not found\n");
	}
}
void countdll(){
	int count=1;
	struct dll *p;
	if(start==NULL){
		printf("\nDll is empty\n");
	}
	else{
		p=start;
	while(p->right!=NULL){
		count++;
		p=p->right;
	}
	printf("The number of elements in DLL is :%d",count);
}
}
int search(int n){
	struct dll *z;
	z=start;
	while(z->right!=NULL){
		if(z->data==n){
			return 1;
		}
		z=z->right;
	}
	if(z->data==n){
		return 1;
	}
	return 0;
}


