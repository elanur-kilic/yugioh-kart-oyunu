#include "kartlar.h"
#include "mezar.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>


// yok edilen kartlar
// bu fonksiyon yok edilen kartları bir dosyaya yazabilir
void mezar(const std::string &dosyaAdi, const std::vector<kart> &yokEdilenKartlar, const std::vector<canavarKart> &yokEdilenCanavarlar,
                          const std::vector<sihirKart> &yokEdilenSihirler,
                          const std::vector<tuzakKart> &yokEdilenTuzaklar)
{
    std::ofstream dosya(dosyaAdi, std::ios::app);
    if (!dosya.is_open())
    {
        std::cout << "Dosya acilamadi: " << dosyaAdi << std::endl;
        return;
    }
    for (const auto &kart : yokEdilenKartlar)
    {
        dosya << kart.ID << "," << kart.ad << "," << kart.cesit;

        if (kart.cesit == "canavar")
        {
            for (const auto &canavar : yokEdilenCanavarlar)
            {
                if (canavar.ID == kart.ID)
                {
                    dosya << "," << canavar.tip << "," << canavar.ozellik << "," << canavar.atk << "," << canavar.def << "\n";
                    break; // Kart bulundu, döngüden çık
                }
            }
        }
        else if (kart.cesit == "sihir")
        {
            for (const auto &sihir : yokEdilenSihirler)
            {
                if (sihir.ID == kart.ID)
                {
                    dosya << "," << sihir.atkEtki << "," << sihir.defEtki << "," << sihir.lpEtki << "," << sihir.hedefMons << "\n";
                    break; // Kart bulundu, döngüden çık
                }
            }
        }
        else if (kart.cesit == "tuzak")
        {
            for (const auto &tuzak : yokEdilenTuzaklar)
            {
                if (tuzak.ID == kart.ID)
                {
                    dosya << "," << tuzak.atkEtki << "," << tuzak.defEtki << "," << tuzak.lpEtki << "," << tuzak.hedefMons << "\n";
                    break; // Kart bulundu, döngüden çık
                }
            }
        }
        else
        {
            std::cout << "Bilinmeyen kart cesidi: " << kart.cesit << std::endl;
        }
        std::cout << kart.ad << "adli kart dosyaya yazildi: " << dosyaAdi << std::endl;
    }
    dosya << "\n";
    dosya.close();
}

// mezardaki kartlari goster
void mezariAc(const std::string &dosyaAdi)
{
    std::ifstream dosya(dosyaAdi);
    if (!dosya.is_open())
    {
        std::cout << "Dosya acilamadi: " << dosyaAdi << std::endl;
        return;
    }
    std::string satir;
    std::cout << "Mezarlik:\n";
    while (std::getline(dosya, satir))
    {
        std::cout << satir << std::endl;
    }
    dosya.close();
}

// oyun bitince mezari temizle
void mezariTemizle(const std::string &dosyaAdi)
{
    std::ofstream dosya(dosyaAdi, std::ios::trunc); // Dosyayi temizle
    if (!dosya.is_open())
    {
        std::cout << "Dosya acilamadi: " << dosyaAdi << std::endl;
        return;
    }
    dosya.close();
    std::cout << "Mezarlik temizlendi: " << dosyaAdi << std::endl;
}