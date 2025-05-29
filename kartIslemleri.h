#ifndef KARTISLEMLERI_H
#define KARTISLEMLERI_H
#include "kartlar.h"
void kartEkle(const std::string dosyaAdi, std::vector<canavarKart> &canavarlar,
              std::vector<sihirKart> &sihirler,
              std::vector<tuzakKart> &tuzaklar);

void kartlariOku(const std::string &dosyaAdi, std::vector<canavarKart> &canavarlar,
                 std::vector<sihirKart> &sihirler,
                 std::vector<tuzakKart> &tuzaklar);

void kartCek(std::vector<canavarKart> &monsDestesi,
             std::vector<sihirKart> &sihirDestesi,
             std::vector<tuzakKart> &tuzakDestesi,
             std::vector<canavarKart> &elMons,
             std::vector<sihirKart> &elSihir,
             std::vector<tuzakKart> &elTuzak);

void elGoster(std::vector<canavarKart> &elMons,
              std::vector<sihirKart> &elSihir,
              std::vector<tuzakKart> &elTuzak);

#endif // KARTISLEMLERI_H