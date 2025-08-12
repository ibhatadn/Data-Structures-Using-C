#include<stdio.h>
#include<stdlib.h>
void pop();
void push();
void disp();
void peek();
void count();
struct stack{
	int data;
	struct stack *link;
};
struct stack *top=NULL;
int main(){
	int n;
	printf("\t\t\t->Dynamic Implementation of Stack<-\n\n");
	printf("\nEnter choice\n");
	while(1){
		printf("\n1 for Push \t2 for Pop \t3 to Display \t4 to Peek \t5 to Count \t6 to Exit\n");
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
				printf("\nInvalid entry\n");
				break;
			}
		}
	}
}
void push(){
	struct stack *p;
	int el;
	p=(struct stack*)malloc(sizeof(struct stack));
	if(p==NULL){
		printf("\nMemory not Allocated\n");
 		return;	
	}
	else{
		printf("\nEnter data : \n");
		scanf("%d",&el);
		p->data=el;
		if(top==NULL){
			p->link=NULL;
			top=p;
		}
		else{
			p->link=top;
			top=p;
		
		}
	}
	
}
void pop(){
	if(top==NULL){
		printf("\nStack underflow\n");
		return;
	}
	else{
		printf("\nData deleted : %d \n",top->data);
		top=top->link;
	}
}
void disp(){
	struct stack *p;
	if(top==NULL){
		printf("\nStack is empty\n");
		return;
	}
	else{
		p=top;
		while(p->link!=NULL){
			printf("\nData part is : %d Link part is : %u\n",p->data,p->link);
			p=p->link;
		}
		printf("\nData part is : %d Link part is : %u\n",p->data,p->link);		
	}
}
void peek(){
	if(top==NULL){
		printf("\nStack is empty\n");
		return;
	}
	else{
		printf("\nThe top element in the stack : %d",top->data);
	}
}
void count(){
	int c=1;
	struct stack *p;
	if(top==NULL){
		printf("\nStack is empty\n");
		return;
	}
	else{
		p=top;
		while(p->link!=NULL){
			c++;
			p=p->link;
		}
		printf("\nTotal number of elements in the stack is : %d\n",c);
	}
}
