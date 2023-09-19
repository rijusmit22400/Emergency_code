#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/resource.h>


typedef struct time_record {
    struct timespec start;
    struct timespec final;
}time_record;

int main() {
    FILE *generator;
    pid_t ids[3];
    time_record time [3];
    int scheduling[3]={SCHED_OTHER,SCHED_FIFO,SCHED_RR};
    int num_children = 3;
    int priority[3]={0,50,50};

    for (int i = 0; i < num_children; i++) {
        clock_gettime(1,&(time[i].start));
        pid_t child_pid = fork();
        if (child_pid < 0) {

            perror("fork");
            exit(EXIT_FAILURE);

        } else if (child_pid == 0) {

            struct sched_param param;
            param.sched_priority=priority[i];
            printf("The child process %d is about to run\n",i+1);
            if(i==0){
                if(setpriority(PRIO_PROCESS,0,0)==-1){
                    perror("cannot set priority");
                    continue;
                }
                execl("/home/rijusmit-biswas/Desktop/OS-2/e2","/home/rijusmit-biswas/Desktop/OS-2/e2",NULL);
                continue;
            }
            if(sched_setscheduler(0,scheduling[i],&param)==-1){
                perror("KILLING THE CHILD NOW");
                
            }else{
                execl("/home/rijusmit-biswas/Desktop/OS-2/e2","/home/rijusmit-biswas/Desktop/OS-2/e2",NULL);
            }
            exit(EXIT_SUCCESS);

        } else {
            ids[i] = child_pid;
        }
    }
    generator = fopen("data.txt","w"); 
    for (int i=0;i<num_children;i++){
        waitpid(ids[i],EXIT_SUCCESS,0);
        clock_gettime(1,&(time[i].final));
        double elapsed_time = (time[i].final.tv_sec - time[i].start.tv_sec) +
                    (time[i].final.tv_nsec - time[i].start.tv_nsec) / 1e9;
        char j[30];
        sprintf(j,"%d:%lf",scheduling[i],elapsed_time);
        fprintf(generator,"%s\n",j);
    }

    printf("File generated........\n");
    return 0;
}