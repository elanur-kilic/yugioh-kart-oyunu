#ifndef OYUNA_BASLA_H
#define OYUNA_BASLA_H
#include "canavar.h"
#include "kartlar.h"
#include "kartIslemleri.h"
#include "mezar.h"
#include "savas.h"
#include "sihir.h"
#include "tuzak.h"
#include <string>
#include <vector>
void oyunMenu(std::string oyuncuAdi, std::vector<canavarKart> &elMons,
               std::vector<sihirKart> &elSihir, std::vector<tuzakKart> &elTuzak,
               std::vector<canavarKart> &monsAlan, std::vector<sihirKart> &sihirAlan,
               std::vector<tuzakKart> &tuzakAlan,std::vector<canavarKart> &rakipMons,
               int &LP, int &rakipLP,int &canavarSecim) ;

void desteSec(std::vector<canavarKart> &canavarlar, std::vector<sihirKart> &sihirler,
              std::vector<tuzakKart> &tuzaklar, int &secilenDeste, int digerSecilenDeste = 0 );


#endif
