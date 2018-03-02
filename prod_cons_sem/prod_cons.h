#ifndef __PRODCONS__
#define __PRODCONS__

#define NBR_SLOT 10 // Number init of slot in the semaphore
#define NBR_PROD 200// Number of producers thread
#define NBR_CONS 200// Number of consumer thread
#define MAX_RAND_NBR 10// Maximum value of range of the random value
#define MIN_RAND_NBR 0// Minimum value of range of the random value
#define THREAD_NAME_MAX_LEN 16// Length of the name of the thread
#define MULTIPLE_OF_SLEEPTIME 1000000/* Multiple of sleepTime: to convert in ms
                                     or sec*/
#define NBR_OF_TEST 10/* Define the number of times the function do_something
                    will be run in the main*/

#include <stdbool.h> // for boolean using
#include <pthread.h> // for the creation/init/destroy of threads
#include <semaphore.h> // for the creation/init/destroy of semaphore

extern bool semActive; // boolean that will active production consumption
extern pthread_mutex_t mutex;
extern sem_t emptySlot;
extern sem_t fullSlot;
extern int nbr_EmptySlot;
extern int nbr_FullSlot;
extern int nbr_suppliedProduct;
extern int nbr_consummateProduct;
extern int nbr_notConsummateProduct;

/*fonction do_something that simulate a fonction that "do something" in a
random time and return the sleepTime value generated*/
int do_something();

/*Function produce that simulate something produced*/
int produce();

/*Function consume that simulate something produced: in this case similar to
produce() function but could be different in another case*/
int consummate();

/*Fonction producer: it produces something (data), then place the results of it
in an area accessible by the consumer (to be read later by the consumer*/
void *producer_callBack(void *arg);

/*Fonction consummer: Read and use the data produced by the producer*/
void *consumer_callBack(void *arg);

#endif

