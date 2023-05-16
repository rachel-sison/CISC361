#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#include "exercise1.h"

// 3
void problem3() {
    int status;
    int pid = fork();
    
    if (pid == 0) {
        // Child process
        int child_pid = getpid();
        printf("I am the child (%d)\n", child_pid);
        
        int grandchild_pid = fork();
        if (grandchild_pid == 0) {
            // Grandchild process
            int grandchild_pid = getpid();
            printf("I am the grandchild (%d)\n", grandchild_pid);
        }
        
        // Wait for the grandchild process to complete
        wait(NULL);
    } else if (pid > 0) {
        // Parent process
        int parent_pid = getpid();
        printf("I am the parent (%d)\n", parent_pid);
        
        // Wait for the child process to complete
        wait(NULL);
    } else {
        // Error occurred during fork()
        printf("Fork failed\n");
    ;
    }

}

#define MAX_NO_OF_ELEMENTS 1000000
void problem4(){
    int numbers[MAX_NO_OF_ELEMENTS];
    int i;
    long long sum = 0;
    clock_t start, end;
    double cpu_time_taken;
    
    // Initialize the array with numbers from 1 to MAX_NO_OF_ELEMENTS
    for (i = 0; i < MAX_NO_OF_ELEMENTS; i++) {
        numbers[i] = i + 1;
    }
    
    // Start timing
    start = clock();
    
    // Sum all the elements of the array
    for (i = 0; i < MAX_NO_OF_ELEMENTS; i++) {
        sum += numbers[i];
    }
    
    // Stop timing
    end = clock();
    
    // Calculate CPU time taken
    cpu_time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    // Print the total sum and the time taken
    printf("Total sum: %lld\n", sum);
    printf("Time taken to sum all the numbers is %lf seconds.\n", cpu_time_taken);

}

int main(){
    problem3();
}