#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <string>

struct Element_listy
{
    std::string dane;
    Element_listy* next;
};

class Lista
{
public:
    Lista();
    ~Lista();
    void dodaj_na_koncu(std::string &napis);
    void drukuj_liste();
    void getDane(int indeks, std::string &dane);
    int get_rozmiar();
    std::string wyjmij_z_listy(int indeks);
    void skreslenie(int indeks);
private:
    Element_listy* head;
    Element_listy* tail;
    int rozmiar;
};

#endif // LISTA_H
