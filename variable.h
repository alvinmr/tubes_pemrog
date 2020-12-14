#include <stdio.h>
#include "struct.h"
#include "konstanta.h"

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

Voucher voucher = {"ALAKADARNAPOCER", 0.50};

int jumlah_barang_keranjang = 0;
int total_bayar = 0;
float diskon = 0;