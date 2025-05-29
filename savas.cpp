#include "kartlar.h"
#include "canavar.h"
#include "oyunaBasla.h"
#include "kartIslemleri.h"
#include "savas.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

// savas alanındaki kartlar
void alandakiKartlar(const std::vector<canavarKart> &monsAlan, const std::vector<sihirKart> &sihirAlan,
                     const std::vector<tuzakKart> &tuzakAlan)
{
    std::cout << "Savas alanindaki kartlar:\n";
    std::cout << "Canavar Kartlari:\n";
    for (const auto &kart : monsAlan)
    {
        std::cout << kart.ID << "ID" << kart.ad << " (ATK: " << kart.atk << ", DEF: " << kart.def << ")\n";
    }

    std::cout << "Sihir Kartlari:\n";
    for (const auto &kart : sihirAlan)
    {
        std::cout << kart.ID << "ID" << kart.ad << " (ATK Etki: " << kart.atkEtki
                  << ", DEF Etki: " << kart.defEtki
                  << ", LP Etki: " << kart.lpEtki
                  << ", Hedef: " << kart.hedefMons << ")\n";
    }

    std::cout << "Tuzak Kartlari:\n";
    for (const auto &kart : tuzakAlan)
    {
        std::cout << kart.ID << "ID" << kart.ad << " (ATK Etki: " << kart.atkEtki
                  << ", DEF Etki: " << kart.defEtki
                  << ", LP Etki: " << kart.lpEtki
                  << ", Hedef: " << kart.hedefMons << ")\n";
    }
}

// savas
void savas(std::vector<canavarKart> &monsAlan, std::vector<canavarKart> &rakipMons,
           std::vector<canavarKart> &elMons, std::vector<sihirKart> &sihirAlan,
           std::vector<tuzakKart> &tuzakAlan,
           int &canavarSecim,
           int &LP, int &rakipLP)
{

    std::cout << "Savas basliyor...\n";
    std::cout << "Savas alanindaki canavarlar:\n";

    for (size_t i = 0; i < monsAlan.size(); ++i)
    {
        std::cout << i << "." << monsAlan[i].ID << "ID" << monsAlan[i].ad << " (ATK: " << monsAlan[i].atk
                  << ", DEF: " << monsAlan[i].def << ")\n";
    }

    // Savaş mantığını burada uygulayabilirsiniz
    // Örneğin, canavarların ATK ve DEF değerlerini karşılaştırarak savaş sonuçlarını belirleyebilirsiniz.
    // sahadaki canavarlari savastirmak icin sirala
}
