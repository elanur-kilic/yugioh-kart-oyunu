#include "kartlar.h"
#include "canavar.h"
#include "oyunaBasla.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

// canavar yerlestirme
void canavarYerles(std::vector<canavarKart> &elMons, std::vector<canavarKart> &rakipMons, int &canavarSecim,
                   std::vector<canavarKart> &monsAlan, int &LP)
{
    if (elMons.empty())
    {
        std::cout << "Elinizde canavar karti yok!" << std::endl;
        return;
    }

    std::cout << "Elinizdeki canavar kartlari:\n";
    for (size_t i = 0; i < elMons.size(); ++i)
    {
        std::cout << i + 1 << ". " << elMons[i].ad << " (ATK: " << elMons[i].atk
                  << ", DEF: " << elMons[i].def << ")" << std::endl;
    }
    std::cout << "Yerlestirmek istediginiz canavar kartinin numarasini girin(1-" << elMons.size() << ") " << std::endl;

    std::cin >> canavarSecim;
    // Kart seçimi sonrası cin.clear() + cin.ignore() eklemen iyi olur:
    std::cin.clear();             // Hatalı giriş varsa temizle
    std::cin.ignore(10000, '\n'); // Satırın geri kalanını temizle
    if (canavarSecim >= 1 && canavarSecim <= elMons.size())
    {
        canavarKart secilenKart = elMons[canavarSecim - 1];
        monsAlan.push_back(secilenKart);
        elMons.erase(elMons.begin() + canavarSecim - 1);
        std::cout << secilenKart.ad << " canavar karti yerlestirildi." << std::endl;
    }
    else
    {
        std::cout << "Gecersiz secim." << std::endl;
    }
}
