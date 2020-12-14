#include <stdio.h>
#include <string.h>

#define MAX 50
#define BOLD "\e[1m"
#define RED "\e[31m\e[1m"
#define GREEN "\e[32m\e[1m"
#define RESET "\e[0m"

typedef struct
{
    char nama[30];
    int harga;
    int qty;
} Keranjang;

typedef struct
{
    char nama[30];
    int harga;
    int stok;
    int jenis;
} Barang;

typedef struct
{
    char nama[30];
    char alamat[100];
    char no_hp[12];
} User;

Keranjang keranjang[MAX];

Barang barang[] = {
    {"WayluxeTshirt", 125000, 10, 1},
    {"A&D Blouse", 167000, 10, 1},
    {"Kemeja flanel", 110000, 10, 1},
    {"Tshirt putih", 57000, 10, 1},
    {"Jogger Pants", 148000, 10, 2},
    {"Bossini Pants", 389000, 10, 2},
    {"Cargo short", 125000, 10, 2},
    {"Era Haka pants", 204000, 10, 2},
    {"3 second Men", 299000, 10, 3},
    {"Eiger Dewfall", 450000, 10, 3},
    {"Boontie Pretty", 149500, 10, 3},
    {"Puma Sporty", 474000, 0, 3},
    {"Pull and Bear", 330000, 10, 4},
    {"Pancoat Sweater", 770000, 10, 4},
    {"Uniqlo Men", 189000, 10, 4},
};

User user;

int jumlah_barang_keranjang = 0;
int total_bayar = 0;

void tulisanKeranjang()
{
    puts("\t\t▒█░▄▀ ▒█▀▀▀ ▒█▀▀█ ░█▀▀█ ▒█▄░▒█ ░░░▒█ ░█▀▀█ ▒█▄░▒█ ▒█▀▀█");
    puts("\t\t▒█▀▄░ ▒█▀▀▀ ▒█▄▄▀ ▒█▄▄█ ▒█▒█▒█ ░▄░▒█ ▒█▄▄█ ▒█▒█▒█ ▒█░▄▄");
    puts("\t\t▒█░▒█ ▒█▄▄▄ ▒█░▒█ ▒█░▒█ ▒█░░▀█ ▒█▄▄█ ▒█░▒█ ▒█░░▀█ ▒█▄▄█");
}

void tulisanSelamatDatang()
{

    puts("\t\t▒█░░▒█ ▒█▀▀▀ ▒█░░░ ▒█▀▀█ ▒█▀▀▀█ ▒█▀▄▀█ ▒█▀▀▀ 　 ▀▀█▀▀ ▒█▀▀▀█ ");
    puts("\t\t▒█▒█▒█ ▒█▀▀▀ ▒█░░░ ▒█░░░ ▒█░░▒█ ▒█▒█▒█ ▒█▀▀▀ 　 ░▒█░░ ▒█░░▒█ ");
    puts("\t\t▒█▄▀▄█ ▒█▄▄▄ ▒█▄▄█ ▒█▄▄█ ▒█▄▄▄█ ▒█░░▒█ ▒█▄▄▄ 　 ░▒█░░ ▒█▄▄▄█ \n");
    puts("░█▀▀█ ▒█░░░ ░█▀▀█ ▒█░▄▀ ░█▀▀█ ▒█▀▀▄ ░█▀▀█ ▒█▀▀█ ▒█▄░▒█ ░█▀▀█ 　 ▒█▀▀▀█ ▀▀█▀▀ ▒█▀▀▀█ ▒█▀▀█ ▒█▀▀▀ ");
    puts("▒█▄▄█ ▒█░░░ ▒█▄▄█ ▒█▀▄░ ▒█▄▄█ ▒█░▒█ ▒█▄▄█ ▒█▄▄▀ ▒█▒█▒█ ▒█▄▄█ 　 ░▀▀▀▄▄ ░▒█░░ ▒█░░▒█ ▒█▄▄▀ ▒█▀▀▀ ");
    puts("▒█░▒█ ▒█▄▄█ ▒█░▒█ ▒█░▒█ ▒█░▒█ ▒█▄▄▀ ▒█░▒█ ▒█░▒█ ▒█░░▀█ ▒█░▒█ 　 ▒█▄▄▄█ ░▒█░░ ▒█▄▄▄█ ▒█░▒█ ▒█▄▄▄ \n");
}

