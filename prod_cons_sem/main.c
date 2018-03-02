#define _GNU_SOURCE // in order to use set name without warning

#include <stdio.h>
#include <stdlib.h>
#include "prod_cons.h"

bool semActive = false;
pthread_mutex_t mutex;
sem_t emptySlot;
sem_t fullSlot;
int nbr_EmptySlot = NBR_SLOT; // At the begin every slot is empty
int nbr_FullSlot = 0; // At the begin number of full slot is null
int nbr_suppliedProduct = 0;
int nbr_consummateProduct = 0;
int nbr_notConsummateProduct = 0;

int main()
{
    int nbr_usingBySlot[NBR_SLOT] = 0;
    //Declaration of the threads, semaphore and variables
    int i = 0;
    pthread_t consumers[NBR_CONS];
    pthread_t producers[NBR_PROD];
    char ProducerName[THREAD_NAME_MAX_LEN];
    char ConsumerName[THREAD_NAME_MAX_LEN];
    semActive = true;

    /*Initialisation of the semaphore fullSlot, initialy, there is no full
    slot*/
    sem_init(&fullSlot, 0, 0);

    /*Initialisation of the semaphore emptySlot, initialy, every slot is empty*/
    sem_init(&emptySlot, 0, NBR_SLOT);

    /*Initialisation of the mutex that will be used to protect each slot*/
    pthread_mutex_init(&mutex, NULL);

    /*Creation of the producer threads*/
    for (i = 0; i < NBR_PROD; i++)
    {
        pthread_create(producers + i, NULL, producer_callBack, NULL);

        // Set a name to the producers
        sprintf(ProducerName, "Producer %d", i + 1);
        pthread_setname_np(producers[i], ProducerName);
    }

    /*Creation of the consumer threads*/
    for (i = 0; i < NBR_CONS; i++)
    {
        pthread_create(consumers + i, NULL, consumer_callBack, NULL);

        // Set a name to the consumers
        sprintf(ConsumerName, "Consumer %d", i + 1);
        pthread_setname_np(consumers[i], ConsumerName);
    }

    /*Run the function do_something the number of times of NBR_OF_TEST*/
    for (i = 0; i <= NBR_OF_TEST; i++)
    {
        do_something();
    }
    semActive = false;

    /*Destroy the semaphores after using*/
    sem_destroy(&emptySlot);
    sem_destroy(&fullSlot);

    /*Destroy mutex after using*/
    pthread_mutex_destroy(&mutex);

    /*Display number of product supplied*/
    printf("Number of supplied products %d\n", nbr_suppliedProduct);

    /*Display number of product consummate*/
    printf("Number of consummate products %d\n", nbr_consummateProduct);

    /*Display number of product non-consummate*/
    nbr_notConsummateProduct = nbr_suppliedProduct   - nbr_consummateProduct;
    printf("Number of non consummate products %d\n", nbr_notConsummateProduct);

    /*Display number of using by slot*/

    return 0;
}
