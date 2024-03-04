#include <stdio.h>

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};

void calculate_completion_time(struct Process processes[], int n) {
    int current_time = 0;

    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        processes[i].completion_time = current_time + processes[i].burst_time;
        current_time = processes[i].completion_time;
    }
}

void calculate_waiting_time(struct Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].waiting_time = processes[i].completion_time - processes[i].arrival_time - processes[i].burst_time;
    }
}

void calculate_turnaround_time(struct Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

void calculate_average_times(struct Process processes[], int n, float *avg_waiting_time, float *avg_turnaround_time) {
    int total_waiting_time = 0, total_turnaround_time = 0;

    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    *avg_waiting_time = (float)total_waiting_time / n;
    *avg_turnaround_time = (float)total_turnaround_time / n;
}

void display_results(struct Process processes[], int n, float avg_waiting_time, float avg_turnaround_time) {
    printf("+------------+--------------+------------+------------------+--------\n");
    printf("| Process ID | Arrival | Burst | Completion  | Waiting | Turnaround |\n");
    printf("+------------+--------------+------------+------------------+--------\n");
   
    for (int i = 0; i < n; i++) {
        printf("|     %2d     |  %4d   | %4d  |    %4d     | %4d    |  %4d      |\n",
               processes[i].id, processes[i].arrival_time, processes[i].burst_time,
               processes[i].completion_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("+------------+--------------+------------+------------------+---------\n");
    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

int main() {
    int n;
    float avg_waiting_time, avg_turnaround_time;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Process %d Arrival Time: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }

    calculate_completion_time(processes, n);
    calculate_waiting_time(processes, n);
    calculate_turnaround_time(processes, n);
    calculate_average_times(processes, n, &avg_waiting_time, &avg_turnaround_time);
    display_results(processes, n, avg_waiting_time, avg_turnaround_time);

    return 0;
}