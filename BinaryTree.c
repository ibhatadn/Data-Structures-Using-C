#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct btree{
	struct btree *LT;
	int data;
	struct btree *RT;
};
int f=0;
struct btree *root=NULL,*stalker=NULL,*t=NULL;
void insert();
void modify(struct btree *,int);
void inorder(struct btree *);
void preorder(struct btree *);
void postorder(struct btree *);
int search(struct btree *,int);
void deletebtree(struct btree *,int);
int count(struct btree *);
int main(){
	int n,el;
	printf("\nEnter choice:\n");
	while(1){
		printf("\n\n1 for Insertion \t 2 for Deletion \t 3 to Modify \t 4 for inorder display \n5 for preorder display \t 6 for postorder display \t 7 To search \t 8 to Count  \t 10 to Exit\n\n");
		scanf("%d",&n);
		printf("\n");
		switch(n){
			case 1:{
				insert();
				break;
			}
			case 2:{
				t=root;
				if(root==NULL){
					printf("\n\nEmpty Tree\n\n");
					break;
				}
				printf("\nEnter data of the Node you want to delete:\t");
				scanf("%d",&el);
				search(t,el);
				if(f==0){
					printf("\nNumber Not Found\n");
				}
				else{
					t=root;
					deletebtree(t,el);
					f=0;
				}
				break;
			}
			case 3:{
				t=root;
						if(root==NULL){
					printf("\n\nEmpty Tree\n\n");
					break;
				}
				printf("\nEnter data of the Node you want to modify:\t");
				scanf("%d",&el);
				search(t,el);
				if(f==0){
					printf("\nNumber Not Found\n");
				}
				else{
					t=root;
				modify(t,el);
				f=0;
			}
				break;
			}
			case 4:{
					if(root==NULL){
					printf("\n\nEmpty Tree\n\n");
					break;
				}
				t=root;
				inorder(t);
				break;
			}
			case 5:{
					if(root==NULL){
					printf("\n\nEmpty Tree\n\n");
					break;
				}
				t=root;
				preorder(t);
				break;
			}
			case 6:{
					if(root==NULL){
					printf("\n\nEmpty Tree\n\n");
					break;
				}
				t=root;
				postorder(t);
				break;
			}
			case 7:{
				if(root==NULL){
					printf("\n\nEmpty Tree\n\n");
					break;
				}
				t=root;
				printf("\nEnter Data:\t");
				scanf("%d",&el);
				search(t,el);
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
					printf("\nEmpty Tree\n");
					break;
				}
				c=count(t);
				printf("The number of nodes in the Binary Tree are: %d",c);
				break;
			}
			case 10:{
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
void insert(){
	struct btree *p,*pre=NULL,*cur=NULL;
	int el,i,len;
	char dir[20];
	p=(struct btree *)malloc(sizeof(struct btree));
	if(p==NULL){
		printf("\n\nMemory Not Allocated\n\n");
		return;
	}
	printf("\n\nEnter data:\t");
	scanf("%d",&el);
	p->data=el;
	p->LT=NULL;
	p->RT=NULL;
	if(root==NULL){
		root=p;
	}else{
		printf("\n\nEnter the Direction in which you want to insert the nodes:\t");
		scanf("%s",dir);
		cur=root;
		len=strlen(dir);
		for(i=0;i<len;i++){
			if(cur==NULL){
				break;
			}
			pre=cur;
			if(dir[i]=='L' || dir[i]=='l'){
				cur=cur->LT;
			}
			else{
				cur=cur->RT;
			}
		}
		if(cur!=NULL || i!=len){
			printf("\n\nInsertion of Node Not Possible\n\n");
			return;
		}
		if(dir[i-1]=='L' || dir[i-1]=='l'){
			pre->LT=p;
		}
		else{
			pre->RT=p;
	}
		}
			}
void inorder(struct btree *t){
	if(t==NULL){
		return;
	}
	inorder(t->LT);
	printf("%d\t",t->data);
	inorder(t->RT);
}
void preorder(struct btree *t){
	if(t==NULL){
		return;
	}
	printf("%d\t",t->data);
	preorder(t->LT);
	preorder(t->RT);
}
void postorder(struct btree *t){
	if(t==NULL){
		return;
	}
	preorder(t->LT);
	preorder(t->RT);
	printf("%d\t",t->data);
}
int search(struct btree *t,int n){
	if(t==NULL)
	return;
	search(t->LT,n);
	if(t->data==n){
	f=1;
	}
	search(t->RT,n);
}
void deletebtree(struct btree *t,int value){
	struct btree *temp1,*temp2;
	if(root->data==value){
		printf("\n\nRoot Node with data %d deleted\n\n",root->data);
		if(root->LT==NULL && root->RT==NULL){
			free(root);
			root=NULL;
			return;
		}
		else if(root->LT==NULL){
			root=root->RT;
			return;
		}
		else if(root->RT==NULL){
			root=root->LT;
			return;
		}
		else{
			temp1=root->LT;
			temp2=root->RT;
			root=temp1;
			while(temp1->LT!=NULL){
				temp1=temp1->LT;
			}
			temp1->LT=temp2;
		}
		
	}else{
	if(t==NULL){
		return;
	}
	if(t->data==value){
		printf("\nNode with Data: %d deleted\n",t->data);
		if(t->LT==NULL && t->RT==NULL){
			if(stalker->LT==t){
			stalker->LT=NULL;
			return;
			}
			else{
			stalker->RT=NULL;
			return;
			}
		}
		else if(t->RT==NULL && t->LT!=NULL){
			if(stalker->LT==t){
				stalker->LT=t->LT;
				return;
			}
			else{
				stalker->RT=t->LT;
			return;
			}
		}
		 else if(t->LT==NULL && t->RT!=NULL){
			if(stalker->LT==t){
				stalker->LT=t->RT;
				return;
		 }
			else{
				stalker->RT=t->RT;
				return;
			}
		
		}
		else{
			temp1=t->LT;
			temp2=t->RT;
				if(stalker->LT==t){
				stalker->LT=temp1;
				while(temp1->LT!=NULL){
					temp1=temp1->LT;
				}
				temp1->LT=temp2;
				return;
			}else{
			stalker->RT=temp1;
				while(temp1->LT!=NULL){
					temp1=temp1->LT;
				}
				temp1->LT=temp2;
				return;
			}
		}
		 
	}
	stalker=t;
	deletebtree(t->LT,value);
	stalker=t;
	deletebtree(t->RT,value);
}
}
void modify(struct btree *t,int value){
		int el;
		if(root->data==value){
			printf("\nEnter the data with which you want to replace the root node:\t");
			scanf("%d",&el);
			printf("\n\nRoot Node with data: %d replaced with: %d\n\n",root->data,el);
			root->data=el;
			return;
		}
		else {
		if(t==NULL){
			return;
		}	
		if(t->data==value){
			printf("\nEnter the data with which you want to replace the node:\t");
			scanf("%d",&el);
			printf("\n\n Node with data: %d replaced with: %d\n\n",t->data,el);
			t->data=el;
			return;	
			}
			modify(t->LT,value);
			modify(t->RT,value);	
		}
	}
int count(struct btree *t){
	if(t==NULL){
		return 0;
	}
	return (count(t->LT)+count(t->RT)+1);
	}
