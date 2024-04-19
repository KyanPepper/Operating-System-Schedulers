#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef enum bool {
    false, true
} bool;

// Define the process struct
typedef struct Process {
    uint32_t A;                      // Arrival time of the process
    uint32_t B;                      // Upper bound of CPU burst times
    uint32_t C;                      // Total CPU time required
    uint32_t M;                      // Multiplier of CPU burst time
    uint32_t processID;              // Process ID

    uint8_t status;                  // 0: unstarted, 1: ready, 2: running, 3: blocked, 4: terminated

    int32_t finishingTime;           // Cycle when the process finishes (-1 initially)
    uint32_t currentCPUTimeRun;      // Time the process has run (in running state)
    uint32_t currentIOBlockedTime;   // Time the process has been IO blocked (in blocked state)
    uint32_t currentWaitingTime;     // Time spent waiting (in ready state)

    uint32_t IOBurst;                // Time until process finishes being blocked
    uint32_t CPUBurst;               // CPU availability (must be > 1 to move to running state)

    int32_t quantum;                 // Quantum for preemptive schedulers

    bool isFirstTimeRunning;         // Flag to check when to calculate CPU burst in running state

    struct Process* nextInBlockedList;        // Next process in blocked list
    struct Process* nextInReadyQueue;         // Next process in ready queue
    struct Process* nextInReadySuspendedQueue; // Next process in ready suspended queue
} Process;

// Function prototypes
uint32_t getRandNumFromFile(uint32_t line, FILE* random_num_file_ptr);
uint32_t randomOS(uint32_t upper_bound, uint32_t process_indx, FILE* random_num_file_ptr);
void printStart(Process process_list[]);
void printFinal(Process finished_process_list[]);
void printProcessSpecifics(Process process_list[]);
void printSummaryData(Process process_list[]);


const char* RANDOM_NUMBER_FILE_NAME= "random-numbers";
const uint32_t SEED_VALUE = 200;  // Seed value for reading from file


