#include "bingo.h"
#include "lista.h"

using namespace std;

int main()
{
    Bingo bingo;
    std::cout << "Wydrukuj sciezki do dostepnych list z haslami\n";
    bingo.get_sciezki().drukuj_liste();
    std::string str;

    bingo.get_sciezki().getDane(1, str);
    std::cout << "drukuj element 1\n";
    std:: cout<< str << '\n'<<'\n';
    bingo.losowanie_hasel();
    std::cout << "Bingo z haslami wylosowanymi z jednej z list\n";
    bingo.wydrukuj_tablice2D();
    //std::cout<<"\nlista hasel po losowaniu\n";
   // bingo.get_hasla().drukuj_liste();
    int wiersz=0,kolumna=0;
    while(!bingo.czy_koniec_gry())
    {
    bingo.skresl_w_tablicy();
    std::cout<<"tablica po zmianie 1\n";
    bingo.wydrukuj_tablice2D();
    bingo.wydrukuj_tablice1D(bingo.get_suma_wiersze());
    bingo.wydrukuj_tablice1D(bingo.get_suma_kolumny());
    }
    return 0;
}
