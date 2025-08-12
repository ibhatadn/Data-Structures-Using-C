#include<stdio.h>
#include<stdlib.h>
struct bst{
	struct bst *LL;
	int data;
	struct bst *RL;
};
int f=0;
struct bst *root=NULL,*t=NULL,*stalker=NULL,*succ=NULL;
void insert_bst();
void inorder_bst(struct bst *);
void preorder_bst(struct bst *);
void postorder_bst(struct bst *);
int search_bst(struct bst *,int);
void delete_bst(struct bst *,int);
int count_bst(struct bst *);
void Minel(struct bst *);
void Maxel(struct bst *);
struct bst *inorder_successor(struct bst *t);
void delete_bstmin(struct bst *t);
void modify_bst(struct bst *,int,int);
int main(){
	int n,el;
	printf("\nEnter choice:\n");
	while(1){
		printf("\n\n1 for Insertion \t 2 for Deletion \t 3 to Modify \t 4 for inorder display \n5 for preorder display \t 6 for postorder display \t 7 To search \t 8 to Count \n9 to Find Maximum element \t 10 to Find the Minimum Element \t 11 to Exit\n\n");
		scanf("%d",&n);
		printf("\n");
		switch(n){
			case 1:{
				insert_bst();
				break;
			}
			case 2:{
				t=root;
				if(root==NULL){
					printf("\n\nBinary Search Tree is empty\n\n");
					break;
				}
				printf("\nEnter data of the Node you want to delete:\t");
				scanf("%d",&el);
				search_bst(t,el);
				if(f==0){
					printf("\nNumber Not Found\n");
				}
				else{
					t=root;
					delete_bst(t,el);
					f=0;
				}
				break;
			}
			case 3:{
						if(root==NULL){
					printf("\n\nBinary Search Tree is Empty\n\n");
					break;
				}
				int d;
				t=root;
				printf("\nEnter data of the Node you want to modify:\t");
				scanf("%d",&el);
				printf("\nEnter the data with which you want to modify it:\t");
				scanf("%d",&d);
				modify_bst(t,el,d);
				break;
			}
			case 4:{
					if(root==NULL){
					printf("\n\nBinary Search Tree is Empty\n\n");
					break;
				}
				t=root;
				inorder_bst(t);
				break;
			}
			case 5:{
					if(root==NULL){
					printf("\n\nBinary Search Tree is empty\n\n");
					break;
				}
				t=root;
				preorder_bst(t);
				break;
			}
			case 6:{
					if(root==NULL){
					printf("\n\nBinary Search Tree is empty\n\n");
					break;
				}
				t=root;
				postorder_bst(t);
				break;
			}
			case 7:{
				if(root==NULL){
					printf("\n\nBinary Search Tree is empty\n\n");
					break;
				}
				t=root;
				printf("\nEnter Data:\t");
				scanf("%d",&el);
				search_bst(t,el);
				if(f==0){
					printf("\nNumber Not Found\n");
				}
				else{
					printf("\nNumber Found\n");
					f=0;
				}
				break;
			}
			case 8:{
				int c;
				t=root;
				if(root==NULL){
					printf("\nBinary Search Tree is empty\n");
					break;
				}
				c=count_bst(t);
				printf("\nThe number of nodes in the Binary Search Tree are: %d\n",c);
				break;
			}
			case 9:{
				if(root==NULL){
					printf("\nBinary Search Tree is Empty\n");
					break;
				}
				t=root;
				Maxel(t);
				break;
			}
			case 10:{
				if(root==NULL){
					printf("\nBinary Search Tree is Empty\n");
					break;
				}
				t=root;
				Minel(t);
				break;
			}
			case 11:{
				exit(0);
				break;
			}
			default:{
				printf("\nInvalid Entry\n");
				break;
			}
		}
	}
}
void insert_bst(){
	int el;
	struct bst *p,*pre,*cur;
	p=(struct bst *)malloc(sizeof(struct bst));
	if(p==NULL){
		printf("\nMemory Not Allocated\n");
		return;
	}
	else{
		printf("\nEnter Data:\t");
		scanf("%d",&el);
		p->data=el;
		p->LL=NULL;
		p->RL=NULL;
		if(root==NULL){
			root=p;
		}
		else{
			cur=root;
			while(cur!=NULL){
				pre=cur;
				if(el==cur->data){
					printf("\nInsertion of Duplicate Data Not Allowed\n");
					return;
				}
				else if(el<cur->data){
					cur=cur->LL;
				}else{
					cur=cur->RL;
				}
			}
			if(el<pre->data){
				pre->LL=p;
			}else{
				pre->RL=p;
			}
		}
	}
}
void delete_bst(struct bst *t,int value){
	if(t==NULL){
		return;
	}
	if(value>t->data){
		stalker=t;
		delete_bst(t->RL,value);
	}
	if(value<t->data){
		stalker=t;
		delete_bst(t->LL,value);
	}
	else{
		if(root->data==value){
			if(root->LL==NULL && root->RL==NULL){
				printf("\nNode with data: \t %d deleted\n",root->data);
				root=NULL;
				return;
			}
			else if(root->LL==NULL && root->RL!=NULL){
				printf("\nNode with data: \t %d deleted\n",root->data);				
				root=root->RL;
				return;
			}
			else if(root->RL==NULL && root->LL!=NULL){
				printf("\nNode with data: \t %d deleted\n",root->data);
				root=root->LL;
				return;
			}
			else{
				inorder_successor(root->RL);
				printf("\nData replaced r with: %d\n",succ->data);
				root->data=succ->data;
				delete_bstmin(root->RL);
				return;
			
			}
		}
		if(t->data==value){
			
			if(t->LL==NULL && t->RL==NULL ){
				printf("\nData Deleted: %d\n",t->data);
				if(stalker->LL==t){
					stalker->LL=NULL;
					return;
				}else{
					stalker->RL=NULL;
					return;
				}
			}
			else if(t->LL==NULL){
				printf("\nData Deleted: %d\n",t->data);
					if(stalker->RL==t){
					stalker->RL=t->RL;
				return;
				}
					else{
					stalker->LL=t->RL;
				return;
				}}
			else if(t->RL==NULL){
				printf("\nData Deleted: %d\n",t->data);
				if(stalker->LL==t){
					stalker->LL=t->LL;
					return;
					}
				else{
					stalker->RL=t->LL;
				return;
				}}
			else{
				inorder_successor(t->RL);
				printf("\nData replaced  with: %d\n",succ->data);
				t->data=succ->data;
				stalker=t;
				delete_bstmin(t->RL);
				return;				
			}
			}
		}
	}
