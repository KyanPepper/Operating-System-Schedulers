#include "scheduler/scheduler.h"

int main(int argc, char *argv[])
{
    uint32_t CURRENT_CYCLE = 0;             // The current cycle that each process is on
    uint32_t TOTAL_CREATED_PROCESSES = 0;   // The total number of processes constructed
    uint32_t TOTAL_STARTED_PROCESSES = 0;   // The total number of processes that have started being simulated
    uint32_t TOTAL_FINISHED_PROCESSES = 0;  // The total number of processes that have finished running
    uint32_t TOTAL_NUMBER_OF_CYCLES_SPENT_BLOCKED = 0; // The total cycles in the blocked state
    FILE* random_num_file_ptr = fopen("random-numbers", "r");
    if (random_num_file_ptr == NULL)
    {
        fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
        return 1;
    }
    
    uint32_t total_num_of_process = getRandNumFromFile(SEED_VALUE, random_num_file_ptr);
    printf(total_num_of_process);

    
    Process* process_list = malloc(total_num_of_process * sizeof(Process)); // Creates a container for all processes



    return 0;
} 