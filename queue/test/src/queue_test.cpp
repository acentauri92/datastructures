#include "CppUTest/TestHarness.h"

extern "C" {
	#include "queue.h"	
}

// create a test group
TEST_GROUP(queue_test){
   
};

//create a test for that test group
TEST (queue_test, init_queue){
    Queue_t myqueue;
    initQueue(&myqueue);

    LONGS_EQUAL(SIZE, myqueue.front);
}