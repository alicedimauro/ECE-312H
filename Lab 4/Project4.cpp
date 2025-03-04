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
int inventory_books = 0;
int inventory_dice = 0;
int inventory_figures = 0;
int inventory_towers = 0;

/* Reset the inventory and customer database */
void reset(void) {
    for (int i = 0; i < num_customers; i++) {
        StringDestroy(&customers[i].name);
    }
    num_customers = 0;
    inventory_books = 0;
    inventory_dice = 0;
    inventory_figures = 0;
    inventory_towers = 0;
}

/* Process Inventory */
void processInventory(void) {
    String item;
    int quantity;
    readString(&item);
    readNum(&quantity);
    if (StringIsEqualTo(&item, &StringCreate("Books"))) inventory_books += quantity;
    else if (StringIsEqualTo(&item, &StringCreate("Dice"))) inventory_dice += quantity;
    else if (StringIsEqualTo(&item, &StringCreate("Figures"))) inventory_figures += quantity;
    else if (StringIsEqualTo(&item, &StringCreate("Towers"))) inventory_towers += quantity;
    StringDestroy(&item);
}

/* Process Purchase */
void processPurchase(void) {
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
    
    Customer *customer = NULL;
    for (int i = 0; i < num_customers; i++) {
        if (StringIsEqualTo(&(customers[i].name), &name)) {
            customer = &customers[i];
            break;
        }
    }
    if (!customer && num_customers < MAX_CUSTOMERS) {
        customers[num_customers].name = StringDup(&name);
        customers[num_customers].books = 0;
        customers[num_customers].dice = 0;
        customers[num_customers].figures = 0;
        customers[num_customers].towers = 0;
        customer = &customers[num_customers++];
    }
    
    int *inventory_ptr = NULL, *customer_ptr = NULL;
    if (StringIsEqualTo(&item, &StringCreate("Books"))) { inventory_ptr = &inventory_books; customer_ptr = &customer->books; }
    else if (StringIsEqualTo(&item, &StringCreate("Dice"))) { inventory_ptr = &inventory_dice; customer_ptr = &customer->dice; }
    else if (StringIsEqualTo(&item, &StringCreate("Figures"))) { inventory_ptr = &inventory_figures; customer_ptr = &customer->figures; }
    else if (StringIsEqualTo(&item, &StringCreate("Towers"))) { inventory_ptr = &inventory_towers; customer_ptr = &customer->towers; }
    
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

/* Process Return */
void processReturn(void) {
    String name, item;
    int quantity;
    readString(&name);
    readString(&item);
    readNum(&quantity);
    
    Customer *customer = NULL;
    for (int i = 0; i < num_customers; i++) {
        if (StringIsEqualTo(&(customers[i].name), &name)) {
            customer = &customers[i];
            break;
        }
    }
    if (!customer) {
        printf("Sorry ");
        StringPrint(&name);
        printf(", we do not have you in our database\n");
    } else {
        int *inventory_ptr = NULL, *customer_ptr = NULL;
        if (StringIsEqualTo(&item, &StringCreate("Books"))) { inventory_ptr = &inventory_books; customer_ptr = &customer->books; }
        else if (StringIsEqualTo(&item, &StringCreate("Dice"))) { inventory_ptr = &inventory_dice; customer_ptr = &customer->dice; }
        else if (StringIsEqualTo(&item, &StringCreate("Figures"))) { inventory_ptr = &inventory_figures; customer_ptr = &customer->figures; }
        else if (StringIsEqualTo(&item, &StringCreate("Towers"))) { inventory_ptr = &inventory_towers; customer_ptr = &customer->towers; }
        
        if (inventory_ptr && customer_ptr && *customer_ptr >= quantity) {
            *customer_ptr -= quantity;
            *inventory_ptr += quantity;
        } else {
            printf("%s, you do not have %d ", name.ptr, quantity);
            StringPrint(&item);
            printf("\n");
        }
    }
    
    StringDestroy(&name);
    StringDestroy(&item);
}

/* Process Summarize */
void processSummarize(void) {
    printf("There are %d Books %d Dice %d Figures and %d Towers in inventory\n", inventory_books, inventory_dice, inventory_figures, inventory_towers);
    printf("we have had a total of %d different customers\n", num_customers);
}

