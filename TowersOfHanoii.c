#include<stdio.h>
void towers(int ,char ,char ,char ); 
int main(){
	int number;
	printf("\nEnter the number of discs\n");
	scanf("%d",&number);
	towers(number,'A','B','C');
}
void towers(int n,char a,char b,char c){
	if(n<0){
		printf("\ninvalid entry\n");
	}
	else if(n==1){
		printf("\nDisk moved from %c to %c\n",a,c);
	}
	else{
		towers(n-1,a,c,b);
		towers(1,a,b,c);
		towers(n-1,b,a,c);
	}
}
