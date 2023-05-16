#include<stdio.h>
#include <stdbool.h>
int main()
{
// Initialize variables
int i = 0, num_processes = 0, total_time = 0, x, output_flag = 0,
time_quantum =0;
int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10],
temp[10];
float average_wait_time = 0, average_turnaround_time = 0;
bool round_robin_algorithm = false;
for(i = 0; i < 10; i++)
{
arrival_time[i] = 0;
burst_time[i] = 0;
temp[i] = 0;
}
// Define Number of Processes
while(num_processes < 1 || num_processes > 10)
{
printf("\nEnter Total Number of Processes (1 - 10):\t");
scanf("%d", &num_processes);
if (num_processes < 1 || num_processes > 10)
{
printf("Incorrect Value Entered");
}
}
// Define Process Details
x = num_processes;
for(i = 0; i < num_processes; i++)
{
printf("\nEnter Details of Process[%d]\n", i + 1);
printf("Arrival Time (>-1):\t");
scanf("%d", &arrival_time[i]);
printf("Burst Time (>0):\t");
scanf("%d", &burst_time[i]);
temp[i] = burst_time[i];
if (arrival_time[i] < 0 && burst_time[i] < 1) {
printf("Incorrect Values Entered");
i--;
}
}
// Define Quantum
if (round_robin_algorithm)
{
while(time_quantum < 1)
{
printf("\nEnter Time Quantum (>0):\t");
scanf("%d", &time_quantum);
if (time_quantum < 1)
{
printf("Incorrect Value Entered");
}
}
}
// Prepare Output
printf("\nProcess ID\t\tArrival Time\t\tBurst Time\t Turnaround Time\tWaiting Time\n");
// Perform Scheduling Calculations
if (!round_robin_algorithm)
{for (i = 0; i < num_processes; i++)
    {
        // Update total waiting time
        wait_time += total_time - arrival_time[i];
        
        // Update total turnaround time
        turnaround_time += total_time - arrival_time[i] + burst_time[i];
        
        // Update total time
        total_time += burst_time[i];
        
        // Print process details
        printf("%d\t\t\t%d\t\t\t%d\t\t%d\t\t%d\n", i + 1, arrival_time[i], burst_time[i],
            total_time - arrival_time[i], total_time - arrival_time[i] - burst_time[i]);
}
{int remaining_time[num_processes];
    int current_time = 0;
    int completed_processes = 0;

    
}
}
// Calculate & Print Average Wait and Turnaround Times
average_wait_time = 0;
average_turnaround_time = 0;
printf("\n\nAverage Waiting Time:\t%f", average_wait_time);
printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time);
return 0;
}

/*1. Read through the code and then, using the if/else declaration in the “Perform Scheduling
Calculations” section, write code that calculates and outputs how a First-Come-First-Serve
scheduler would handle the processes you define. To implement this: “Add code in the "Perform
*/