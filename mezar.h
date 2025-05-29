#ifndef MEZAR_H
#define MEZAR_H
#include "kartlar.h"
#include <string>
#include <vector>

void mezar(const std::string &dosyaAdi, const std::vector<kart> &yokEdilenKartlar, const std::vector<canavarKart> &yokEdilenCanavarlar,
                          const std::vector<sihirKart> &yokEdilenSihirler,
                          const std::vector<tuzakKart> &yokEdilenTuzaklar);

void mezariAc(const std::string &dosyaAdi);

void mezariTemizle(const std::string &dosyaAdi);

#endif
