#include <stdio.h>
#include <string.h>

#define MAX_INVENTORY 50
#define MAX_LEN 10

// Structure
struct Products {
    char name[MAX_LEN];
    int productID;
    float price;
    int quantity;
};

// Functions
void addProduct(struct Products inventory[], int *numProducts, char name[MAX_LEN], int productID, float price, int quantity) {
    if (*numProducts >= MAX_INVENTORY) {//if max inventory has been reached.
        printf("Error: Max Inventory\n");
        return;
    }

    strcpy(inventory[*numProducts].name, name); //assign info
    inventory[*numProducts].productID = productID;
    inventory[*numProducts].price = price;
    inventory[*numProducts].quantity = quantity;

    (*numProducts)++; // increment num of products in the system.
    printf("Product added!\n");
}

void displayProducts(struct Products inventory[], int numProducts) {
    printf("Inventory:\n");
    printf("%-20s %-10s %-10s %-10s\n", "Name", "ProductID", "Price", "Quantity");
    for (int i = 0; i < numProducts; i++) {//print all info to most recent created product.
        printf("%-20s %-10d %-10.2f %-10d\n", inventory[i].name, inventory[i].productID, inventory[i].price, inventory[i].quantity);
    }
}

void searchByProductID(struct Products inventory[], int numProducts, int productID) {
    for (int i = 0; i < numProducts; i++) {//grab all created inventory index's
        if (inventory[i].productID == productID) {
            printf("Product found:\n");
            printf("%-20s %-10s %-10s %-10s\n", "Name", "ProductID", "Price", "Quantity");
            printf("%-20s %-10d %-10.2f %-10d\n", inventory[i].name, inventory[i].productID, inventory[i].price, inventory[i].quantity);
            return;
        }
    }
    printf("Product ID: [%d] Not found!\n", productID);
}

//main
int main() {
    char choice;
    float pPrice;
    int numProducts = 0, pAmount, pID;
    char pName[MAX_LEN];

    struct Products inventory[MAX_INVENTORY];

    printf("[A] = Add Products\n");
    printf("[D] = Display Inventory\n");
    printf("[S] = Search by Product ID\n");

while(1){ //loop to enter options
    printf("Enter Option: ");
    scanf(" %c", &choice);

    switch (choice) {
    case 'A':
    case 'a':
        printf("Enter Product Name: ");
        scanf(" %s", pName);
        printf("Enter Product ID: ");
        scanf(" %d", &pID);
        printf("Enter Product Price: $");
        scanf(" %f", &pPrice);
        printf("Enter Product Amount: ");
        scanf(" %d", &pAmount);
        addProduct(inventory, &numProducts, pName, pID, pPrice, pAmount);
        break;
    case 'D':
    case 'd':
        displayProducts(inventory, numProducts);
        break;
    case 'S':
    case 's':
        printf("Enter Product ID: ");
        scanf(" %d", &pID);
        searchByProductID(inventory, numProducts, pID);
        break;
    default:
        printf("Error: Invalid Input!\n");
    }//switch
    }//while

    return 0;
}//main
