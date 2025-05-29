#include "kartlar.h"
#include "kartIslemleri.h"
#include "oyunaBasla.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

// oyun menusu
void oyunMenu(std::string oyuncuAdi, std::vector<canavarKart> &elMons,
               std::vector<sihirKart> &elSihir, std::vector<tuzakKart> &elTuzak,
               std::vector<canavarKart> &monsAlan, std::vector<sihirKart> &sihirAlan,
               std::vector<tuzakKart> &tuzakAlan,std::vector<canavarKart> &rakipMons,
               int &LP, int &rakipLP,int &canavarSecim)     
               {

    int secim;
    bool canavarOynandi = false;
    while (true)
    {
        std::cout << "Kart yerlestirme asamasi\n ";
        std::cout << "Yerlestirmek istediginiz karti secin:" << oyuncuAdi << "\n";
        std::cout << "1. Canavar karti" << (canavarOynandi ? "(Zaten Oynandi)" : "") << std::endl;
        std::cout << "2. Sihir karti\n";
        std::cout << "3. Tuzak karti\n";
        std::cout << "4. Savas asamasına gec\n";
        std::cout << "5. Kart oynamayi bitir\n";
        std::cout << "Seciminiz: ";
        std::cin >> secim;
        // Kart seçimi sonrası cin.clear() + cin.ignore() eklemen iyi olur:
        std::cin.clear();             // Hatalı giriş varsa temizle
        std::cin.ignore(10000, '\n'); // Satırın geri kalanını temizle
        while ((secim < 1 || secim > 5))
        {
            std::cout << "Gecersiz secim. Lutfen 1, 2, 3 4 veya 5 girin: ";
            std::cin >> secim;
        }
        if (secim == 5)
        {
            std::cout << "Kart oynamayi bitirdiniz. Sira rakipte." << std::endl;
            break;
        }
    
    switch (secim)
    {
    case 1:
        if (canavarOynandi)
        {
            std::cout << "Zaten canavar kartı oynandı. Lütfen başka bir kart seçin." << std::endl;
            continue; // Canavar kartı zaten oynandıysa devam et
        }
        canavarYerles(elMons,rakipMons,canavarSecim,
                      monsAlan, LP);
        canavarOynandi = true; // Canavar kartı oynandı
        break;
    case 2:
        sihirYerles(elSihir, sihirAlan, LP);
        break;
    case 3:
        tuzakYerles(elTuzak, tuzakAlan, LP);
        break;
    case 4: 
        if (canavarOynandi)
        {
            std::cout << "Savas asamasina geciliyor..." << std::endl;
            savas(monsAlan, rakipMons, elMons, sihirAlan, tuzakAlan,
                  canavarSecim, LP, rakipLP);
            break; // Savaş aşamasına geçildiğinde döngüden çık
        }
        else
        {
            std::cout << "Önce bir canavar kartı oynamalısınız." << std::endl;
        }
        break;
    }
}
}
// ayni desteyi secmesini engellemek icin ne yapmaliyim
// Çözüm: Seçilen desteleri takip eden bir değişken kullanın ve
// ikinci seçimde aynı deste seçimini engelleyin.

void desteSec(std::vector<canavarKart> &canavarlar, std::vector<sihirKart> &sihirler,
     std::vector<tuzakKart> &tuzaklar, int &secilenDeste, int digerSecilenDeste )
{
    std::cout << "1.Deste:yamiDeste\n"
         << "2.Deste:kaibaDeste\n"
         << "3.Deste:joeyDeste\n";
    int secim;
    while (true)
    {
        std::cout << "Lütfen deste seçiniz (1-3): ";
        std::cin >> secim;
        if (secim < 1 || secim > 3)
        {
            std::cout << "Geçersiz seçim. Lütfen 1-3 arasında bir sayı girin." << std::endl;
            continue;
        }
        if (secim == digerSecilenDeste)
        {
            std::cout << "Bu deste zaten seçildi, lütfen farklı bir deste seçin." << std::endl;
            continue;
        }
        break;
    }
    secilenDeste = secim;
    switch (secim)
    {
    case 1:
        kartlariOku("yamiDeste.csv", canavarlar, sihirler, tuzaklar);
        std::cout << "Yami deste seçildi." << std::endl;
        break;
    case 2:
        kartlariOku("kaibaDeste.csv", canavarlar, sihirler, tuzaklar);
        std::cout << "Kaiba deste seçildi." << std::endl;
        break;
    case 3:
        kartlariOku("joeyDeste.csv", canavarlar, sihirler, tuzaklar);
        std::cout << "Joey deste seçildi." << std::endl;
        break;
    }
    std::cout << "Deste başarıyla yüklendi." << std::endl;
}



