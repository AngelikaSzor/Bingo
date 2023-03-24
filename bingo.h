#ifndef BINGO_H
#define BINGO_H

#include <iostream>
#include <fstream>
#include <string>
#include <lista.h>
#include <ctime>
#include <cstdlib>

class Bingo
{
public:
    Bingo();
    ~Bingo();

    std::string** utworz_tablice2D(int rozmiar);
    void usun_tablice2D();
    void wydrukuj_tablice2D();
    void wczytaj_z_pliku(const std::string &sciezka, Lista &lista);
    Lista get_sciezki();
    Lista get_hasla();
    void losowanie_hasel();
    void skresl_w_tablicy();
    int* utworz_tablice1D(int rozmiar);
    void usun_tablice1D(int* tablica1D);
    void wyzeruj_tablice1D(int* tablica1D);
    void wydrukuj_tablice1D(int* tablica1D);
    int* get_suma_wiersze();
    int* get_suma_kolumny();
    bool czy_koniec_gry();
    int sprawdzenie_int();
    int set_rozmiar();
    int set_wk();

private:
    std::string ** hasla;
    int rozmiar;
    int* suma_kolumny;
    int* suma_wiersze;
    Lista lista_sciezek;
    Lista lista_hasel;
};

#endif // BINGO_H
