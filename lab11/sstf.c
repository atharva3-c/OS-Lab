#include<stdio.h>
#include<stdlib.h>


int getpos(int arr[], int n, int tar){

	for(int i=0;i<n;i++){
		if(arr[i]==tar){
			return i;
		}
	}
	return -1;
}





int main(){
	int n;
	printf("enter the size of requests\n");
	scanf("%d",&n);
	printf("\nEnter the requests");

	int req[n],order[n],head=0,ind=0;

	for(int i=0;i<n;i++){
		scanf("%d",&req[i]);
	}

	printf("enter the head position\n");
	scanf("%d",&head);

	int pos,left,right,idx=0,leftdiff,rightdif,summ=0;

	pos=getpos(req,n,head);
	printf("%d\n",pos);
	/////////////////////////////////////////////////////////////////////////////
	left=pos-1;
	right=pos+1;

	while(left>=0&&right<n){

		leftdiff=req[pos]-req[left];
		rightdif=req[pos]-req[right];

		if(abs(leftdiff)<=abs(rightdif)){
			//summ+=abs(leftdiff);
			order[idx++]=req[left];
			printf("%d\n",req[left]);
			pos=left;
			left=pos-1;
		}
		else{
			summ+=abs(rightdif);
			order[idx++]=req[right];
			pos=right;
			right=pos+1;
		}
	}

	if(right<n-1){
		while(right!=n-1){
		order[idx++]=req[right];
		right++;
		}
	}
	
	if(left>0){
		while(left!=0){
		order[idx++]=req[left];
		left--;
	}
	}
	
	printf("\nORDER\n");

	for(int i=0;i<idx;i++){
		printf("%d\t\t",order[i]);
	}
	return 0;

}