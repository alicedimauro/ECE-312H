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

void processInventory(void) {
    String item;
    int quantity;
    readString(&item);
    readNum(&quantity);

    String Book = StringCreate("Books");
    String Dice = StringCreate("Dice");
    String Figures = StringCreate("Figures");
    String Towers = StringCreate("Towers");

    if (StringIsEqualTo(&item, &Book)) inventory_books += quantity;
    else if (StringIsEqualTo(&item, &Dice)) inventory_dice += quantity;
    else if (StringIsEqualTo(&item, &Figures)) inventory_figures += quantity;
    else if (StringIsEqualTo(&item, &Towers)) inventory_towers += quantity;

    StringDestroy(&Book);
    StringDestroy(&Dice);
    StringDestroy(&Figures);
    StringDestroy(&Towers);
    StringDestroy(&item);
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
    
    Customer *customer = NULL;
    for (int i = 0; i < num_customers; i++) {
        if (StringIsEqualTo(&(customers[i].name), &name)) {
            customer = &customers[i];
            break;
        }
    }
    
    if (!customer && num_customers < MAX_CUSTOMERS) {
        customers[num_customers].name = StringDup(&name);
        customers[num_customers].books = customers[num_customers].dice = customers[num_customers].figures = customers[num_customers].towers = 0;
        customer = &customers[num_customers++];
    }
    
    String Book = StringCreate("Books");
    String Dice = StringCreate("Dice");
    String Figures = StringCreate("Figures");
    String Towers = StringCreate("Towers");
    
    int *inventory_ptr = NULL, *customer_ptr = NULL;
    if (StringIsEqualTo(&item, &Book)) { inventory_ptr = &inventory_books; customer_ptr = &customer->books; }
    else if (StringIsEqualTo(&item, &Dice)) { inventory_ptr = &inventory_dice; customer_ptr = &customer->dice; }
    else if (StringIsEqualTo(&item, &Figures)) { inventory_ptr = &inventory_figures; customer_ptr = &customer->figures; }
    else if (StringIsEqualTo(&item, &Towers)) { inventory_ptr = &inventory_towers; customer_ptr = &customer->towers; }
    
    if (inventory_ptr && customer_ptr) {
        if (*inventory_ptr >= quantity) {
            *inventory_ptr -= quantity;
            *customer_ptr += quantity;
        } else {
            printf("Sorry "); StringPrint(&name); printf(", we only have %d ", *inventory_ptr); StringPrint(&item); printf("\n");
        }
    }
    
    StringDestroy(&Book);
    StringDestroy(&Dice);
    StringDestroy(&Figures);
    StringDestroy(&Towers);
    StringDestroy(&name);
    StringDestroy(&item);
}

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
        printf("Sorry "); StringPrint(&name); printf(", we do not have you in our database\n");
    } else {
        String Book = StringCreate("Books");
        String Dice = StringCreate("Dice");
        String Figures = StringCreate("Figures");
        String Towers = StringCreate("Towers");
        
        int *inventory_ptr = NULL, *customer_ptr = NULL;
        if (StringIsEqualTo(&item, &Book)) { inventory_ptr = &inventory_books; customer_ptr = &customer->books; }
        else if (StringIsEqualTo(&item, &Dice)) { inventory_ptr = &inventory_dice; customer_ptr = &customer->dice; }
        else if (StringIsEqualTo(&item, &Figures)) { inventory_ptr = &inventory_figures; customer_ptr = &customer->figures; }
        else if (StringIsEqualTo(&item, &Towers)) { inventory_ptr = &inventory_towers; customer_ptr = &customer->towers; }

        if (inventory_ptr && customer_ptr && *customer_ptr >= quantity) {
            *customer_ptr -= quantity;
            *inventory_ptr += quantity;
        } else {
            printf("Sorry "); StringPrint(&name); printf(", you do not have %d ", quantity); StringPrint(&item); printf("\n");
        }
        
        StringDestroy(&Book);
        StringDestroy(&Dice);
        StringDestroy(&Figures);
        StringDestroy(&Towers);
    }
    
    StringDestroy(&name);
    StringDestroy(&item);
}

void processSummarize(void) {
    printf("There are %d Books %d Dice %d Figures and %d Towers in inventory\n", inventory_books, inventory_dice, inventory_figures, inventory_towers);
    printf("we have had a total of %d different customers\n", num_customers);
}