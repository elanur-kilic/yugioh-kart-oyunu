#ifndef SAVAS_H
#define SAVAS_H
#include "kartlar.h"
#include "canavar.h"
#include "oyunaBasla.h"
#include "kartIslemleri.h"
#include <string>
#include <vector>


void alandakiKartlar(const std::vector<canavarKart> &monsAlan,const std::vector<sihirKart> &sihirAlan,
                     const std::vector<tuzakKart> &tuzakAlan);

void savas(std::vector<canavarKart> &monsAlan, std::vector<canavarKart> &rakipMons,
           std::vector<canavarKart> &elMons, std::vector<sihirKart> &sihirAlan,
           std::vector<tuzakKart> &tuzakAlan,
           int &canavarSecim,
           int &LP, int &rakipLP);

#endif