void terimakasih()
{
    puts("\t\t\t===========================================");
    puts("\t\t\t|      Terimakasih Telah berbelanja       |");
    puts("\t\t\t|      	   Di ALAKADARNA STORE        	  |");
    puts("\t\t\t===========================================");
}

void menu()
{
    int pilih_menu;
    system("cls");
    tulisanSelamatDatang();
    printf("Halo %s! Selamat Berbelanja di ALAKADARNA STORE\n", user.nama);
    puts("Silahkan pilih menu yang telah tersedia");
    puts(BOLD "1. Belanja");
    puts("2. Keranjang");
    puts("3. Keluar" RESET);
    puts("NB : Masukkan angkanya saja");
    printf("Masukkan pilihan menu : ");
    scanf("%d", &pilih_menu);

    switch (pilih_menu)
    {
    case 1:
        system("cls");
        menuBelanja();
        break;
    case 2:
        system("cls");
        tampilKeranjang();
        break;
    case 3:

        break;
    default:
        puts(RED "Masukkan angka yang ada dalam menu saja yaa" RESET);
        break;
    }
}

void tambahKeranjang(int index)
{
    strcpy(keranjang[index].nama, barang[index].nama);
    keranjang[index].harga = barang[index].harga;
    barang[index].stok--;
    total_bayar += keranjang[index].harga;
    jumlah_barang_keranjang++;
    keranjang[index].qty++;

    system("cls");
    puts(GREEN "\t\t\t\t-------------------------");
    puts("\t\t\t\t| Berhasil ditambahkan! |");
    puts("\t\t\t\t-------------------------" RESET);
    tampilKeranjang();
}

void hapusKeranjang()
{
    int id_barang;
    printf("Masukkan ID Barang yang ingin dihapus : ");
    scanf("%d", &id_barang);
    keranjang[id_barang].qty--;
    if (keranjang[id_barang].qty >= 0)
    {
        total_bayar -= keranjang[id_barang].harga;
        jumlah_barang_keranjang--;
        barang[id_barang].stok++;
        system("cls");
        puts(GREEN "\t\t\t\t---------------------");
        puts("\t\t\t\t| Berhasil dihapus! |");
        puts("\t\t\t\t---------------------" RESET);
    }
    else
    {
        system("cls");
        puts(RED "\t\t\t---------------------------------");
        puts("\t\t\t| Barang tidak ada di keranjang |");
        puts("\t\t\t---------------------------------" GREEN);
    }
    tampilKeranjang();
}

void tampilKeranjang()
{
    int nomor = 0, i;
    tulisanKeranjang();
    puts("===================================================================================");
    puts(BOLD "No\t\tID Barang\tNama\t\tHarga\t\tQty" RESET);
    puts("===================================================================================");
    if (jumlah_barang_keranjang == 0)
    {
        puts(BOLD "\t\t\n\nWah keranjangmu masih kosong. Yuk belanja dulu\n\n" RESET);
    }
    else
    {
        for (i = 0; i < MAX; i++)
        {
            if (keranjang[i].qty > 0)
            {
                nomor++;
                printf("%d\t\t", nomor);
                printf("%d\t\t", i);
                printf("%s\t", keranjang[i].nama);
                printf("%d\t\t", keranjang[i].harga);
                printf("%d\t\n", keranjang[i].qty);
            }
        }
    }
    puts("===================================================================================");
    printf("Total : " BOLD "Rp %d" RESET " (Belum termasuk PPN 10%)\n", total_bayar);
    puts("===================================================================================");
    menuKeranjang();
}

void checkout()
{
    int pembayaran;
    float ppn = total_bayar * 0.1;
    while (pembayaran < total_bayar + ppn)
    {
        printf("Masukkan pembayaranmu senilai " BOLD "Rp %.f" RESET " (PPN 10%) : ", total_bayar + ppn);
        scanf(" %d", &pembayaran);
        puts(RED "Uangmu kurang, masukkan sesuai harga total atau lebih" RESET);
    }
    notaBelanja(pembayaran);
}

