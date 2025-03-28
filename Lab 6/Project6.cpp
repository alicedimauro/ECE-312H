// Set <Project6.cpp>
// ECE 312 Project 6 submission by
// Alice Di Mauro
// ad55559
// Slip days used: <0>
// Spring 2025
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
  // TODO: Your code here
  *calls += 1; // Increment the number of calls
  if (n == 0) return 0; // Base case: no elements
  return x[n - 1] + sumNums1(x, n - 1, calls); // recursive call on remaining elements
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
  // TODO: Your code here
  *calls += 1; // same as previous function
  if (n == 0) return 0;
  if (n == 1) return x[0]; // another base case? if one element return it
  int mid = n / 2; // Divide the array into two halves
  return sumNums2(x, mid, calls) + sumNums2(x + mid, n - mid, calls); // sum both halves
}

/*
 * Write a recursive function that revereses a positive n-digit integer x.
 * For example, if x = 12345, the function should return 54321.
 * Hint: use pow() from math.h
 */
int reverse(int x, int n, int *calls) {
  // TODO: Your code here
  *calls += 1;
  if (n == 1) return x; // Return single digit number (base case)
  return (x % 10) * pow(10, n - 1) + reverse(x / 10, n - 1, calls); // Move the last digit to the front
}

/*
 * Given a linked list, remove all nodes that contain the character val
 * Don't forget to free memory for any nodes you remove
*/
Node* remove_nodes(Node* head, char val, int* calls) {
  // TODO: Your code here
  *calls += 1;
  if (!head) return NULL; // Base case: empty list
  head->next = remove_nodes(head->next, val, calls); // Recursive call to process next node
  if (head->data == val) { // If current node matches the target value
    Node* temp = head->next; // First save the next node
    free(head); // Then free the current node
    return temp; // Return the next node as the new head
  }
  return head; // Return the current node if not removed
}

/* You are given a list of item weights that represent the weight of the ith
 * index item You are also given a maximum weight that your bag can hold.
 * Return the total weight of the subset of items that maximize the total weight
 * of the bag without going over the maximum weight
 */
int knapsack(int weights[], int n, int max_weight, int *calls) {
  // TODO: Your code here
  *calls += 1;
  if (n == 0 || max_weight == 0) return 0; // No items or full capacity?
  if (weights[n - 1] > max_weight) return knapsack(weights, n - 1, max_weight, calls); // Skip because it's too heavy
  
  // Either include the current item or exclude it, choose the maximum value
  int include = weights[n - 1] + knapsack(weights, n - 1, max_weight - weights[n - 1], calls);
  int exclude = knapsack(weights, n - 1, max_weight, calls);
  
  return (include > exclude) ? include : exclude;
}

// Given a binary tree, return the weight of the least weight path (the path
// with the smallest sum of node values)
int least_weight_path(BinaryNode *root, int *calls) {
  // TODO: Your code here
  *calls += 1;
  if (!root) return 0; // The tree is empty
  if (!root->left && !root->right) return root->data; // It's a leaf node

  if (!root->left) return root->data + least_weight_path(root->right, calls); // If one child, follow the not NULL path
  if (!root->right) return root->data + least_weight_path(root->left, calls);

  int left = least_weight_path(root->left, calls); // Recusively call left + right, return path sum
  int right = least_weight_path(root->right, calls);
  return root->data + ((left < right) ? left : right);
}

bool is_win(char board[3][3], char player) {
  // (Optional but recommended) TODO: Your code here
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true; // row wins
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true; // columm wins
  }
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true; // check the diagnols
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
  return false;
}

/*
 * Given a tic-tac-toe board, return a Record struct that contains the number of
 * ways that X can win, the number of ways that O can win, and the number of
 * draws from the current board position.
 * The possible values of the board are 'X', 'O', and ' ' (space character for empty)
 */
Record tic_tac_toe(char board[3][3], bool is_x_turn, int *calls) {
  // TODO: Your code here
  *calls += 1;
  if (is_win(board, 'X')) return {1, 0, 0}; // X number of wins
  if (is_win(board, 'O')) return {0, 0, 1}; // O number of wins

  bool is_draw = true;
  Record result = {0, 0, 0};

  for (int i = 0; i < 3; i++) { // Check all possible moves
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ') { // There's an empty space
        is_draw = false;
        board[i][j] = is_x_turn ? 'X' : 'O'; // Place the current player's move
        Record temp = tic_tac_toe(board, !is_x_turn, calls); // Recursive call to check the next move
        result.x_wins += temp.x_wins;
        result.o_wins += temp.o_wins;
        result.draws += temp.draws;
        board[i][j] = ' '; // Undo move (backtrack)
      }
    }
  }
  if (is_draw) return {0, 1, 0}; // No more moves left to do, it's a draw!
  return result;
}
