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
    char email[25];
} User;

typedef struct
{
    char kode[30];
    float nominal;
} Voucher;