#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef void (*funcTimer) (void);

funcTimer ptr;

void delay(int number_of_seconds){
    //convert time into mili seconds
    int milli_seconds  = 1000 * number_of_seconds;

    //store start time
    clock_t start_time = clock();

    //loop till required time is not achieved
    while (clock() < start_time + milli_seconds);    
}

void timerstart(int seconds){
    while(1){
        delay(seconds);
        ptr();
    }
}

void settimerCallback(funcTimer cb){
    ptr = cb;
}

void timerCallback(void){   
    printf("It's time!\n");
}

int main(){
    settimerCallback(timerCallback);
    timerstart(1);
    printf("After 1 second!\n");

    return 0;
}

#ifndef __TIMER_H
#define __TIMER_H
void timerstart(int seconds);
void settimerCallback(funcTimer cd);
#endif