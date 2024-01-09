#include "C:\Users\KAVAKLI\Desktop\2. ŞUBE 4. GRUP STOK YÖNETİM SİSTEMİ\HEADER\main.h"
#include "C:\Users\KAVAKLI\Desktop\2. ŞUBE 4. GRUP STOK YÖNETİM SİSTEMİ\FONKSİYONLAR\main.c"
int main() {
    system("chcp 65001>nul");
    printf("------------------------------------STOK YÖNETİM SİSTEMİNE HOŞGELDİNİZ-----------------------------------\n");
    int kayitli_urun_sayisi = 0;
    dosyadan_stokal(stoklar, &kayitli_urun_sayisi);
    int seçim;
    do { // while içine yazdığımız koşulu sağladığı sürece kod çalışır. sağlamazsa döngü kırılır.
        printf("1-) Ürün bilgi ekle\n");
        printf("2-) Ürün bilgi güncelle\n");
        printf("3-) Stok görüntüle\n");
        printf("4-) Stok sil\n");
        printf("5-) Ürün bilgilerini kaydet ve çıkış yap\n");
        printf("Lütfen seçim yapınız:");
        scanf("%d", &seçim);

        switch (seçim) {
            case 1:
                urun_ekle(stoklar, &kayitli_urun_sayisi);
                break;
            case 2:
                stok_goruntule(stoklar, kayitli_urun_sayisi);
                urun_guncelle(stoklar);
                break;
            case 3:
                stok_goruntule(stoklar, kayitli_urun_sayisi);
                break;
            case 4:
                stok_goruntule(stoklar, kayitli_urun_sayisi);
                stok_sil(stoklar,&kayitli_urun_sayisi); 
                break;
            case 5:
                dosyaya_kaydet(stoklar, kayitli_urun_sayisi);
                break;

            default:
                printf("Yanlış seçim, tekrar deneyin.\n");
        }
    } while (seçim != 5);

    return 0;
}
