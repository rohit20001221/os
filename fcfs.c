#include<stdio.h>

void waitTime(int processes[], int n, int bt[], int wt[]){
    wt[0] = 0;

    for(int i=1; i<n; i++){
        wt[i] = bt[i-1]+wt[i-1];
    } 
}

void turnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]){
    for(int i=0; i < n; i++){
        tat[i] = bt[i] + wt[i];
    }
}

void findavgTime(int processes[], int n, int bt[]){
    int wt[n], tat[n], total_wt=0, total_tat=0;

    waitTime(processes, n, bt, wt);
    turnAroundTime(processes, n, bt, wt, tat);

    for(int i=0; i < n; i++){
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];

        printf("\t%d", processes[i]);
        printf("\t\t%d", bt[i]);
        printf("\t\t%d", wt[i]);
        printf("\t\t%d\n", tat[i]);
    }

    float s = (float)total_wt/n;
    float t = (float)total_tat/n;

    printf("WT(avg) = %f\n", s);
    printf("TAT(avg) = %f\n", t);
}

int main(){
    int processes[] = {1,2,3};
    int n = sizeof(processes)/sizeof(int);

    int burst_time[] = {10, 5, 8};
    findavgTime(processes, n, burst_time);
    return 0;
}