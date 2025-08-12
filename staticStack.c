#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int top=-1,a[MAX];
void push();
void pop();
void disp();
void peek();
void count();
int main(){
	int n;
	printf("\t\t\t\n->Static implementation of Stack<-\n");
	printf("\n Press : \n");
	while(1){
		printf("\n1 for Push \t2 for Pop \t3 to Display Elements\n4 to Peek \t5 to Count \t6 to Exit\n");
		scanf("%d",&n);
		switch(n){
			case 1:{
				push();
				break;
			}
			case 2:{
				pop();
				break;
			}
			case 3:{
				disp();
				break;
			}
			case 4:{
				peek();
				break;
			}
			case 5:{
				count();
				break;
			}

			case 6:{
				exit(0);
				break;
			}
			default:{
				printf("\n\nInvalid entry\n\n");
				break;
			}
		}
	}
}
void push(){
	int el;
	if(top==MAX-1){
		printf("\nStack Overflow\n");
		return;
	}
	else{
		printf("Enter data : ");
		scanf("%d",&el);
		top++;
		a[top]=el;
		
	}
}
void pop(){
		if(top==-1){
			printf("Stack underflow");
		}
		else{
			printf("Data deleted : %d ",a[top]);
			top--;
		}
}
void disp(){
	int i=0;
	if(top==-1){
		printf("\nStack is Empty\n");
		return;
	}
	else{
			printf("\nElements in the Stack are : \n");
		for(i=top;i>=0;i--){
		printf("Data part : %d  Address Part : %u\n",a[i],&a[i]);
		}
	}
}
void peek(){
	if(top==-1){
		printf("\nStack is empty\n");
		return;
	}
	else{
		printf("\nTop element in the stack is : %d\t",a[top]);
	}
}
void count(){
	int c=0,i;
	if(top==-1){
		printf("\nStack is empty\n");
	}
	else{
	for(i=top;i>=0;i--){
		c++;
	}
	printf("Total number of element present in the stack is : %d",c);
	}
}
