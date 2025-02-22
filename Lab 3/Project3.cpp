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
assert(queue != NULL);
queue->size = n;
queue->data = (int *)malloc(n * sizeof(int));
assert(queue->data != NULL);
for (int i = 0; i < n; i++) {
    queue->data[i] = src[i];
}
return queue;
}

/*
 * Free all memory associated with the given UTQueue.
 */
void utqueuefree(UTQueue *self) {
if (self) {
 free(self->data);
 free(self);
}
}


/*
 * Push (enqueue) an integer "value" into the queue.
 */

UTQueue *utqueuepush(UTQueue *src, int value) {
//{ return NULL; }
src->data = (int *)realloc(src->data, (src->size + 1) * sizeof(int));
    assert(src->data != NULL);
    src->data[src->size] = value;
    src->size++;
    return src;
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
for (int i = 1; i < src->size; i++) {
    src->data[i - 1] = src->data[i];
 }
 src->size--;
 src->data = (int *)realloc(src->data, src->size * sizeof(int));
 return value;
             
//  return NULL;
}

/*
 * Reverses the queue in src.
 */
UTQueue *utqueuerev(UTQueue *src) {
//{ return NULL; } Put this back? But function should return pointer no?
for (int i = 0, j = src->size - 1; i < j; i++, j--) {
  int temp = src->data[i];
  src->data[i] = src->data[j];
  src->data[j] = temp;
}
return src;
}


/*
 * combines the elements of UTQueues dst and src INTO dst.
 * src should be deleted after the combination
 */
UTQueue *utqueuecombine(UTQueue *dst, UTQueue *src) {
// { return NULL; }
dst->data = (int *)realloc(dst->data, (dst->size + src->size) * sizeof(int));
    assert(dst->data != NULL);
    for (int i = 0; i < src->size; i++) {
        dst->data[dst->size + i] = src->data[i];
    }
    dst->size += src->size;
    utqueuefree(src);
    return dst;
}


/*
 * Swap the two queues.
 * q1 should "have" the contents of q2 and vice verse.
 * There is more than one way to do this
 */
void utqueueswap(UTQueue *q1, UTQueue *q2) {
UTQueue temp = *q1;
    *q1 = *q2;
    *q2 = temp;
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
    for (int i = 0; i < minSize; i++) {
        dst->data[i] = src[i];
    }
    return dst;
}

