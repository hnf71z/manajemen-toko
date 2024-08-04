#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Membuat data produk (struct)
struct data_produk {
    int id;
    char nama[50];
    int stok;
    float harga;
};

// Fungsi untuk menambahkan produk
void produk_baru(struct data_produk *produk, int *hitung_produk) {
    do {
        printf("Masukkan nama produk: ");
        scanf("%s", produk[*hitung_produk].nama);

        printf("Masukkan stok produk: ");
        scanf("%d", &produk[*hitung_produk].stok);

        printf("Masukkan harga produk: ");
        scanf("%f", &produk[*hitung_produk].harga);

        produk[*hitung_produk].id = *hitung_produk + 1; //ID dihasilkan secara otomatis
        (*hitung_produk)++;

        printf("Produk berhasil ditambahkan!\n");
        printf("Apakah ingin menambahkan kembali? (y/n): ");
        char pilihan;
        scanf(" %c", &pilihan);

        if(pilihan != 'y' && pilihan != 'Y') {
            break;
        }
    } while(1);
}

void jual_produk(struct data_produk *produk, int hitung_produk) {
    do{
        int id_produk, jumlah;
        printf("Masukkan ID produk yang akan dijual: ");
        scanf("%d", &id_produk);

        if(id_produk < 1 || id_produk > hitung_produk) {
            printf("ID produk tidak valid!\n");
            return;
        }

        printf("Masukkan jumlah yang akan dijual: ");
        scanf("%d", &jumlah);

        if(jumlah > produk[id_produk - 1].stok) {
            printf("Stok tidak mencukupi!\n");
            return;
        }

        produk[id_produk - 1].stok -= jumlah;
        printf("Penjualan berhasil! Total harga: %.3f\n", produk[id_produk - 1].harga * jumlah);

        printf("Apakah ingin menjual lagi? (y/n): ");
        char pilihan;
        scanf(" %c", &pilihan);
        if(pilihan != 'y' && pilihan != 'Y') {
            break;
        }
    } while(1);
}

void daftar_produk(struct data_produk *produk, int hitung_produk) {
    printf("Daftar Produk:\n");
    printf("----------------------------------------------------------\n");
    printf("%-5s %-20s %-10s %-10s\n", "ID", "Nama", "Stok", "Harga");
    printf("----------------------------------------------------------\n");
    for(int i = 0; i < hitung_produk; i++) {
        printf("%-5d %-20s %-10d %-10.3f\n", produk[i].id, produk[i].nama, produk[i].stok, produk[i].harga);
    }
    printf("----------------------------------------------------------\n");
}

// Fungsi main atau blok main
int main() {
    struct data_produk produk[100]; // Batas jumlah produk maksimal
    int hitung_produk = 0;
    int menu;

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
        scanf("%d", &menu);

        switch(menu) {
            case 1:
                produk_baru(produk, &hitung_produk);
                break;
            case 2:
                jual_produk(produk, hitung_produk);
                break;
            case 3:
                daftar_produk(produk, hitung_produk);
                break;
            case 4:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi..\n");
                break;
        }
    } while(menu != 4);

    return 0;
}