#include "kartlar.h"
#include "tuzak.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

// tuzak yerlestirme
void tuzakYerles(std::vector<tuzakKart> &elTuzak,
                 std::vector<tuzakKart> &tuzakAlan, int &LP)
{
    if (elTuzak.empty())
    {
        std::cout << "Elinizde tuzak karti yok!" << std::endl;
        return;
    }

    std::cout << "Elinizdeki tuzak kartlari:\n";
    for (size_t i = 0; i < elTuzak.size(); ++i)
    {
        std::cout << i + 1 << ". " << elTuzak[i].ad
             << " (ATK Etki: " << elTuzak[i].atkEtki
             << ", DEF Etki: " << elTuzak[i].defEtki
             << ", LP Etki: " << elTuzak[i].lpEtki << ")" << std::endl;
    }
    std::cout << "Yerlestirmek istediginiz tuzak kartinin numarasini girin(1-" << elTuzak.size() << ") " << std::endl;
    int tuzakSecim;
    std::cin >> tuzakSecim;
    // Kart seçimi sonrası cin.clear() + cin.ignore() eklemen iyi olur:
    std::cin.clear();             // Hatalı giriş varsa temizle
    std::cin.ignore(10000, '\n'); // Satırın geri kalanını temizle
    if (tuzakSecim >= 1 && tuzakSecim <= elTuzak.size())
    {
        tuzakKart secilenKart = elTuzak[tuzakSecim - 1];
        tuzakAlan.push_back(secilenKart);
        elTuzak.erase(elTuzak.begin() + tuzakSecim - 1);
        std::cout << secilenKart.ad << " tuzak karti yerlestirildi." << std::endl;
    }
    else
    {
        std::cout << "Gecersiz secim." << std::endl;
    }
}
