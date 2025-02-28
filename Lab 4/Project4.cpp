// ECE 312(H) PA4
// Alice Di Mauro
// ad55559
// Spring 2025
// Speight 

#include "Invent.h"
#include "MyString.h"
#include <assert.h>
#include <stdio.h>

#define MAX_CUSTOMERS 1000
Customer customers[MAX_CUSTOMERS];  
int num_customers = 0;

/* you'll probably need several more global variables */
/* and of course, you have a few functions to write */
int inventory_books = 0;
int inventory_dice = 0;
int inventory_figures = 0;
int inventory_towers = 0;

/* clear the inventory and reset the customer database to empty */
void reset(void) { /* your code here */
    num_customers = 0;
    inventory_books = 0;
    inventory_dice = 0;
    inventory_figures = 0;
    inventory_towers = 0;}

/* Personal function to aid given functions
 Find or create a customer */
Customer* find_or_create_customer(String *name) {
    for (int i = 0; i < num_customers; i++) {
        if (StringIsEqualTo(&(customers[i].name), name)) {
            return &customers[i];
        }
    }
    if (num_customers < MAX_CUSTOMERS) {
        customers[num_customers].name = StringDup(name);
        customers[num_customers].books = 0;
        customers[num_customers].dice = 0;
        customers[num_customers].figures = 0;
        customers[num_customers].towers = 0;
        return &customers[num_customers++];
    }
    return NULL;
}

/* Find an existing customer */
Customer* find_customer(String *name) {
    for (int i = 0; i < num_customers; i++) {
        if (StringIsEqualTo(&(customers[i].name), name)) {
            return &customers[i];
        }
    }
    return NULL;
}


void processSummarize() {
    printf("Inventory: Books=%d Dice=%d Figures=%d Towers=%d\n", inventory_books, inventory_dice, inventory_figures, inventory_towers);
    printf("Number of Customers: %d\n", num_customers);
    
    Customer *max_books = NULL, *max_dice = NULL, *max_figures = NULL, *max_towers = NULL;
    for (int i = 0; i < num_customers; i++) {
        if (!max_books || customers[i].books > max_books->books) max_books = &customers[i];
        if (!max_dice || customers[i].dice > max_dice->dice) max_dice = &customers[i];
        if (!max_figures || customers[i].figures > max_figures->figures) max_figures = &customers[i];
        if (!max_towers || customers[i].towers > max_towers->towers) max_towers = &customers[i];
    }
    
    printf("Max Buyers:\n");
    if (max_books && max_books->books > 0) { printf("Books: "); StringPrint(&max_books->name); printf(" %d\n", max_books->books); }
    if (max_dice && max_dice->dice > 0) { printf("Dice: "); StringPrint(&max_dice->name); printf(" %d\n", max_dice->dice); }
    if (max_figures && max_figures->figures > 0) { printf("Figures: "); StringPrint(&max_figures->name); printf(" %d\n", max_figures->figures); }
    if (max_towers && max_towers->towers > 0) { printf("Towers: "); StringPrint(&max_towers->name); printf(" %d\n", max_towers->towers); }
}

void processPurchase() {
    String name, item;
    int quantity;
    readString(&name);
    readString(&item);
    readNum(&quantity);
    
    if (quantity <= 0) {
        StringDestroy(&name);
        StringDestroy(&item);
        return;
    }
    
    Customer *customer = find_or_create_customer(&name);
    if (!customer) {
        StringDestroy(&name);
        StringDestroy(&item);
        return;
    }
    
    int *inventory_ptr = NULL, *customer_ptr = NULL;
    if (StringIsEqualTo(&item, &inventory)) { inventory_ptr = &inventory_books; customer_ptr = &customer->books; }
    else if (StringIsEqualTo(&item, &dice)) { inventory_ptr = &inventory_dice; customer_ptr = &customer->dice; }
    else if (StringIsEqualTo(&item, &figures)) { inventory_ptr = &inventory_figures; customer_ptr = &customer->figures; }
    else if (StringIsEqualTo(&item, &towers)) { inventory_ptr = &inventory_towers; customer_ptr = &customer->towers; }
    
    if (inventory_ptr && customer_ptr) {
        if (*inventory_ptr >= quantity) {
            *inventory_ptr -= quantity;
            *customer_ptr += quantity;
        } else {
            printf("Sorry ");
            StringPrint(&name);
            printf(", we only have %d ", *inventory_ptr);
            StringPrint(&item);
            printf("\n");
        }
    }
    
    StringDestroy(&name);
    StringDestroy(&item);

}



void processReturn() {
    String name, item;
    int quantity;
    readString(&name);
    readString(&item);
    readNum(&quantity);
    
    Customer *customer = find_customer(&name);
    if (!customer) {
        printf("%s, you do not have %d ", name.ptr, quantity);
        StringPrint(&item);
        printf("\n");
        StringDestroy(&name);
        StringDestroy(&item);
        return;
    }
    
    int *customer_ptr = NULL, *inventory_ptr = NULL;
    if (StringIsEqualTo(&item, &inventory)) { customer_ptr = &customer->books; inventory_ptr = &inventory_books; }
    else if (StringIsEqualTo(&item, &dice)) { customer_ptr = &customer->dice; inventory_ptr = &inventory_dice; }
    else if (StringIsEqualTo(&item, &figures)) { customer_ptr = &customer->figures; inventory_ptr = &inventory_figures; }
    else if (StringIsEqualTo(&item, &towers)) { customer_ptr = &customer->towers; inventory_ptr = &inventory_towers; }
    
    if (customer_ptr && inventory_ptr && *customer_ptr >= quantity) {
        *customer_ptr -= quantity;
        *inventory_ptr += quantity;
    } else {
        printf("%s, you do not have %d ", name.ptr, quantity);
        StringPrint(&item);
        printf("\n");
    }
    
    StringDestroy(&name);
    StringDestroy(&item);
}

void processInventory() {
    String item;
    int quantity;
    readString(&item);
    readNum(&quantity);
    if (StringIsEqualTo(&item, &inventory)) inventory_books += quantity;
    else if (StringIsEqualTo(&item, &dice)) inventory_dice += quantity;
    else if (StringIsEqualTo(&item, &figures)) inventory_figures += quantity;
    else if (StringIsEqualTo(&item, &towers)) inventory_towers += quantity;
    StringDestroy(&item);

}
