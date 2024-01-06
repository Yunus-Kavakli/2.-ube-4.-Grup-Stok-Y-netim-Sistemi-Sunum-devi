#ifndef STOK
#define STOK
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define STOK_limiti 100
struct bilgiler {
    int seri_no;
    char adi [15];
    int adedi;
    int sira_no[STOK_limiti];
}stoklar[STOK_limiti];
void stok_sil(struct bilgiler stoklar[STOK_limiti], int *urun_sirasi);
void urun_guncelle(struct bilgiler stoklar[STOK_limiti]);
void stok_goruntule(struct bilgiler stoklar[STOK_limiti], int urun_sirasi);
void dosyaya_kaydet(struct bilgiler stoklar[STOK_limiti],int urun_sirasi);
void dosyadan_stokal(struct bilgiler stoklar[STOK_limiti],int *urun_sirasi);
void urun_ekle(struct bilgiler stoklar[STOK_limiti],int *urun_sirasi);
#endif

