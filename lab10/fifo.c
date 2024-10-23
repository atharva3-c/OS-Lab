#include <stdio.h>
#include<stdlib.h>


int main()
{
	int size,pagefault=0,pno,check=-1,flag;
	printf("Enter the size\n");
	scanf("%d",&size);

	int arr[size];
	int start=0;

	for(int i=0;i<size;i++){
		arr[i]=-1;
	}

	while(1){

		printf("enter page number\t");
		scanf("%d",&pno);
		flag=0;
		if(pno==-1){
			break;
		}

		for(int i=0;i<size;i++){
			if(arr[i]==pno){
				printf("HIT\n");
				flag=1;
				break;
			}
		}
		if(!flag){
			start=(start+1)%size;
			arr[start]=pno;
			pagefault++;
		}
	}
	printf("%d",pagefault);
	return 0;
}