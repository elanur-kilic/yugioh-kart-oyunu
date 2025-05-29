#include "kartlar.h"
#include "sihir.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

// sihir yerlestirme
void sihirYerles(std::vector<sihirKart> &elSihir,
                 std::vector<sihirKart> &sihirAlan, int &LP)
{
    if (elSihir.empty())
    {
        std::cout << "Elinizde sihir karti yok!" << std::endl;
        return;
    }

    std::cout << "Elinizdeki sihir kartlari:\n";
    for (size_t i = 0; i < elSihir.size(); ++i)
    {
        std::cout << i + 1 << ". " << elSihir[i].ad
             << " (ATK Etki: " << elSihir[i].atkEtki
             << ", DEF Etki: " << elSihir[i].defEtki
             << ", LP Etki: " << elSihir[i].lpEtki << ")" << std::endl;
    }
    std::cout << "Yerlestirmek istediginiz sihir kartinin numarasini girin(1-" << elSihir.size() << ") " << std::endl;
    int sihirSecim;
    std::cin >> sihirSecim;
    // Kart seçimi sonrası cin.clear() + cin.ignore() eklemen iyi olur:
    std::cin.clear();             // Hatalı giriş varsa temizle
    std::cin.ignore(10000, '\n'); // Satırın geri kalanını temizle
    if (sihirSecim >= 1 && sihirSecim <= elSihir.size())
    {
        sihirKart secilenKart = elSihir[sihirSecim - 1];
        sihirAlan.push_back(secilenKart);
        elSihir.erase(elSihir.begin() + sihirSecim - 1);
        std::cout << secilenKart.ad << " sihir karti yerlestirildi." << std::endl;
        LP += secilenKart.lpEtki; // Sihir kartının LP etkisini ekle
    }
    else
    {
        std::cout << "Gecersiz secim." << std::endl;
    }
}
