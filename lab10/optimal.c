#include <stdio.h>
#include<stdlib.h>


int getindex(int arr[],int size,int pno,int pro[],int n,int j){
	int mintc=1000,count,ind=-1;

	for(int i=0;i<size;i++){
		count=0;
		for(int t=j+1;t<n;t++){
			if(pro[t]==arr[i]){
				count++;
			}
		}
		if(count<mintc){
			mintc=count;
			ind=i;
		}
	}
	return ind;
}
int main()
{
	int size,pagefault=0,pno,check=-1,flag,full=0,len;

	printf("Enter the size of storage\n");
	scanf("%d",&size);

	int arr[size];
	int start=-1;

	for(int i=0;i<size;i++){
		arr[i]=-1;
	}

	printf("Enter the length of page arrays\n");
	scanf("%d",&len);
	int pro[len];


	for(int i=0;i<len;i++){
		scanf("%d",&pro[i]);
	}

	for(int j=0;j<len;j++){

		flag=0;
		for(int i=0;i<size;i++){
			if(arr[i]==pro[j]){
				printf("\nHIT\n");
				flag=1;
				break;
			}
		}
		if(!flag){
			if(full<size){
				full++;
				start=(start+1)%size;
				arr[start]=pro[j];
				pagefault++;
			}
			else{
				start=getindex(arr,size,pro[j],pro,len,j);
				printf("\nGot index to replace as %d\n",start);
				arr[start]=pro[j];
				pagefault++;
			}
			
		}
	}
	printf("%d",pagefault);
	return 0;
}