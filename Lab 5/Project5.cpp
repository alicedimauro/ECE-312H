// Set <Project5.cpp>
// ECE 312 Project 5 submission by
// Alice Di Mauro
// ad55559
// Slip days used: <0>
// Fall 2023

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Set.h"

/*
 * Several of the required functions have been written already
 * You may use these functions as-is or you may modify them in any way.
 * Please NOTE, you are responsible for ensuring that the functions work correctly in
 * your project solution. Just because the function works correctly in my solution does
 * NOT mean that the function will work correctly in yours.
 */

/*
 * Design NOTES:
 *
 * The design provided in this starter kit assumes
 * (1) empty sets will be represented with length == 0 and elements == nullptr (i.e., address 0)
 * (2) amortized doubling is not used, and capacity is ignored/unused. Functions should assume that
 * the amount of storage available in the elements[] array is equal to length
 */



/* done for you already */
void destroySet(Set* self) {
    free(self->elements);
}

/* done for you already */
void createEmptySet(Set* self) {
    self->len = 0;
    self->elements = nullptr;
}

/* done for you already */
void createSingletonSet(Set* self, int x) {
    self->elements = (int*) malloc(sizeof(int));
    self->elements[0] = x;
    self->len = 1;
}

/* done for you already */
void createCopySet(Set* self, const Set* other) {
    self->elements = (int*) malloc(other->len * sizeof(int));
    for (int k = 0; k < other->len; k += 1) {
        self->elements[k] = other->elements[k];
    }
    self->len = other->len;
}

/* done for you already */
void assignSet(Set* self, const Set* other) {
    if (self == other) { return; }

    destroySet(self);
    createCopySet(self, other);
}

/* return true if x is an element of self
Check if an element is in the set using binary search */
bool isMemberSet(const Set* self, int x) {
    int left = 0, right = self->len - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (self->elements[mid] == x) return true;
        if (self->elements[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

/*
 * add x as a new member to this set.
 * If x is already a member, then self should not be changed
 * Be sure to restore the design invariant property that elemnts[] remains sorted
 * (yes, you can assume it is sorted when the function is called, that's what an invariant is all about)
 */
void insertSet(Set* self, int x) {
    if (isMemberSet(self, x)) return; // Do not insert duplicate elements
    self->elements = (int*) realloc(self->elements, (self->len + 1) * sizeof(int));
    int i = self->len - 1;
    while (i >= 0 && self->elements[i] > x) { // Shift the elements to maintain sorted order
        self->elements[i + 1] = self->elements[i];
        i--;
    }
    self->elements[i + 1] = x;
    self->len++;
}


/*
 * don't forget: it is OK to try to remove an element
 * that is NOT in the set.
 * If 'x' is not in the set 'self', then
 * removeSet should do nothing (it's not an error)
 * Otherwise, ('x' IS in the set), remove x. Be sure to update self->length
 * It is not necessary (nor recommended) to call malloc -- if removing an element means the
 * array on the heap is "too big", that's almost certainly OK, and reallocating a smaller array
 * is almost definitely NOT worth the trouble
 */
void removeSet(Set* self, int x) {
    int left = 0, right = self->len - 1, index = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (self->elements[mid] == x) {
            index = mid;
            break;
        }
        if (self->elements[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    if (index == -1) return; // Element was not found
    for (int i = index; i < self->len - 1; i++) {
        self->elements[i] = self->elements[i + 1]; // Shift all elements to the left
    }
    self->len--;
}

/* done for you already */
void displaySet(const Set* self) {
    int k;

    printf("{");

    if (self->len == 0) {
        printf("}");
    }
    else {
        for (k = 0; k < self->len; k += 1) {
            if (k < self->len - 1) {
                printf("%d,", self->elements[k]);
            } else {
                printf("%d}", self->elements[k]);
            }
        }
    }
}

/* return true if self and other have exactly the same elements */
bool isEqualToSet(const Set* self, const Set* other) {
    if (self->len != other->len) return false;
    for (int i = 0; i < self->len; i++) {
        if (self->elements[i] != other->elements[i]) return false;
    }
    return true;
}

/* return true if every element of self is also an element of other */
bool isSubsetOf(const Set* self, const Set* other) {
    int i = 0, j = 0;
    while (i < self->len && j < other->len) {
        if (self->elements[i] == other->elements[j]) i++; // Checking if two sets are equal 
        j++;
    }
    return i == self->len;
}

/* done for you */
bool isEmptySet(const Set* self) {
    return self->len == 0;
}

/* remove all elements from self that are not also elements of other */
void intersectFromSet(Set* self, const Set* other) {
    int* newElements = (int*) malloc(self->len * sizeof(int));
    int k = 0;
    for (int i = 0, j = 0; i < self->len && j < other->len;) {
        if (self->elements[i] < other->elements[j]) i++;
        else if (self->elements[i] > other->elements[j]) j++;
        else newElements[k++] = self->elements[i++], j++; // store the interse
    }
    free(self->elements);
    self->elements = newElements;
    self->len = k;
}

/* remove all elements from self that are also elements of other */
void subtractFromSet(Set* self, const Set* other) {
    int* newElements = (int*) malloc(self->len * sizeof(int));
    int k = 0, i = 0, j = 0;

    while (i < self->len) {
        if (j < other->len && self->elements[i] == other->elements[j]) {
            i++; // Skip element in self if it exists in other
            j++; // Move j forward to compare next element
        } else if (j < other->len && self->elements[i] > other->elements[j]) {
            j++; // Move j forward without affecting i
        } else {
            newElements[k++] = self->elements[i++]; // Add element to result
        }
    }

    free(self->elements);
    self->elements = newElements;
    self->len = k;
}

/* add all elements of other to self (obviously, without creating duplicate elements) */
void unionInSet(Set* self, const Set* other) {
    int* newElements = (int*) malloc((self->len + other->len) * sizeof(int));
    int i = 0, j = 0, k = 0;
    while (i < self->len || j < other->len) {
        if (i < self->len && (j >= other->len || self->elements[i] < other->elements[j])) {
            newElements[k++] = self->elements[i++];
        } else if (j < other->len && (i >= self->len || self->elements[i] > other->elements[j])) {
            newElements[k++] = other->elements[j++];
        } else {
            newElements[k++] = self->elements[i]; i++, j++; // Merge common elements
        }
    }
    free(self->elements);
    self->elements = newElements;
    self->len = k;
}
