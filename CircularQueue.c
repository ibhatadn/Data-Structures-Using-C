#include<stdio.h>
#include<stdlib.h>
#define MAX 5 
void enqueue();
void dequeue();
void display();
void count();
int queue[MAX];
int rear=-1,front=-1;
int main(){
	int n;
	printf("\t\t\t->Welcome to Circular Queue implementation using arrays<-\n");
	printf("\nEnter Choice:\n");
	while(1){
		printf("\n1 For Enqueue\t2 For Dequeue\t3 to Display\t4 to Count\t5 to Exit\n");
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
				display();
				break;
			}
			case 4:{
				count();
				break;
			}
			case 5:{
				exit(0);
				break;
			}
		}
	}
}
void enqueue(){
	int el;
	if(front==0 && rear==MAX-1 || front==(rear+1)%MAX){
		printf("\nCircular Queue is full\n");
		return;
	}
	else{
		printf("\nEnter Data:\n");
		scanf("%d",&el);
		if(front==-1 && rear==-1){
			front=0;
			rear=0;
			queue[rear]=el;
		}
		else{
		rear=(rear+1)%MAX;
		queue[rear]=el;
	}
	}
}
void dequeue(){
	if(front==-1 || rear==-1){
		printf("\nCircular Queue Underflow\n");
		return;
	}
	else if(front==rear){
		printf("\nData deleted: %d\n",queue[front]);
		front=-1;
		rear=-1;
	}
	else{
		printf("\nData deleted: %d\n",queue[front]);
		front=(front+1)%MAX;
	}
}
void display(){
	int i;
	if(front==-1 && rear==-1){
		printf("\nCircular Queue is Empty\n");
		return;
	}
	else{
		i=front;
		printf("Elements in the Circular Queue are :\t");
		while(i!=rear){
			printf(" %d",queue[i]);
			i=(i+1)%MAX;
		}
		printf(" %d",queue[i]);
	}
}
void count(){
	int c=1,i=front;
	if(front==-1){
		printf("\nQueue is empty\n");
		return;
	}
	else{
		while(i!=rear){
			c++;
			i=(i+1)%MAX;
		}
		printf("\nThe number of elements in Circular Queue is: %d\n",c);
	}
}
