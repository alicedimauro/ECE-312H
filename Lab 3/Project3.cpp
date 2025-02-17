/**
 * NAME:
 * EID:
 * Spring 2025
 * Speight
 */

#include "UTQueue.h"
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h> 
#include <stdlib.h>

/*
 * ALREADY DONE FOR YOU
 * Prints the passed in queue to make it easy to visualize.
 */
void utqueueprint(UTQueue *src) {
  printf("[");
  for (int i = 0; i < src->size - 1; i++)
    printf("%d, ", src->data[i]);
  printf("%d]\n", src->data[src->size - 1]);
}

/*
 * Allocate a UTQueue on the heap.
 * The size of the input array is n.
 * Initialize the queue correctly by copying src
 * Return a pointer to the newly created UTQueue.
 */
UTQueue *utqueuedup(const int *src, int n) { return NULL; }

/*
 * Free all memory associated with the given UTQueue.
 */
void utqueuefree(UTQueue *self) {}
/*
 * Push (enqueue) an integer "value" into the queue.
 */
UTQueue *utqueuepush(UTQueue *src, int value) { return NULL; }

/*
 * Pop (dequeue) an element from the queue
 * should fail an assertion if the queue is empty
 */
int utqueuepop(UTQueue *src) {
  assert(false); // change false to make this assertion fail only if src has 0
                 // elements.
  return NULL;
}

/*
 * Reverses the queue in src.
 */
UTQueue *utqueuerev(UTQueue *src) { return NULL; }

/*
 * combines the elements of UTQueues dst and src INTO dst.
 * src should be deleted after the combination
 */
UTQueue *utqueuecombine(UTQueue *dst, UTQueue *src) { return NULL; }

/*
 * Swap the two queues.
 * q1 should "have" the contents of q2 and vice verse.
 * There is more than one way to do this
 */
void utqueueswap(UTQueue *q1, UTQueue *q2) {}

/*
 * Copy values from src array into dst.
 * Assume dst is a valid UTQueue.
 * src is an array of numbers.
 * Do not allocate any additional storage: only copy as many numbers
 * as will actually fit into the current UTQueue dst.
 * If all of src can fit into dst, leave the remaining ints in dst.
 * return the pointer to dst with the changes.
 */
UTQueue *utqueuecpy(UTQueue *dst, const int *src, int n) { return NULL; }
