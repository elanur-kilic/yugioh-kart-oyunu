#include <iostream>
#include <windows.h>
#include "kartlar.h"
#include "kartIslemleri.h"
#include "oyunaBasla.h"
#include "mezar.h"
#include "savas.h"

int main()
{
    SetConsoleOutputCP(65001); // Windows için UTF-8 konsol

    srand(time(0));        // Rastgeleliği başlat (her çalıştırmada farklı sonuçlar)
    int secilenDeste1 = 0; // main fonksiyonunda global veya static olarak tanımlayın
    std::string name1 = "yami", name2 = "kaiba", dosyaAdi1, dosyaAdi2;
    int canavarAd1, canavarAd2, atk1, atk2, def1, def2, LP1 = 4000, LP2 = 4000;

    // Oyuncu isimlerini al
    /*
       std::cout << "1. Oyuncu ismini girin: ";
       std::getline(std::cin, name1);
       std::cout << "2. Oyuncu ismini girin: ";
       std::getline(std::cin, name2);
   */

    // Deste vektörlerini oku
    std::vector<canavarKart> canavarlar1, canavarlar2;
    std::vector<sihirKart> sihirler1, sihirler2;
    std::vector<tuzakKart> tuzaklar1, tuzaklar2;

    // Oyuncu deste seçim ekranı
    std::cout << name1 << " Deste Seçimi:\n";
    desteSec(canavarlar1, sihirler1, tuzaklar1, secilenDeste1);
    std::cout << name2 << " Deste Seçimi:\n";
    int secilenDeste2 = 0;
    desteSec(canavarlar2, sihirler2, tuzaklar2, secilenDeste2, secilenDeste1);

    // Oyuncu isimlerini yazdır
    std::cout << "1. Oyuncu: " << name1 << " LP:" << LP1 << std::endl;
    std::cout << "2. Oyuncu: " << name2 << " LP:" << LP2 << std::endl;

    // Kart destelerini karıştır
    std::vector<canavarKart> monsDestesi1 = canavarlar1;
    std::vector<sihirKart> sihirDestesi1 = sihirler1;
    std::vector<tuzakKart> tuzakDestesi1 = tuzaklar1;
    std::vector<canavarKart> monsDestesi2 = canavarlar2;
    std::vector<sihirKart> sihirDestesi2 = sihirler2;
    std::vector<tuzakKart> tuzakDestesi2 = tuzaklar2;
    std::vector<canavarKart> elMons1, elMons2;
    std::vector<sihirKart> elSihir1, elSihir2;
    std::vector<tuzakKart> elTuzak1, elTuzak2;
    std::vector<kart> yokEdilenKartlar1, yokEdilenKartlar2;
    std::vector<canavarKart> monsAlan1, monsAlan2;
    std::vector<sihirKart> sihirAlan1, sihirAlan2;
    std::vector<tuzakKart> tuzakAlan1, tuzakAlan2;

    // Oyuncuların kart çekme işlemi
    for (int i = 0; i < 5; ++i)
    {
        kartCek(monsDestesi1, sihirDestesi1, tuzakDestesi1, elMons1, elSihir1, elTuzak1);
        kartCek(monsDestesi2, sihirDestesi2, tuzakDestesi2, elMons2, elSihir2, elTuzak2);
    }
    // 1. Oyuncu icin +1 kart
    kartCek(monsDestesi1, sihirDestesi1, tuzakDestesi1, elMons1, elSihir1, elTuzak1);
    elGoster(elMons1, elSihir1, elTuzak1);
    int secim;
    bool canavarOynandi = false;
    while (true)
    {
        std::cout << "Kart yerlestirme asamasi\n ";
        std::cout << "Yerlestirmek istediginiz karti secin:" << name1 << "\n";
        std::cout << "1. Canavar karti" << (canavarOynandi ? "(Zaten Oynandi)" : "") << std::endl;
        std::cout << "2. Sihir karti\n";
        std::cout << "3. Tuzak karti\n";
        std::cout << "4. Kart oynamayi bitir\n";
        std::cout << "Seciminiz: ";
        std::cin >> secim;
        // Kart seçimi sonrası cin.clear() + cin.ignore() eklemen iyi olur:
        std::cin.clear();             // Hatalı giriş varsa temizle
        std::cin.ignore(10000, '\n'); // Satırın geri kalanını temizle
        while ((secim < 1 || secim > 4))
        {
            std::cout << "Gecersiz secim. Lutfen 1, 2, 3 veya 4 girin: ";
            std::cin >> secim;
            std::cin.clear();             // Hatalı giriş varsa temizle
            std::cin.ignore(10000, '\n'); // Satırın geri kalanını temizle
        }
        if (secim == 4)
        {
            std::cout << "Kart oynamayi bitirdiniz. Sira rakipte." << std::endl;
            break; // Kart oynamayi bitir
        }

        switch (secim)
        {
        case 1:

            if (canavarOynandi)
            {
                std::cout << "Zaten bir canavar karti oynadiniz. Lütfen sihir veya tuzak karti oynayin." << std::endl;
                continue; // Canavar kartı zaten oynandıysa devam et
            }

            canavarYerles(elMons1, monsAlan1, canavarAd1, monsDestesi1, LP1);
            canavarOynandi = true; // Canavar kartı oynandı
            break;
        case 2:
            sihirYerles(elSihir1, sihirAlan1, LP1);
            break;
        case 3:
            tuzakYerles(elTuzak1, tuzakAlan1, LP1);
            break;
        }
    }

    // oyun dongusu
    while (LP1 > 0 && LP2 > 0)
    {

        // 2. Oyuncu turu
        kartCek(monsDestesi2, sihirDestesi2, tuzakDestesi2, elMons2, elSihir2, elTuzak2);
        elGoster(elMons2, elSihir2, elTuzak2);
        oyunMenu(name2, elMons2, elSihir2, elTuzak2, monsAlan2, sihirAlan2, tuzakAlan2, elMons1, LP2, LP1, canavarAd2);
        // 1. Oyuncu turu
        kartCek(monsDestesi1, sihirDestesi1, tuzakDestesi1, elMons1, elSihir1, elTuzak1);
        elGoster(elMons1, elSihir1, elTuzak1);
        oyunMenu(name1, elMons1, elSihir1, elTuzak1, monsAlan1, sihirAlan1, tuzakAlan1, elMons2, LP1, LP2, canavarAd1);

        if (LP2 <= 0)
            break; // Rakip LP sıfırlandıysa döngüden çık
    }

    std::cout << "Oyun bitti!" << std::endl;
    std::cout << name1 << " LP: " << LP1 << ", " << name2 << " LP: " << LP2 << std::endl;

    return 0;
}