void modify_bst(struct bst *t,int oldel,int newel){
	if(t==NULL){
		printf("\nElement Not Found\n");
		return;
	}
	else{
		if(oldel<t->data){
			modify_bst(t->LL,oldel,newel);
			}
		else if(oldel>t->data){
			modify_bst(t->RL,oldel,newel);
		}
		else{
			if((t->LL==NULL || newel>t->LL->data) && (t->RL==NULL || newel<t->RL->data)){
				t->data=newel;
				printf("\nThe Node has been Modified\n");
			}
			else{
				printf("Can't Modify,Voilates property of BST");
			}
		}
		}
	}	
void inorder_bst(struct bst *t){
	if(t==NULL){
		return;
	}
	inorder_bst(t->LL);
	printf("%d\t",t->data);
	inorder_bst(t->RL);
}
void preorder_bst(struct bst *t){
	if(t==NULL){
		return;
	}
	printf("%d\t",t->data);
	preorder_bst(t->LL);
	preorder_bst(t->RL);
}
void postorder_bst(struct bst *t){
	if(t==NULL){
		return;
	}
	postorder_bst(t->LL);
	postorder_bst(t->RL);
	printf("\n%d\t left link part:%u and right link part;%u",t->data,t->LL,t->RL);
}
int search_bst(struct bst *t,int value){
	if(t==NULL){
		return;
	}
	search_bst(t->LL,value);
	if(t->data==value){
		f=1;
	}
	search_bst(t->RL,value);
}
int count_bst(struct bst *t){
	if(t==NULL){
		return 0;
	}
	return(count_bst(t->LL)+count_bst(t->RL)+1);
}
void Minel(struct bst *t){
	while(t->LL!=NULL){
		t=t->LL;
	}
	printf("\nThe Smallest Node in the Binary Search Tree is : %d\n",t->data);
}
void Maxel(struct bst *t){
	while(t->RL!=NULL){
		t=t->RL;
	}
	printf("\nThe Largest Node in the Binary Search Tree is : %d\n",t->data);
}
struct bst *inorder_successor(struct bst *t){
	struct bst *temp=t;
	while(temp->LL!=NULL){
		temp=temp->LL;
	}
	succ=temp;	
}
void delete_bstmin(struct bst *t){
	printf("\nMan i dont think this is getting called\n");
	struct bst *temp=t,*temp1=NULL;
	while(temp->LL!=NULL){
		temp1=temp;
		printf("Value in temp1:%d",temp1->data);
		temp=temp->LL;
		printf("Value in temp:%d",temp->data);
	}
	printf("I came out");
		if(root->RL==temp){
						printf("I am in 1");						
		root->RL=root->RL->RL;
		return;
		
	}
	printf("I came out");
	if(stalker->RL==temp){
		printf("I am in 2");
		stalker->RL=temp->RL;
		return;
	}
	printf("I came out");
	if(temp->LL==NULL && temp->RL==NULL){
		printf("I am in 3");
		temp1->LL=NULL;
		return;
	}
	printf("I came out");
	if(temp->LL==NULL && temp->RL!=NULL){
	 	printf("I am in 4");
		temp1->LL=temp->RL;
		return;		
	}
	printf("I came out");
	printf("Found no statemnt to execute");	
	return;
	}
