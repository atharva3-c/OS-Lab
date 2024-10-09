#include<stdio.h>
#include<stdlib.h>




int check(int re[],int avail[],int n){
	
	for(int i=0;i<n;i++){
		if(re[i]>avail[i]){
			return 0;
		}
	}
	return 1;
}


int main(){

int m,n,sum;
printf("enter the Processes : ");
scanf("%d",&m);

printf("enter the no of resources : ");
scanf("%d",&n);

int allocation[m][n],maxneed[m][n],available[m][n],remainingneed[m][n];
int maxresources[n];
//////////////////////////////////////////////////////////////
printf("enter max available resource numbers\n");
for(int i=0;i<n;i++){
	scanf("%d",&maxresources[i]);
}
///////////////////////////////////////////////////////////
printf("\nEnter vales of Allocation\n");
for(int i=0;i<m;i++){

	for(int j=0;j<n;j++){
	
		scanf("%d",&allocation[i][j]);
	
	}

}

int totalresources[n];

for(int i=0;i<n;i++){
	sum=0;

	for(int j=0;j<m;j++){
	
		sum+=allocation[j][i];
	
	}
	totalresources[i]=sum;

}

/////////////////////////////////////////////

printf("\nEnter vales of Maxneed\n");
for(int i=0;i<m;i++){

	for(int j=0;j<n;j++){
	
		scanf("%d",&maxneed[i][j]);
	
	}

}
/////////////////////////////////////////////
int rem[n];
for(int i=0;i<n;i++){

rem[i]=maxresources[i]-totalresources[i];
}
////////////////////////////////////////////////
for(int i=0;i<m;i++){

	for(int j=0;j<n;j++){
	
		remainingneed[i][j]=maxneed[i][j]-allocation[i][j];
	
	}

}
//////////////////////////////////////////////////

int flag[m],order[m];
int start=0;
for(int i=0;i<m;i++){
	flag[i]=0;
}
int stopflag;
    printf("Available Resources at start: ");
    for (int k = 0; k < n; k++) {
        printf("%d ", rem[k]);
    }
    printf("\n");
for(int i=0;i<m;i++){
	stopflag=1;

	for(int j=0;j<m;j++){
		if(flag[j]==1){
			continue;
		}
		if(check(remainingneed[j],rem,n)){
			stopflag=0;
			for(int l=0;l<n;l++){
				rem[l]+=allocation[j][l];
			}
			flag[j]=1;
			order[start++]=j+1;
			break;
		}
	}
	if(stopflag){
		printf("\nDEADLOCK\n");
		break;
	}
	for(int k=0;k<n;k++){
		printf("%d ",rem[k]);
	}
	printf("\n");

}

printf("SAFE SEQUENCE\n");
for(int i=0;i<m;i++){
	printf("%d",order[i]);
}

return 0;

}

