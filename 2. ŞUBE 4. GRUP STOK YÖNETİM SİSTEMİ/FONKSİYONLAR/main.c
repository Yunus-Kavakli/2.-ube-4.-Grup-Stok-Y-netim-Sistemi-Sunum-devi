#include "C:\Users\KAVAKLI\Desktop\2. ŞUBE 4. GRUP STOK YÖNETİM SİSTEMİ\HEADER\main.h"
// Yunus Kavaklı
void urun_ekle(struct bilgiler stoklar[STOK_limiti], int *urun_sirasi)
{
    printf("%d. ürün ekleniyor...\n", *urun_sirasi + 1); // stoktaki ürünlere ürün ekleyeceğimiz için 1 ekleyerek eklenecek ürün sırasını yazıyoruz
    printf("Ürün seri numarasını giriniz: ");
    scanf("%d", &stoklar[*urun_sirasi].seri_no);
    printf("Ürün adını giriniz: ");
    scanf("%s", stoklar[*urun_sirasi].adi); // metin ataması olduğu için scanf içine & kullanmamıza gerek yok.
    printf("Ürünün stok miktarını giriniz: ");
    scanf("%d", &stoklar[*urun_sirasi].adedi);
    printf("Ürün başarıyla eklendi\n");
    stoklar->sira_no[*urun_sirasi] = *urun_sirasi;
    (*urun_sirasi)++;
}
// Cem Civelek
void urun_guncelle(struct bilgiler stoklar[STOK_limiti])
{
    int silinecek_urun_no;
    printf("Bilgilerini güncellemek istediğiniz ürünün sıra numarasını giriniz: ");
    scanf("%d", &silinecek_urun_no);
    silinecek_urun_no = silinecek_urun_no - 1; // ekranda 1. olarak görünen ürün aslında 0. ürün olarak kaydedildiği için -1 yapıyoruz.
    if (silinecek_urun_no == stoklar->sira_no[silinecek_urun_no])
    {
        printf("Ürün bulundu\n");
        printf("Yeni ürün seri numarasını giriniz: ");
        scanf("%d", &stoklar[silinecek_urun_no].seri_no);
        printf("Yeni ürün adını giriniz: ");
        scanf("%s", stoklar[silinecek_urun_no].adi);
        printf("Yeni ürünün stok miktarını giriniz: ");
        scanf("%d", &stoklar[silinecek_urun_no].adedi);
        printf("Ürün başarıyla güncellendi.\n");
    }
    else
        printf("Ürün bulunamadı");

}
// Cem civelek
void stok_goruntule(struct bilgiler stoklar[STOK_limiti], int urun_sirasi)
{
    printf("Stok görüntüleniyor...\n");
    printf("Sıra no\t\tSeri no\t\tAdı\t\tAdedi\n");
    for (int i = 0; i < urun_sirasi; ++i)
    {
        printf("%d\t\t%d\t\t%s\t\t%d\n", stoklar->sira_no[i] + 1, stoklar[i].seri_no, stoklar[i].adi, stoklar[i].adedi);
    }
    printf("Stok başarıyla görüntülendi.\n");
}
// Abdulgaffar Gülice
void stok_sil(struct bilgiler stoklar[STOK_limiti], int *urun_sirasi){
    int silinecek_urun;
    printf("silinecek ürün sirasini girin");
    scanf("%d",&silinecek_urun);
    for (int i = 0; i < *urun_sirasi; ++i) {
        if(silinecek_urun -1 == stoklar->sira_no[i]){
            for (int j = i; j < *urun_sirasi; ++j) {
                stoklar[j].seri_no = stoklar[j+1].seri_no;
                strcpy(stoklar[j].adi,stoklar[j+1].adi);
                stoklar[j].adedi = stoklar[j+1].adedi;
                strcpy(stoklar[j].sira_no,stoklar[j+1].sira_no);
                *urun_sirasi= *urun_sirasi-1;
            }
        }
    }
};

void dosyaya_kaydet(struct bilgiler stoklar[STOK_limiti], int urun_sirasi)
{
    FILE *dosya = fopen("C:\\Users\\KAVAKLI\\Desktop\\stoklar.txt", "w");
    if (dosya == NULL)
    {
        printf("Dosya oluşturulamadı");
        EXIT_FAILURE;
    }
    for (int i = 0; i < urun_sirasi; ++i)
    {
        fprintf(dosya, "%d\t%s\t%d\n", stoklar[i].seri_no, stoklar[i].adi, stoklar[i].adedi);
    }
    fclose(dosya);
    printf("Dosyaya başarılı bir şekilde kaydedildi\n");
    printf("Programdan çıkılıyor...");
}

void dosyadan_stokal(struct bilgiler stoklar[STOK_limiti], int *urun_sirasi)
{
    FILE *dosya = fopen("C:\\Users\\KAVAKLI\\Desktop\\stoklar.txt", "r");
    if (dosya == NULL)
    {
        printf("Dosya okuma işlemi başarısız oldu\n");
        EXIT_FAILURE;
    }
    while (fscanf(dosya, "%d%s%d", &stoklar[*urun_sirasi].seri_no, stoklar[*urun_sirasi].adi, &stoklar[*urun_sirasi].adedi) != EOF)
    {
        stoklar->sira_no[*urun_sirasi] = *urun_sirasi;
        (*urun_sirasi)++;
    }
    fclose(dosya);
    printf("Dosyadan stoklar alındı\n");
}
