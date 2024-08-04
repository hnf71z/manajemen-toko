#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    int id;
    char name[50];
    int stock;
    float price;
};

// ... (other function declarations)

// Function to load products from a file, creating the file if it doesn't exist
int loadProductsFromFile(struct Product *products, int *productCount, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found. Creating a new file.\n");

        // Create a new file for writing
        file = fopen(filename, "w");
        if (file == NULL) {
            printf("Error creating file.\n");
            return 0;
        }

        fclose(file);
        return 1;  // Return 1 to indicate that a new file has been created
    }

    // File exists, proceed with reading data
    *productCount = 0;

    while (fscanf(file, "%d %s %d %f", &products[*productCount].id, products[*productCount].name,
                  &products[*productCount].stock, &products[*productCount].price) == 4) {
        (*productCount)++;
        if (*productCount >= 100) {
            printf("Maximum product limit reached. Some products may not be loaded.\n");
            break;
        }
    }

    fclose(file);
    return 1;
}

// ... (other functions remain the same)

int main() {
    struct Product products[100];
    int productCount = 0;
    int choice;

    // Load existing product data from a file or create a new file
    if (!loadProductsFromFile(products, &productCount, "products.txt")) {
        printf("Error loading or creating the product file.\n");
        return 1;  // Exit with an error code
    }

    do {
        // ... (no changes in this part)

        switch (choice) {
            case 1:
                addProduct(products, &productCount, NULL);
                break;
            case 2:
                sellProduct(products, productCount, NULL);
                break;
            case 3:
                displayProducts(products, productCount);
                break;
            case 4:
                saveProductsToFile(products, productCount, "products.txt");
                printf("Terima kasih!\n");
                break;
            default:
 
