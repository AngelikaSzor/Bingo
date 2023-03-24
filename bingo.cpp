#include "bingo.h"

Bingo::Bingo()
{
    std::cout<<"Podaj rozmiar tablicy (tablica jest kwadratowa XxX, podana liczba powinna byc liczba calkowita, wieksza od 1)\n";
    this->wczytaj_z_pliku("Hasla/Sciezki.txt", this->lista_sciezek);
    this->rozmiar = this->set_rozmiar();
    this->hasla = this->utworz_tablice2D(this->rozmiar);
    this->suma_wiersze = this->utworz_tablice1D(this->rozmiar);
    this->suma_kolumny = this->utworz_tablice1D(this->rozmiar);
    this->wyzeruj_tablice1D(this->suma_wiersze);
    this->wyzeruj_tablice1D(this->suma_kolumny);
}

Bingo::~Bingo()
{
    this->usun_tablice2D();
    this->usun_tablice1D(this->suma_wiersze);
    this->usun_tablice1D(this->suma_kolumny);
}

std::string** Bingo::utworz_tablice2D(int rozmiar)
{
    std::string ** tablica= new std::string *[rozmiar];
    for(int i=0; i<rozmiar; i++)
    {
        tablica[i] = new std::string [rozmiar];
    }
    return tablica;
}

void Bingo::usun_tablice2D()
{
    for(int i = 0; i < this->rozmiar; i++)
    {
      delete [] this->hasla[i];
    }
    delete[] this->hasla;
}
void Bingo::wydrukuj_tablice2D()
{
    for(int i=0; i<this->rozmiar; i++)
    {
        for(int j=0; j<this->rozmiar; j++)
        {
            std::cout << this->hasla [i][j] << ' ';
        }
        std::cout << '\n';
    }
}
void Bingo::wczytaj_z_pliku(const std::string &sciezka, Lista &lista)
{
  std::string line;
  std::ifstream plik;
  plik.open(sciezka.c_str());
  if(!plik.is_open())
  {
      std::cout<<"Nie znaleziono pliku\n";
  }
  else
  {
      //std::cout<<"przed petla\n";
     while(plik.good())
     {
  std::getline(plik,line);
//   std::cout<<line<<'\n';
    lista.dodaj_na_koncu(line);
     }
  }
}
Lista Bingo::get_sciezki()
{
    return this->lista_sciezek;
}

void Bingo::losowanie_hasel()
{
    srand(time(nullptr));
    std::string sciezka_do_pliku;
    std::string dane;
    this->lista_sciezek.getDane(0,sciezka_do_pliku);
    this->wczytaj_z_pliku(sciezka_do_pliku, this->lista_hasel);

    for(int i=0; i<this->rozmiar; i++)
    {
        for(int j=0; j<this->rozmiar; j++)
        {
           int id = rand()%this->lista_hasel.get_rozmiar();
           dane = lista_hasel.wyjmij_z_listy(id);
           this->hasla[i][j] = dane;
        }
    }
}
Lista Bingo::get_hasla()
{
    return this->lista_hasel;
}
void Bingo::skresl_w_tablicy()
{
    std::string podmiana = "X";
    int kolumna;
    int wiersz;
    std::cout<<"Podaj wiersz: \n";
    wiersz = set_wk();
    std::cout<<"Podaj kolumne: \n";
    kolumna = set_wk();
    while(this->hasla[wiersz-1][kolumna-1] == podmiana)
    {
        std::cout<<"Ta wartosc zostala juz skreslona\n";
        std::cout<<"Podaj wiersz: \n";
        wiersz = set_wk();
        std::cout<<"Podaj kolumne: \n";
        kolumna = set_wk();
    }

    this->hasla[wiersz-1][kolumna-1] = podmiana;
    this->suma_wiersze[wiersz-1]++;
    this->suma_kolumny[kolumna-1]++;
}


int* Bingo::utworz_tablice1D(int rozmiar)
{
    int* tablica= new int [rozmiar];
    return tablica;
}

void Bingo::usun_tablice1D(int* tablica1D)
{
    delete []tablica1D;
}

void Bingo::wyzeruj_tablice1D(int* tablica1D)
{
    for(int i=0; i<this->rozmiar; i++)
    {
        tablica1D[i]=0;
    }
}
void Bingo::wydrukuj_tablice1D(int* tablica1D)
{
    for(int i=0; i<this->rozmiar; i++)
    {
        std::cout<<tablica1D[i]<<' ';
    }
    std::cout<<'\n';
}

int* Bingo::get_suma_wiersze()
{
    return this->suma_wiersze;
}

int* Bingo::get_suma_kolumny()
{
    return this->suma_kolumny;
}

bool Bingo::czy_koniec_gry()
{
//jezeli wartosc w ktoryms elemencie tablicy 1D jest rowna 4 to koniec gry jezeli nie to zapetlenie do ponownego skreslenia
    for(int i=0; i<this->rozmiar; i++)
    {
        if(this->suma_wiersze[i]==this->rozmiar|| this->suma_kolumny[i]==this->rozmiar)
        {
            std::cout<<"\n!!!!!!!!!!!!BINGO!!!!!!!!!!!!\n";
            return 1;
        }
    }
    return 0;
}

int Bingo::sprawdzenie_int ()
{
    int n;
    std::cin >> n;
    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Niepoprawny numer. Prosze wpisac ponownie: \n";
        std::cin >> n;
    }
    std::cin.sync();
    return n;
}

int Bingo::set_rozmiar()
{
    int n= this->sprawdzenie_int();
    while(n<2)
    {
        std::cout<<"Bingo nie moze byc mniejsze niz 2x2\n";
        n= this->sprawdzenie_int();
    }
    return n;
}
int Bingo::set_wk()
{
    int n= this->sprawdzenie_int();
    while(n<1 || n>this->rozmiar)
    {
        std::cout<<"Podaj poprawny numer \n";
        n= this->sprawdzenie_int();
    }
    return n;
}
