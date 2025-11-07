#include <stdio.h>
struct Process {
    int pid, at, bt, ct, tat, wt;
};

int main() {
    int n;
    printf("Number of processes : ");
    scanf("%d", &n);
    struct Process p[n];
    printf("Burst time : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i].bt);
        p[i].pid = i;
    }
    printf("Arrival time : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i].at);
    }
    int time = 0;
    float totalWT = 0, totalTAT = 0;
    for (int i = 0; i < n; i++) {
        if (time < p[i].at) time = p[i].at; // CPU idle till arrival
        time += p[i].bt;
        p[i].ct = time;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        totalWT += p[i].wt;
        totalTAT += p[i].tat;
    }
    printf("\nGantt Chart : ");
    for (int i = 0; i < n; i++) {
        printf("P%d ", p[i].pid);
    }
    printf("\n");
    printf("\n%-5s %-5s %-5s %-5s %-5s %-5s\n", "PID", "AT", "BT", "CT", "TAT", "WT");
    for (int i = 0; i < n; i++) {
        printf("P%-4d %-5d %-5d %-5d %-5d %-5d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("\nAverage waiting time: %.2f\n", totalWT / n);
    printf("Average turnaround time : %.2f\n", totalTAT / n);

    return 0;
}
