#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //using of usleep
#include <time.h> // for the using of srand()
#include "prod_cons.h"

/*fonction do_something that simulate a fonction that "do something" in a
random time and return the sleepTime value generated*/
int do_something()
{
    int sleepTime = 0;

    // generate a random number
    srand(time(NULL));
    sleepTime = rand()% (MAX_RAND_NBR - MIN_RAND_NBR + 1) + MIN_RAND_NBR;

    // usleep while the duration of the random number generated
    usleep(sleepTime * MULTIPLE_OF_SLEEPTIME);

    return sleepTime;
}

/*Function produce that simulate something produced*/
int produce()
{
    int myProduction;
    //printf("I produce something\n");
    myProduction = do_something();
    return myProduction;
}

/*Function consume that simulate something produced: in this case similar to
produce() function but could be different in another case*/
int consummate()
{
    int myComsumption;
    printf("I consume something\n");
    myComsumption = do_something();
    return myComsumption;
}

/*Fonction producer: it produces something (data), then place the results of it
in an area accessible by the consumer (to be read later by the consumer*/
void *producer_callBack(void *arg)
{
    // Declare something to product
    int product;

    while(semActive)
    {
        product = produce(); // product something: simulate with usleep()
        sem_wait(&emptySlot);// Wait for an empty slot

        /*protect the slot in order to be used by one producter*/
        pthread_mutex_lock(&mutex); // lock the slot
        printf("Producer : Insert my product in an empty slot\n");
        pthread_mutex_unlock(&mutex); // unlock the slot
        nbr_FullSlot++;
        nbr_EmptySlot--;
        nbr_suppliedProduct++;
        sem_post(&fullSlot);// there is one more slot which is full
    }
}

/*Fonction consummer: Read and use the data produced by the producer*/
void *consumer_callBack(void *arg)
{
    // Declare something to be consummated
    int consumption;

    while(semActive)
    {
        sem_wait(&fullSlot);// Wait for a full slot
        /*protect the slot in order to be used by one consumer*/
        pthread_mutex_lock(&mutex); // lock the slot
        consumption = consummate(); // consummate something: simulate with usleep
        pthread_mutex_unlock(&mutex); // unlock the slot
        nbr_FullSlot--;
        nbr_EmptySlot++;
        nbr_consummateProduct++;
        sem_post(&emptySlot);// One more slot is empty
    }
}

