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

	int req[n],order[n],head=0,idx=0;

	for(int i=0;i<n;i++){
		scanf("%d",&req[i]);
	}

	printf("enter the head position\n");
	scanf("%d",&head);

	int pos,p;

	pos=getpos(req,n,head);
	printf("%d\n",pos);
	/////////////////////////////////////////////////////////////////////////////
	if(pos<n/2){
		p=pos;
		while(p!=-1){
			order[idx++]=req[p];
			p--;
		}
		for(int i=pos+1;i<n;i++){
			order[idx++]=req[i];
		}

	}
	else{
		p=pos-1;
		for(int i=pos;i<n;i++){
			order[idx++]=req[i];
		}
		while(p!=-1){
			order[idx++]=req[p];
			p--;
		}
	}
	
	
	printf("\nORDER\n");

	for(int i=0;i<idx;i++){
		printf("%d\t\t",order[i]);
	}
	return 0;

}