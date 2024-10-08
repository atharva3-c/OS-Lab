#include<stdio.h>
#include<stdlib.h>



int max(int a,int b){

    if(a>b){
        return a;
    }

    else
        return b;
}


void fcfs(int temp[],int process[],int burst[],int n){
int completion[n];


for(int i=0;i<n;i++){
    for(int j=0;j<n-i-1;j++){
        if(temp[j]>temp[j+1]){

            int t=temp[j];
            temp[j]=temp[j+1];
            temp[j+1]=t;

            int l=process[j];
            process[j]=process[j+1];
            process[j+1]=l;

            int o=burst[j];
            burst[j]=burst[j+1];
            burst[j+1]=o;
        }

    }

}

printf("\n\ngantt chart\n\n");

for(int i=0;i<n;i++){
    printf("-P[%d]-",process[i]);
}

printf("\n\n");

int start=temp[0],end=burst[0];
completion[0]=end;
printf("P[%d]-(%d->%d)\n",0,start,end);

    for(int i=1;i<n-1;i++){

        start=max(end,temp[i]);
        end=start+burst[i];
        completion[i]=end;
        printf("P[%d]-(%d->%d)\n",i,start,end);

    }

    start=max(end,temp[n-1]);
    end=start+burst[n-1];
    completion[n-1]=end;
    printf("P[%d]-(%d->%d)\n",n-1,start,end);
    printf("\n");
    printf("proc\t\tarr\t\tburst\t\tcompletion\t\ttat\t\twaiting time");
    printf("\n");

    for(int i=0;i<n;i++){
        int tat=completion[i]-temp[i];
        int wt=tat-burst[i];
        printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",process[i],temp[i],burst[i],completion[i],tat,wt);
        printf("\n");
        }   
}


int main(){
int n;
printf("enter number of processes :");
scanf("%d",&n);

int arrival[n],burst[n],process[n];


for(int i=0;i<n;i++){
process[i]=i;	
printf("arrival P[%d] :",i);
scanf("%d",&arrival[i]);

printf("burst P[%d] :",i);
scanf("%d",&burst[i]);
printf("\n");

}
fcfs(arrival,process,burst,n);

return 0;
}


