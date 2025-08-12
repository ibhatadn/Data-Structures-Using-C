#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int arr[MAX];
int f=-1,r=-1,i=0;
void enqueue();
void dequeue();
void displayqueue();
void rear();
void Count();
void front();
int main(){
	int choice;
	printf("\nEnter choice :\n");
	while(1){
		printf("\n1 for Enqueue \t2 for Dequeue \t3 for Display\t 4 for Display Front \t 5 to Dislay rear \t 6 to Count \t 7 to Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:{
			enqueue();
				break;
			}
			case 2:{
			dequeue();
				break;
			}
			case 3:{
			displayqueue();	
				break;
			}
			case 4:{
			front();
				break;
			}
			case 5:{
				rear();
				break;
			}
			
			case 6:{
				Count();
				break;
			}
			case 7:{
				exit(0);	
				break;
			}
			default:{
				printf("\nInvalid entry!\n");
				break;
			}
		}
	}
}
void enqueue(){
	int el;
	if(r==MAX-1){
		printf("\nQueue is full\n");
		return;
	}
	else{
		printf("\nEnter data :\t ");
		scanf("%d",&el);
		if(r==-1 || f==-1){
		f=0;
		r=0;
		arr[r]=el;
	}
	else{
		r++;
		arr[r]=el;	
		}
}
}
void dequeue(){
	if(r==-1 || f==-1){
		printf("\nQueue is Empty\n");
		return;
	}
	else{
	if(r==f){
	printf("\nElement deleted : %d\n",arr[f]);
	f=-1;
	r=-1;
}
	else{
		printf("\nElement deleted : %d\n",arr[f]);
		f++;
}	
}
}
void displayqueue(){
	if(f==-1 || r==-1){
		printf("\nQueue is empty!\n");
	}
	else{
	for(i=f;i<=r;i++){
		printf("\nData Part is : %d Address Part is : %u\n",arr[i],&arr[i]);
	}
}
}
void rear(){
	if(f==-1 || r==-1){
		printf("\nQueue is empty!\n");
		}else{
	printf("\n The rear element  in the Queue is : %d\n",arr[r]);
}
}
void Count(){
	int	count=0;
	if(r==-1 || f==-1){
		printf("\nQueue is empty\n");
	}
	else{
		for(i=f;i<=r;i++){
			count++;
		}
	printf("\nThe number of elements present in queue is : %d\n",count);
}
}
void front(){
	if(f==-1 || r==-1){
		printf("\nQueue is empty!\n");
		}else{
	printf("\n The Front element in the Queue is : %d\n",arr[f]);
}
}

