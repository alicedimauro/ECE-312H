#ifndef _Invent_h
#define _Invent_h 1

#include "MyString.h"

typedef struct Customer {
  String name;
  int books;
  int dice;
  int figures;
  int towers;
} Customer;

/* read a string from the input file.  Creates a new string (you must call
 * destroyString) */
void readString(String *);

/* read one number form the input file */
void readNum(int *);

/* For each of the following four functions, we have read one word
 * from the input file, either "Inventory" "Purchase" "Return" or "Summarize"
 * In each case, the function should read the remaining input from
 * the input file (using readString and readNum) and
 * process the command
 */
void processInventory(void);
void processPurchase(void);
void processSummarize(void);
void processReturn(void);

/* reset the database (inventory, customer info, etc). */
void reset(void);

#endif /* _Invent_h */
