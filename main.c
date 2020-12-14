#include <stdio.h>
#include <string.h>
#include "fungsi.h"

int main()
{
    char jawaban = 'y';
    system("clear");
    printf("Masukkan Namamu   : ");
    gets(user.nama);
    printf("Masukkan Alamatmu : ");
    gets(user.alamat);
    printf("Masukkan Email    : ");
    gets(user.email);
    printf("Masukkan No.Hp    : ");
    gets(user.no_hp);

    while (jawaban == 'y' || jawaban == 'Y')
    {
        menu();
        printf("ingin " BOLD "keluar(q)" RESET " atau " BOLD "kembali ke menu utama(y) " RESET " ? : ");
        scanf(" %c", &jawaban);
    }
    terimakasih();
    return 0;
}