void notaBelanja(int pembayaran)
{
    int i, j;
    float ppn = total_bayar * 0.1;
    system("cls");
    puts("\t\t\t===========================================");
    puts("\t\t\t|           	ALAKADARNA STORE      	  |");
    puts("\t\t\t-------------------------------------------");
    printf("\t\t\tPelanggan : %s \n", user.nama);
    puts("\t\t\t===========================================");
    puts("\t\t\tDaftar belanja anda : ");
    for (i = 0; i < MAX; i++)
    {
        if (keranjang[i].qty > 0)
        {
            printf("\t\t\t%s", keranjang[i].nama);
            printf("\t\t%dx", keranjang[i].qty);
            printf("\t%d\n", keranjang[i].harga);
        }
    }
    printf("\t\t\t-------------------------------------------\n");
    printf("\t\t\t\tPPN	\t: Rp. %.f\n", ppn);
    printf("\t\t\t\tSub Total\t: Rp. %i\n", total_bayar);
    printf("\t\t\t\tTotal Bayar\t: Rp. %.f\n", total_bayar + ppn);
    printf("\t\t\t\tTunai       \t: Rp. %i\n", pembayaran);
    printf("\t\t\t\tKembalian\t: Rp. %.f\n", pembayaran - (total_bayar + ppn));
    terimakasih();
    // Untuk mengosongkan keranjang setelah checkout
    for (j = 0; j < MAX; j++)
    {
        keranjang[j].qty = 0;
    }
    jumlah_barang_keranjang = 0;
    total_bayar = 0;
}

void tampilBarangByJenis(int jenis)
{
    int id_barang, i;
    puts("\n\t   DAFTAR BARANG ALAKADARNA STORE");
    puts("======================================================");
    puts(BOLD "ID\tNama\t\tHarga\t\tStok" RESET);
    puts("======================================================");

    for (i = 0; i < MAX; i++)
    {
        if (barang[i].jenis == jenis)
        {
            printf("%d\t", i);
            printf("%s\t", barang[i].nama);
            printf("%d\t\t", barang[i].harga);
            printf("%d\t\n", barang[i].stok);
        }
    }
    puts("======================================================");
    printf("Masukkan ID barang yang ingin ditambahkan pada keranjang (ketik '99' untuk membatalkan pesan) : ");
    scanf("%d", &id_barang);
    if (id_barang == 99)
    {
        system("cls");
        menuBelanja();
    }
    else if (barang[id_barang].stok <= 0)
    {
        system("cls");
        puts(RED "\t------------------------------------------------------------------------");
        puts("\t| Pakaian yang kamu masukkan tidak ada / habis nih, pilih yang lain ya |");
        puts("\t------------------------------------------------------------------------" RESET);
        menuBelanja();
    }
    else
    {
        tambahKeranjang(id_barang);
    }
}

void menuBelanja()
{
    int menu_belanja;
    puts("Silahkan dipilih list kategori yang telah tersedia ");
    puts(BOLD "1. Baju");
    puts("2. Celana");
    puts("3. Jaket");
    puts("4. Sweater");
    puts("5. Menu Utama" RESET);
    printf("Masukkan pilihanmu : ");
    scanf("%d", &menu_belanja);
    if (menu_belanja <= 4)
    {
        tampilBarangByJenis(menu_belanja);
    }
    else if (menu_belanja == 5)
    {
        menu();
    }
    else
    {
        puts(RED "Masukkan sesuai nomor yang ada yaa" RESET);
    }
}

void menuKeranjang()
{
    int menu_keranjang;
    puts("Silahkan pilih menu yang telah tersedia");
    puts("Pilih Lanjutan ? ");
    puts(BOLD "1. Tambah Item");
    puts("2. Hapus Item");
    puts("3. Checkout");
    puts("4. Menu Utama" RESET);
    printf("Masukkan pilihanmu : ");
    scanf("%d", &menu_keranjang);

    switch (menu_keranjang)
    {
    case 1:
        system("cls");
        menuBelanja();
        break;
    case 2:
        hapusKeranjang();
        break;
    case 3:
        if (total_bayar <= 0)
        {
            puts(BOLD "Keranjangmu masih kosong, apa yang mau dicheckout ?");
            puts("Yuk belanja dulu" RESET);
        }
        else
        {
            checkout();
        }
        break;
    case 4:
        menu();
        break;
    default:
        puts(RED "Masukkan nomor yang ada di menu saja yaa" RESET);
        break;
    }
}

int main()
{
    char jawaban = 'y';
    system("cls");
    printf("Masukkan Namamu : ");
    scanf("%[^\n]s", user.nama);
    printf("Alamatmu dimana ? : ");
    scanf("%[^\n]s", user.alamat);

    while (jawaban == 'y' || jawaban == 'Y')
    {
        menu();
        printf("ingin " BOLD "keluar(q)" RESET " atau " BOLD "kembali ke menu utama(y) " RESET " ? : ");
        scanf(" %c", &jawaban);
    }
    terimakasih();
    return 0;
}
