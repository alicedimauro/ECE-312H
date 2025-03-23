#include "Recursion.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* Return the sum of the elements in array x[]
 * there are n elements in x[] (x[0].. x[n-1])
 * solve the problem recursively and
 * use an "n-1" type of decomposition
 *
 * NOTE: This function will NOT be graded and is merely provided for practice.
 */
int sumNums1(int x[], int n, int *calls) {
  *calls += 1;
  // TODO: Your code here
  return 0;
}

/*
 * Return the sum of the elements in array x[]
 * there are n elements in x[] (x[0].. x[n-1])
 * n may be either odd or even
 * solve the problem recursively and
 * use an "n/2" type of decomposition
 *
 * NOTE: This function will NOT be graded and is merely provided for practice.
 */
int sumNums2(int x[], int n, int *calls) {
  *calls += 1;
  // TODO: Your code here
  return 0;
}

/*
 * Write a recursive function that revereses a positive n-digit integer x.
 * For example, if x = 12345, the function should return 54321.
 * Hint: use pow() from math.h
 */
int reverse(int x, int n, int *calls) {
  *calls += 1;
  // TODO: Your code here
  return 0;
}

/*
 * Given a linked list, remove all nodes that contain the character val
 * Don't forget to free memory for any nodes you remove
*/
Node* remove_nodes(Node* head, char val, int* calls) {
  *calls += 1;
  // TODO: Your code here
  return head;
}

/* You are given a list of item weights that represent the weight of the ith
 * index item You are also given a maximum weight that your bag can hold.
 * Return the total weight of the subset of items that maximize the total weight
 * of the bag without going over the maximum weight
 */
int knapsack(int weights[], int n, int max_weight, int *calls) {
  *calls += 1;
  // TODO: Your code here
  return 0;
}

// Given a binary tree, return the weight of the least weight path (the path
// with the smallest sum of node values)
int least_weight_path(BinaryNode *root, int *calls) {
  *calls += 1;
  // TODO: Your code here
  return 0;
}

bool is_win(char board[3][3], char player) {
  // (Optional but recommended) TODO: Your code here
  return false;
}

/*
 * Given a tic-tac-toe board, return a Record struct that contains the number of
 * ways that X can win, the number of ways that O can win, and the number of
 * draws from the current board position.
 * The possible values of the board are 'X', 'O', and ' ' (space character for empty)
 */
Record tic_tac_toe(char board[3][3], bool is_x_turn, int *calls) {
  *calls += 1;
  // TODO: Your code here
  return {0, 0, 0};
}
