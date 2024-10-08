#include <stdio.h>

#define MAX_PROCESSES 100

typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
} Process;
int myarr[10],mytime[10];
void calculate_times(Process *p, int n) {
    int time = 0,ik=0;
    int completed = 0;

    while (completed < n) {
        int shortest_index = -1;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= time && p[i].completion_time == 0) {
                if (shortest_index == -1 || p[i].burst_time < p[shortest_index].burst_time) {
                    shortest_index = i;
                    
                }
            }
        }

        if (shortest_index != -1) {
            myarr[ik]=shortest_index;
            mytime[ik]=time;ik++;
            p[shortest_index].completion_time = time + p[shortest_index].burst_time;
            p[shortest_index].turnaround_time = p[shortest_index].completion_time - p[shortest_index].arrival_time;
            p[shortest_index].waiting_time = p[shortest_index].turnaround_time - p[shortest_index].burst_time;

            time += p[shortest_index].burst_time;
            completed++;
        } else {
            time++;
        }
    }
}

void print_results(Process *p, int n) {
    float total_waiting_time = 0;
    float total_turnaround_time = 0;


    printf("\n\ngc first\n\n");
    for(int i=0;i<n;i++){
        //int a=2,b=4;
        int a=p[myarr[i]].burst_time    ,b=mytime[i];
        printf("P[%d]->%d----%d\t\t",p[myarr[i]].process_id,mytime[i],a+b);
    }

    printf("\nProcess ID | Arrival Time | Burst Time | Waiting Time | Turnaround Time\n");
    printf("-----------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;


        printf("%10d | %12d | %10d | %12d | %15d\n", p[i].process_id, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
    }

    printf("\nAverage Waiting Time: %.2f", total_waiting_time / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround_time / n);
}

int main() {
    int n;
    Process processes[MAX_PROCESSES];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        processes[i].process_id = i + 1;

        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);

        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);

        processes[i].completion_time = 0;
    }

    calculate_times(processes, n);
    print_results(processes, n);

    return 0;
}
