#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> //library POSIX (Sleep)
#include<pthread.h> //library POSIX threads

//Decalre callback_t function is a pointer function no parameter no return value
typedef void (*callback_t) (void);

//create struct infor for timer 
typedef struct{
    int interval; //timer wait (s)
    callback_t callback; // function called after end interval
} timer_infor_t;

//use a global variable to control program pause or run or exit
volatile int is_running = 1; // 1: running, 0: paused
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; //use mutex to certain about asychronus when running or paused

//create a function run in each thread
void* timer_thread(void *arg){
    timer_infor_t* info = (timer_infor_t*) arg;
    while(1){
        pthread_mutex_lock(&mutex);
        while(!is_running){
            pthread_mutex_unlock(&mutex);
            usleep(100000); //sleep for 100ms avoid busy waiting
            pthread_mutex_lock(&mutex);
        }
        pthread_mutex_unlock(&mutex);

        sleep(info->interval); //wait (s)
        info->callback(); //call function callback
    }
    return NULL;
}

//Define functions callback 

void deviot_callback(){
    printf("DEVIOT.VN\n");
    fflush(stdout); //Show info immediately to display
}

void abcd_callback(){
    printf("ABCD\n");
    fflush(stdout); //Show info immediately to display
}

void HieuNe_callback(){
    printf("HieuNe.VN\n");
    fflush(stdout); //Show info immediately to display
}

int main(){
    pthread_t tid1, tid2, tid3; //save ID 3 threads

    //Init infor for 3 timer need
    timer_infor_t t1 = {
        .interval = 1,
        .callback = deviot_callback
    };

    timer_infor_t t2 = {
        .interval = 2,
        .callback = abcd_callback
    };

    timer_infor_t t3 = {
        .interval = 3,
        .callback = HieuNe_callback
    };

    //Create thread to run requires
    if(pthread_create(&tid1, NULL, timer_thread, &t1) != 0){
        perror("pthread_create t1"); //show error if not create
        exit(EXIT_FAILURE);
    }

    if(pthread_create(&tid2, NULL, timer_thread, &t2) != 0){
        perror("pthread_create t2"); //show error if not create
        exit(EXIT_FAILURE);
    }

    if(pthread_create(&tid3, NULL, timer_thread, &t3) != 0){
        perror("pthread_create t3"); //show error if not create
        exit(EXIT_FAILURE);
    }

    //Control program
    char command;
    while(1){
        printf("Enter 'p' to pause, 'r' to resume, 'q' to quit: ");
        scanf(" %c", &command);

        if(command == 'p'){
            pthread_mutex_lock(&mutex);
            is_running = 0; //status pause
            pthread_mutex_unlock(&mutex);
        }else if(command == 'r'){
            pthread_mutex_lock(&mutex);
            is_running = 1; //status running
            pthread_mutex_unlock(&mutex);
        }else if(command == 'q'){
            printf("Exiting program....!\n");
            exit(EXIT_SUCCESS);
        }else{
            printf("Not Valid! Prepare Exit Program...\n");
        }
    }

    //wait for threads end (this is no stop) 
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);

    return 0;
}