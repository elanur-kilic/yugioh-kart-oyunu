#include "kartlar.h"
#include "kartIslemleri.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

void kartEkle(const std::string dosyaAdi, std::vector<canavarKart> &canavarlar,
              std::vector<sihirKart> &sihirler,
              std::vector<tuzakKart> &tuzaklar)
{
    int ID, atk, def, atkEtki, defEtki, lpEtki, secim;
    std::string ad, cesit, tip, ozellik, hedefMons;
    std::cout << "Kart ekleme ekranina hosgeldiniz!" << std::endl;
    std::cout << "Lutfen kart bilgilerini giriniz:" << std::endl;

    std::cout << "Kart ID:";
    std::cin >> ID;
    std::cin.ignore(); // Temizle cin buffer
    std::cout << "Kart adini giriniz: ";
    std::getline(std::cin, ad);

    std::cout << "\n"
         << "Hangi karti eklemek istersiniz?\n"
         << "1.Canavar Karti\n"
         << "2.Sihir Karti\n"
         << "3.Tuzak Karti\n"
         << "Seciminiz: ";
    std::cin >> secim;
    std::cin.ignore(); // Temizle cin buffer
    std::ofstream dosya(dosyaAdi, std::ios::app);
    if (!dosya.is_open())
    {
        std::cout << "Dosya acilamadi:" << dosyaAdi << std::endl;
        return;
    }
    if (secim == 1)
    {
        canavarKart c;
        c.ID = ID;
        c.ad = ad;
        c.cesit = "canavar";
        std::cout << "tip: ";
        std::getline(std::cin, c.tip);
        std::cout << "ozellik: ";
        std::getline(std::cin, c.ozellik);
        std::cout << "atk: ";
        std::cin >> c.atk;
        std::cout << "def: ";
        std::cin >> c.def;
        canavarlar.push_back(c);

        dosya << c.ID << "," << c.ad << "," << c.cesit
              << "," << c.tip << "," << c.ozellik << "," << c.atk << "," << c.def << "\n";
        std::cout << "Canavar karti basariyla eklendi." << std::endl;
    }
    else if (secim == 2)
    {
        sihirKart s;
        s.ID = ID;
        s.ad = ad;
        s.cesit = "sihir";
        std::cout << "atkEtki: ";
        std::cin >> s.atkEtki;
        std::cout << "defEtki: ";
        std::cin >> s.defEtki;
        std::cout << "lpEtki: ";
        std::cin >> s.lpEtki;
        std::cout << "hedefMons: ";
        std::cin.ignore(); // Temizle cin buffer
        std::getline(std::cin, s.hedefMons);
        sihirler.push_back(s);

        dosya << s.ID << "," << s.ad << "," << s.cesit
              << "," << s.atkEtki << "," << s.defEtki << "," << s.lpEtki << "," << s.hedefMons << "\n";
        std::cout << "Sihir karti basariyla eklendi." << std::endl;
    }
    else if (secim == 3)
    {
        tuzakKart t;
        t.ID = ID;
        t.ad = ad;
        t.cesit = "tuzak";
        std::cout << "atkEtki: ";
        std::cin >> t.atkEtki;
        std::cout << "defEtki: ";
        std::cin >> t.defEtki;
        std::cout << "lpEtki: ";
        std::cin >> t.lpEtki;
        std::cout << "hedefMons: ";
        std::cin.ignore(); // Temizle cin buffer
        std::getline(std::cin, t.hedefMons);
        tuzaklar.push_back(t);

        dosya << t.ID << "," << t.ad << "," << t.cesit
              << "," << t.atkEtki << "," << t.defEtki << "," << t.lpEtki << "," << t.hedefMons << "\n";
        std::cout << "Tuzak karti basariyla eklendi." << std::endl;
    }
    else
    {
        std::cout << "Gecersiz secim. Lütfen 1, 2 veya 3 girin." << std::endl;
        return;
    }
}

void kartlariOku(const std::string &dosyaAdi, std::vector<canavarKart> &canavarlar,
                 std::vector<sihirKart> &sihirler,
                 std::vector<tuzakKart> &tuzaklar)

