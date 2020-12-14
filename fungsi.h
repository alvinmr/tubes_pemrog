#include <string.h>
#include "variable.h"

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
    system("clear");
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
        system("clear");
        menuBelanja();
        break;
    case 2:
        system("clear");
        tampilKeranjang();
        break;
    case 3:

        break;
    default:
        puts(RED "Masukkan angka yang ada dalam menu saja yaa" RESET);
        menu();
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

    system("clear");
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
        system("clear");
        puts(GREEN "\t\t\t\t---------------------");
        puts("\t\t\t\t| Berhasil dihapus! |");
        puts("\t\t\t\t---------------------" RESET);
    }
    else
    {
        system("clear");
        puts(RED "\t\t\t---------------------------------");
        puts("\t\t\t| Barang tidak ada di keranjang |");
        puts("\t\t\t---------------------------------" RESET);
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
    char jawaban_promo;
    char kode_pocer[30];
    float ppn = (total_bayar - diskon) * 0.1;
    while (pembayaran < total_bayar + ppn - diskon)
    {
        printf("Apakah kamu punya voucher promo kami ? [y/n] ");
        scanf(" %c", &jawaban_promo);
        while (strcmp(kode_pocer, voucher.kode) != 0)
        {
            printf("Masukkan kode pocer : ");
            scanf(" %s", &kode_pocer);
            if (strcmp(kode_pocer, voucher.kode) != 0)
            {
                puts(RED "Kode voucher salah! Masukkan ulang kode vouchernya!" RESET);
            }
            else
            {
                puts("Voucher berhasil dipakai, lanjut bayar!");
                diskon = total_bayar * voucher.nominal;
            }
        }

        printf("Selamat anda mendapatkan diskon sebesar " BOLD "Rp %.f" RESET "\n", diskon);
        printf("Masukkan pembayaranmu senilai " BOLD "Rp %.f" RESET " (Sudah termasuk PPN 10%) : ", total_bayar + ppn - diskon);
        scanf(" %d", &pembayaran);
        puts(RED "Uangmu kurang, masukkan sesuai harga total atau lebih" RESET);
    }
    notaBelanja(pembayaran);
}

void notaBelanja(int pembayaran)
{
    int i, j;
    float ppn = (total_bayar - diskon) * 0.1;
    system("clear");
    puts("\t\t\t===========================================");
    puts("\t\t\t|           	ALAKADARNA STORE      	  |");
    puts("\t\t\t-------------------------------------------");
    puts("\t\t\tPelanggan : ");
    printf("\t\t\tNama    : %s \n", user.nama);
    printf("\t\t\tEmail 	  : %s \n", user.email);
    printf("\t\t\tAlamat 	  : %s \n", user.alamat);
    printf("\t\t\tNo.Hp 	  : %s \n", user.no_hp);
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
    printf("\t\t\t\tSub Total\t: Rp. %i\n", total_bayar);
    printf("\t\t\t\tDiskon  \t: Rp. %.f\n", diskon);
    printf("\t\t\t\tPPN(10%)\t: Rp. %.f\n", ppn);
    printf("\t\t\t\tTotal Bayar\t: Rp. %.f\n", total_bayar + ppn - diskon);
    printf("\t\t\t\tTunai       \t: Rp. %i\n", pembayaran);
    printf("\t\t\t\tKembalian\t: Rp. %.f\n", pembayaran - (total_bayar + ppn - diskon));
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
        system("clear");
        menuBelanja();
    }
    else if (barang[id_barang].stok <= 0)
    {
        system("clear");
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
        system("clear");
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
        menuKeranjang();
        break;
    }
}