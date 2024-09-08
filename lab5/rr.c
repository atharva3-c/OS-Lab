#include <stdio.h>

#define MAX_PROCESSES 100

typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
} Process;
int mypro[20],mystart[20],mypause[20];int gi=0;
void enqueue_by_burst_time(int queue[], int *rear, Process *p, int index) {
    int i = *rear;

    // Find the correct position to insert the process based on burst time
    while (i >= 0 && p[queue[i]].burst_time > p[index].burst_time) {
        queue[i + 1] = queue[i];
        i--;
    }

    queue[i + 1] = index;
    (*rear)++;
}

void calculate_times(Process *p, int n, int quantum) {
    int time = 0;
    int completed = 0;
    int process_in_queue = 0;
    int queue[MAX_PROCESSES];
    int front = 0, rear = -1;

    // Initialize the queue with the first set of processes that arrive at time 0
    for (int i = 0; i < n; i++) {
        if (p[i].arrival_time <= time) {
            enqueue_by_burst_time(queue, &rear, p, i);
            process_in_queue++;
        }
    }


    while (completed < n) {
        if (process_in_queue > 0) {
            int i = queue[front];
            front = (front + 1) % MAX_PROCESSES;
            process_in_queue--;

            mypro[gi]=p[i].process_id;
            mystart[gi]=time;

            if (p[i].remaining_time > quantum) {
                p[i].remaining_time -= quantum;
                time += quantum;
            } else {
                time += p[i].remaining_time;
                p[i].remaining_time = 0;
                p[i].completion_time = time;
                p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
                p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
                completed++;
            }

            mypause[gi]=time;
            gi++;

            // Add any new processes that have arrived to the queue
            for (int j = 0; j < n; j++) {
                if (p[j].arrival_time <= time && p[j].remaining_time > 0 && j != i) {
                    int already_in_queue = 0;
                    for (int k = front; k != (rear + 1) % MAX_PROCESSES; k = (k + 1) % MAX_PROCESSES) {
                        if (queue[k] == j) {
                            already_in_queue = 1;
                            break;
                        }
                    }
                    if (!already_in_queue) {
                        queue[++rear] = j;
                        process_in_queue++;
                    }
                }
            }

            // If the current process still has remaining time, add it back to the queue
            if (p[i].remaining_time > 0) {
                queue[++rear] = i;
                process_in_queue++;
            }
        } else {
            time++;
            for (int j = 0; j < n; j++) {
                if (p[j].arrival_time <= time && p[j].remaining_time > 0) {
                    queue[++rear] = j;
                    process_in_queue++;
                    break;
                }
            }
        }
    }
}

void myfunc(){
    printf("\nGantt Chart:\n");
    for (int i = 0; i < gi; i++) {
        printf("P[%d] -- %d to %d  \t", mypro[i], mystart[i], mypause[i]);
    }
    printf("\n");
}


void print_results(Process *p, int n) {
    float total_waiting_time = 0;
    float total_turnaround_time = 0;

    printf("\nProcess ID | Arrival Time | Burst Time | Completion time |Turnaround Time| Waiting Time \n");
    printf("-----------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;

        printf("%10d | %12d | %10d | %12d | %12d | %15d\n", p[i].process_id, p[i].arrival_time, p[i].burst_time,p[i].completion_time, p[i].turnaround_time,p[i].waiting_time);
    }

    printf("\nAverage Waiting Time: %.2f", total_waiting_time / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround_time / n);
}

int main() {
    int n, quantum;
    Process processes[MAX_PROCESSES];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    for (int i = 0; i < n; i++) {
        processes[i].process_id = i + 1;

        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);

        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);

        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completion_time = 0;
    }

    calculate_times(processes, n, quantum);
    myfunc();
    print_results(processes, n);

    return 0;
}