{
    std::ifstream file(dosyaAdi);
    if (!file)
    {
        std::cout << "Dosya acilamadi:" << dosyaAdi << std::endl;
        return;
    }
    std::string satir;
    while (std::getline(file, satir))
    {
        std::stringstream ss(satir);
        std::string idStr, ad, cesit;
        std::getline(ss, idStr, ',');
        std::getline(ss, ad, ',');
        std::getline(ss, cesit, ',');

        if (cesit == "canavar")
        {
            std::string tip, ozellik, atkStr, defStr;
            std::getline(ss, tip, ',');
            std::getline(ss, ozellik, ',');
            std::getline(ss, atkStr, ',');
            std::getline(ss, defStr, ',');
            canavarKart c;
            c.ID = std::stoi(idStr);
            c.ad = ad;
            c.cesit = cesit;
            c.tip = tip;
            c.ozellik = ozellik;
            c.atk = std::stoi(atkStr);
            c.def = std::stoi(defStr);
            canavarlar.push_back(c);
        }
        else if (cesit == "sihir")
        {
            std::string atkEtkiStr, defEtkiStr, lpEtkiStr, hedefMons, kacMons;
            std::getline(ss, atkEtkiStr, ',');
            std::getline(ss, defEtkiStr, ',');
            std::getline(ss, lpEtkiStr, ',');
            std::getline(ss, hedefMons, ',');
            sihirKart s;
            s.ID = std::stoi(idStr);
            s.ad = ad;
            s.cesit = cesit;
            s.atkEtki = std::stoi(atkEtkiStr);
            s.defEtki = std::stoi(defEtkiStr);
            s.lpEtki = std::stoi(lpEtkiStr);
            s.hedefMons = hedefMons;
            sihirler.push_back(s);
        }
        else if (cesit == "tuzak")
        {
            std::string atkEtkiStr, defEtkiStr, lpEtkiStr, hedefMons, kacMons;
            std::getline(ss, atkEtkiStr, ',');
            std::getline(ss, defEtkiStr, ',');
            std::getline(ss, lpEtkiStr, ',');
            std::getline(ss, hedefMons, ',');
            tuzakKart t;
            t.ID = std::stoi(idStr);
            t.ad = ad;
            t.cesit = cesit;
            t.atkEtki = std::stoi(atkEtkiStr);
            t.defEtki = std::stoi(defEtkiStr);
            t.lpEtki = std::stoi(lpEtkiStr);
            t.hedefMons = hedefMons;
            tuzaklar.push_back(t);
        }
    }
    file.close();
    std::cout << "Kartlar dosyadan okundu." << std::endl;
}

void kartCek(std::vector<canavarKart> &monsDestesi,
             std::vector<sihirKart> &sihirDestesi,
             std::vector<tuzakKart> &tuzakDestesi,
             std::vector<canavarKart> &elMons,
             std::vector<sihirKart> &elSihir,
             std::vector<tuzakKart> &elTuzak)
{
    if (monsDestesi.empty() && sihirDestesi.empty() && tuzakDestesi.empty())
    {
        std::cout << "Destede cekilecek kart kalmadi!" << std::endl;
        return;
    }
    while (true)
    {
        int secim = std::rand() % 3;
        if (secim == 0 && !monsDestesi.empty())
        {
            int i = std::rand() % monsDestesi.size();
            elMons.push_back(monsDestesi[i]);
            monsDestesi.erase(monsDestesi.begin() + i);
            break;
        }
        else if (secim == 1 && !sihirDestesi.empty())
        {
            int i = std::rand() % sihirDestesi.size();
            elSihir.push_back(sihirDestesi[i]);
            sihirDestesi.erase(sihirDestesi.begin() + i);
            break;
        }
        else if (secim == 2 && !tuzakDestesi.empty())
        {
            int i = std::rand() % tuzakDestesi.size();
            elTuzak.push_back(tuzakDestesi[i]);
            tuzakDestesi.erase(tuzakDestesi.begin() + i);
            break;
        }
    }
}

// el goster
void elGoster(std::vector<canavarKart> &elMons,
              std::vector<sihirKart> &elSihir,
              std::vector<tuzakKart> &elTuzak)
{
    std::cout << " ------------------------------" << std::endl;
    std::cout << "|" << " Elinizdeki canavar kartlari: " << "|" << std::endl;
    std::cout << " ------------------------------" << std::endl;
    for (const auto &kart : elMons)
    {
        std::cout << kart.ad << " (ATK: " << kart.atk << ", DEF: " << kart.def << ")" << std::endl;
    }
    std::cout << " ----------------------------" << std::endl;
    std::cout << "|" << " Elinizdeki sihir kartlari: " << "|" << std::endl;
    std::cout << " ----------------------------" << std::endl;
    for (const auto &kart : elSihir)
    {
        std::cout << kart.ad << " (ATK Etki: " << kart.atkEtki << ", DEF Etki: " << kart.defEtki << ", LP Etki: " << kart.lpEtki << ")" << std::endl;
    }
    std::cout << " ----------------------------" << std::endl;
    std::cout << "|" << " Elinizdeki tuzak kartlari: " << "|" << std::endl;
    std::cout << " ----------------------------" << std::endl;
    for (const auto &kart : elTuzak)
    {
        std::cout << kart.ad << " (ATK Etki: " << kart.atkEtki << ", DEF Etki: " << kart.defEtki << ", LP Etki: " << kart.lpEtki << ")" << std::endl;
    }

    if (elMons.empty() && elSihir.empty() && elTuzak.empty())
    {
        std::cout << "Elinizde kart kalmadi! Turu atliyorsunuz." << std::endl;
    }
}