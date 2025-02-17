// Queue ADT demonstration file main.cpp
#include "UTQueue.h"
#include <stdio.h>
#include <stdlib.h>

void testStage1(void) {
  const int dataOne[] = {1, 2, 3, 4, 5, 6};
  UTQueue *queueOne = utqueuedup(dataOne, 6);
  utqueueprint(queueOne);

  // utqueuefree(queueOne);
  // utqueueprint(queueOne); // Bad things can happen here if trying to read
  // from freed memory
  queueOne = utqueuepush(queueOne, 7);
  utqueueprint(queueOne);

  int valueOne = utqueuepop(queueOne);
  utqueueprint(queueOne);

  queueOne = utqueuerev(queueOne);
  utqueueprint(queueOne);

  const int dataTwo[] = {3, 4, 5, 6, 7};
  UTQueue *queueTwo = utqueuedup(dataTwo, 5);
  utqueueprint(queueTwo);

  queueOne = utqueuecombine(queueOne, queueTwo);
  // utqueueprint(queueTwo); // bad things can also happen here because combine
  // should free queuetwo
  utqueueprint(queueOne);

  const int dataThree[] = {1, 1, 1, 1, 1};
  UTQueue *queueThree = utqueuedup(dataThree, 5);
  utqueueprint(queueThree);

  printf("Queue one: ");
  utqueueprint(queueOne);
  printf("Queue two: ");
  utqueueprint(queueThree);
  printf("swapping\n");
  utqueueswap(queueOne, queueThree);
  printf("Queue one: ");
  utqueueprint(queueOne);
  printf("Queue two: ");
  utqueueprint(queueThree);

  const int copyOne[] = {0, 1, 2, 3};
  queueOne = utqueuecpy(queueOne, copyOne, 4);
  utqueueprint(queueOne);
  const int copyTwo[] = {5, 80, 200, 11111, 42, 21};
  queueOne = utqueuecpy(queueOne, copyTwo, 6);
  utqueueprint(queueOne);

  utqueuefree(queueOne);
  utqueuefree(queueThree);
}

int main(void) {
  testStage1();
  return 0;
}
