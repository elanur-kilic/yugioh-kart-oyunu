#ifndef KARTLAR_H
#define KARTLAR_H
#include <string>
#include <vector>

struct kart
{
    int ID;
    std::string ad;
    std::string cesit;
};

struct canavarKart : kart
{
    std::string tip;     // Örneğin: "Savaşçı", "Ejderha", vb. earth(t)
    std::string ozellik; // Örneğin: "Işık", "Karanlık", vb.
    int atk;
    int def;
};

struct sihirKart : kart
{
    int atkEtki;
    int defEtki;
    int lpEtki;
    std::string hedefMons; // örneğin: rakip tüm , dark magıcian, kendi tüm,ejderha,karanlik,isik
};

struct tuzakKart : kart
{
    int atkEtki;
    int defEtki;
    int lpEtki;
    std::string hedefMons; // örneğin: rakip tüm , dark magıcian, kendi tüm,ejderha,karanlik,isik
};

#endif
