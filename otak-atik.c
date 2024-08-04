#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk menyimpan informasi produk
struct Product {
    int id;
    char name[50];
    int stock;
    float price;
};

// Fungsi untuk menambahkan produk baru
void addProduct(struct Product *products, int *productCount) {
    do {
        printf("Masukkan nama produk: ");
        scanf("%s", products[*productCount].name);

        printf("Masukkan stok produk: ");
        scanf("%d", &products[*productCount].stock);

        printf("Masukkan harga produk: ");
        scanf("%f", &products[*productCount].price);

        products[*productCount].id = *productCount + 1; // ID dihasilkan secara otomatis
        (*productCount)++;

        printf("Produk berhasil ditambahkan!\n");
        printf("apakah ingin menambahkan lagi? (y/n): ");
        char ulang;
        scanf(" %c", &ulang);

        if(ulang != 'Y' && ulang != 'y') {
            break;
        }
    } while (1);

    
}

// Fungsi untuk melakukan penjualan
void sellProduct(struct Product *products, int productCount) {
    do { 
        int productId, quantity;
        printf("Masukkan ID produk yang akan dijual: ");
        scanf("%d", &productId);

        if (productId < 1 || productId > productCount) {
            printf("ID produk tidak valid!\n");
            return;
        }

        printf("Masukkan jumlah yang akan dijual: ");
        scanf("%d", &quantity);

        if (quantity > products[productId - 1].stock) {
            printf("Stok tidak mencukupi!\n");
            return;
        }

        products[productId - 1].stock -= quantity;
        printf("Penjualan berhasil! Total harga: %.3f\n", products[productId - 1].price * quantity);

        printf("Apakah ingin menjual lagi? (y/n): ");
        char ulang;
        scanf(" %c", &ulang);
        if(ulang != 'y' && ulang != 'Y') {
            break;
        }
    } while(1);
}


// Fungsi untuk menampilkan semua produk
void displayProducts(struct Product *products, int productCount) {
    printf("Daftar Produk:\n");
    printf("----------------------------------------------------------\n");
    printf("%-5s %-20s %-10s %-10s\n", "ID", "Nama", "Stok", "Harga");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < productCount; i++) {
        printf("%-5d %-20s %-10d %-10.2f\n", products[i].id, products[i].name, products[i].stock, products[i].price);
    }
    printf("----------------------------------------------------------\n");
}

int main() {
    struct Product products[100]; // Batasi jumlah produk maksimal
    int productCount = 0;
    int choice;
    //int i;

    do {
        printf("PROGRAM MANAJEMEN TOKO\n");
     
        printf("----------------------------------------------------------\n");
        printf("| %-2s | %-20s | %-26s |\n", "No", "Menu", "Deskripsi");
        printf("----------------------------------------------------------\n");
        printf("| %-2d | %-20s | %-26s |\n", 1, "Tambah Produk", "Tambahkan produk baru");
        printf("| %-2d | %-20s | %-26s |\n", 2, "Jual Produk", "Lakukan penjualan produk");
        printf("| %-2d | %-20s | %-26s |\n", 3, "Lihat Produk", "Lihat daftar semua produk");
        printf("| %-2d | %-20s | %-26s |\n", 4, "Keluar", "Keluar dari program");
        printf("----------------------------------------------------------\n");
        printf("Pilih menu: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(products, &productCount);
                break;
            case 2:
                sellProduct(products, productCount);
                break;
            case 3:
                displayProducts(products, productCount);
                break;
            case 4:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba kembali..\n");
                break;
        }
    } while (choice != 4);

    return 0;
}


 