/**
 * NAME:Alice Di Mauro
 * EID: ad55559
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
UTQueue *utqueuedup(const int *src, int n) {
// { return NULL; }
  UTQueue *queue = (UTQueue *)malloc(sizeof(UTQueue));
  // Allocated queue on heap
  // Assert(queue != NULL); // 
  queue->size = n;
  // Initialize size
  queue->data = (int *)malloc(n * sizeof(int));
  // Assert(queue->data != NULL);
  for (int i = 0; i < n; i++) {
    queue->data[i] = src[i];
    // Copy of source
  }
  return queue;
  // Returns pointer to queue
}

/*
 * Free all memory associated with the given UTQueue.
 */
void utqueuefree(UTQueue *self) {
  if (self) {
    free(self->data);
    // First deallocate data
    free(self);
    // Now deallocate queue itself 
  }
}


/*
 * Push (enqueue) an integer "value" into the queue.
 */

UTQueue *utqueuepush(UTQueue *src, int value) {
//{ return NULL; }
  src->data = (int *)realloc(src->data, (src->size + 1) * sizeof(int));
  // Resize data to make sure the new data fits
  // assert(src->data != NULL);
  src->data[src->size] = value;
  // Must add the new value at the end of the queue
  src->size++;
  // Make sure to account that size has increased by one
  return src;
  // Returns the pointer to the new queue
}

/*
 * Pop (dequeue) an element from the queue
 * should fail an assertion if the queue is empty
 */
int utqueuepop(UTQueue *src) {
//  assert(false); // change false to make this assertion fail only if src has 0
                 // elements.
  assert(src->size > 0);
  int value = src->data[0];
  // Must have the value at the front of the queue
  for (int i = 1; i < src->size; i++) {
    src->data[i - 1] = src->data[i];
    // Need to shift all the elements to the left one spot to account for the missing value
  }
  src->size--;
  // The queue is now one element smaller
  src->data = (int *)realloc(src->data, src->size * sizeof(int));
  // The queue size has changed so reallocate memory appropriately 
  return value;
  // Returns the value of the integer popped from the queue (temporary place holder)
             
//  return NULL;
}

/*
 * Reverses the queue in src.
 */
UTQueue *utqueuerev(UTQueue *src) {
//{ return NULL; } Put this back? But function should return pointer no?
  for (int i = 0, j = src->size - 1; i < j; i++, j--) {
  // ^^ Please work pleas work please let me use two pointers in the same loop
    int temp = src->data[i];
    // Need a temporary value to help switch the values
    src->data[i] = src->data[j];
    // Using two pointers to move the data around 
    src->data[j] = temp;
  }
  return src;
  // Returns the pointer to the reversed queue
}


/*
 * combines the elements of UTQueues dst and src INTO dst.
 * src should be deleted after the combination
 */
UTQueue *utqueuecombine(UTQueue *dst, UTQueue *src) {
// { return NULL; }
  dst->data = (int *)realloc(dst->data, (dst->size + src->size) * sizeof(int));
  // Size of dst has significantly increased now that it holds the combined queue's; make sure it's accounting for that
  // assert(dst->data != NULL);
  for (int i = 0; i < src->size; i++) {
    dst->data[dst->size + i] = src->data[i];
    // Add the src queue elements to the end of the dst queue
  }
  dst->size += src->size;
  // dst queue has increased so update its size
  utqueuefree(src);
  // NEED TO FREE SRC BECAUSE WE NO LONGER NEED IT'S QUEUE
  return dst;
  // Returns pointer to new combined queue 
}


/*
 * Swap the two queues.
 * q1 should "have" the contents of q2 and vice verse.
 * There is more than one way to do this
 */
void utqueueswap(UTQueue *q1, UTQueue *q2) {
  UTQueue temp = *q1;
  // Need a temporary queue to help swap pointers
  *q1 = *q2;
  *q2 = temp;
  // This feels too easy
}

/*
 * Copy values from src array into dst.
 * Assume dst is a valid UTQueue.
 * src is an array of numbers.
 * Do not allocate any additional storage: only copy as many numbers
 * as will actually fit into the current UTQueue dst.
 * If all of src can fit into dst, leave the remaining ints in dst.
 * return the pointer to dst with the changes.
 */
UTQueue *utqueuecpy(UTQueue *dst, const int *src, int n) {
// { return NULL; }
  int minSize = (dst->size < n) ? dst->size : n;
  // Can I use a ternary operator here? Shoutout Zybooks
  // This should determine which size is smaller right?
  for (int i = 0; i < minSize; i++) {
    dst->data[i] = src[i];
    // Just overwrite the dst elements until you run out of n or run out of space in dst
  }
  return dst;
  // Return a pointer to the new queue
}

