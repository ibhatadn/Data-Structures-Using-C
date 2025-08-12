#include<stdio.h>
#include<stdlib.h>
void enqueue();
void dequeue();
void disp();
void count();
void peek();
void Rear();
void Front();
struct queue{ 
	struct queue *link;
	int data;
};
struct queue *front=NULL, *rear=NULL;
int main(){
	int n;
	printf("\n->Dynamic Queue<-\n");
	printf("\nEnter Choice\n");
	while(1){
		printf("\n1 to Enqueue \t2 to Dequeue \t3 to Display \n4 to Count \t5 for Front \t6 for Rear \t7 to Exit\n");
		scanf("%d",&n);
		switch(n){
		case 1:{
			enqueue();
			break;
			}
		case 2:{
			dequeue();
			break;
			}
		case 3:{
			disp();
			break;
			}
		case 4:{
			count();
			break;
			}
		case 5:{
			Front();
			break;
			}
		case 6:{
			Rear();
			break;
			}
		case 7:{
			exit(0);
			break;
			}
		default:{
			printf("\n!Invalid Entry\n");
			break;
			}
		}		
	}
}
void enqueue(){
	struct queue *p;
	int el;
	p=(struct queue *)malloc(sizeof(struct queue));
	if(p==NULL){
		printf("\nMemory Not Allocated\n");
		return;
	}
	else{
		printf("\nEnter data : \n");
		scanf("%d",&el);
		p->data=el;
		if(front==NULL){
			p->link=NULL;
			front=p;
			rear=p;
		}
		else{
		rear->link=p;
		rear=p;
		rear->link=NULL;			
		
		}
	}
}
void dequeue(){
	if(front==NULL){
		printf("\nQueue is empty\n");
		return;
	}
	else{
		if(front->link==NULL){
			printf("\nData deleted :%d",front->data);
			front=NULL;
			rear=NULL;
		}
		else{
		printf("\nData deleted :%d",front->data);
		front=front->link;
	}
	}
}
void disp(){
	struct queue *p;
	if(front==NULL){
		printf("\nQueue is empty\n");
		return;
	}
	else{
		p=front;
		while(p->link!=NULL){
			printf("\nData part : %d\t Link part : %u",p->data,p->link);
			p=p->link;
		}
		printf("\nData part : %d\t Link part : %u",p->data,p->link);
	}
}
void count(){
	int c=1;
	struct queue *p;
	if(front==NULL){
		printf("\nQueue is Empty\n");
		return;
	}
	else{
		p=front;
		while(p->link!=NULL){
			c++;
			p=p->link;
		}
		printf("The total number of elements in queue is : %d",c);
	}
}
void Rear(){
	if(front==NULL){
		printf("\nQueue is empty\n");
		return;
	}
	else{
		printf("\nRear element is  : %d\t with Link part : %u\n",rear->data,rear->link);
	}
}
void Front(){
	if(front==NULL){
		printf("\nQueue is empty\n");
		return;
	}
	else{
		printf("\nFront element is  : %d\t with Link part : %u\n",front->data,front->link);
	}
}
