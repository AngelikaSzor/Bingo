#include "bingo.h"

Bingo::Bingo()
{
    std::cout<<"Podaj rozmiar tablicy gry\n";
    this->rozmiar = this->set_rozmiar();
    this->hasla = this->utworz_tablice2D(this->rozmiar);
    this->suma_kolumny = this->utworz_tablice1D(this->rozmiar);
    this->suma_wiersze = this->utworz_tablice1D(this-> rozmiar);
    this->wyzeruj_tablice1D(this->suma_kolumny);
    this->wyzeruj_tablice1D(this->suma_wiersze);

    this->lista_hasel = new Lista;
    this->lista_sciezek = new Lista;

    this->wczytaj_z_pliku("Hasla/Sciezki.txt", this->lista_sciezek);

    //std::cout<<"[d]utworzono obiekt bingo\n";
}

Bingo::~Bingo()
{
    this->usun_tablice2D();
    this->usun_tablice1D(this->suma_kolumny);
    this->usun_tablice1D(this->suma_wiersze);
    delete this->lista_hasel;
    delete this->lista_sciezek;
   // std::cout<<"[d]usunieto obiekt bingo\n";
}

std::string** Bingo::utworz_tablice2D(int rozmiar)
{
    std::string **tablica = new std::string *[rozmiar];
    for(int i=0; i<rozmiar; i++)
    {
        tablica[i] = new std::string [rozmiar];
    }
    //std::cout<<"[d]utworzono tablice 2d\n";
    return tablica;
}

void Bingo::usun_tablice2D()
{
    for(int i = 0; i<this->rozmiar; i++)
    {
      delete [] this->hasla[i];
    }
    delete[] this->hasla;
    //std::cout<<"[d] usunieto tablice 2d\n";
}

void Bingo::wydrukuj_tablice2D()
{
    for(int i=0; i<this->rozmiar; i++)
    {
        for(int j=0; j<this->rozmiar; j++)
        {
            std::cout<<this->hasla[i][j]<< std::setw(20);
        }
        std::cout<<'\n';
    }
    //std::cout<<"[d] wydrukowano tablice 2d\n";
}

int* Bingo::utworz_tablice1D(int rozmiar)
{
    int* tablica= new int [rozmiar];
    //std::cout<<"[d] utworzono tablice 1d\n";
    return tablica;
}

void Bingo::usun_tablice1D(int* tablica1D)
{
    delete []tablica1D;
    //std::cout << "[d] usunieto tablice 1d\n";
}

void Bingo::wyzeruj_tablice1D(int* tablica1D)
{
    for(int i=0; i<this->rozmiar; i++)
    {
        tablica1D[i]=0;
    }
    //std::cout<<"[d] wyzerowano tablice 1d\n";
}

void Bingo::wydrukuj_tablice1D(int* tablica1D)
{
    for(int i=0; i<this->rozmiar; i++)
    {
        std::cout<<tablica1D[i];
    }
    std::cout<<'\n';
    //std::cout<<"[d] wydrukowano tablice 1d\n";
}

void Bingo::wczytaj_z_pliku(const std::string &sciezka, Lista* lista)
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
        while(plik.good())
        {
            std::getline(plik,line);
            //std::cout<<line<<'\n';
            lista->dodaj_na_koncu(line);
        }
    }

    //std::cout<<"[d] wczytano z pliku do listy\n";
}

int Bingo::sprawdzenie_int()
{
    int n;
    std::cin >> n;
    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout<<"Niepoprawny numer. Prosze wpisac ponownie: \n";
        std::cin>>n;
    }
    std::cin.sync();
//    std::cout<<"[d] pobrano bezpiecznie inta\n";
    return n;
}

void Bingo::losowanie_hasel(const std::string &sciezka)
{
    srand(time(nullptr));
    std::string dane;
    this->wczytaj_z_pliku(sciezka, this->lista_hasel);

    for(int i=0; i<this->rozmiar; i++)
    {
        for(int j=0; j<this->rozmiar; j++)
        {
           int id = rand()%this->lista_hasel->get_rozmiar();
           dane = lista_hasel->wyjmij_z_listy(id);
           this->hasla[i][j] = dane;
        }
    }

    //std::cout<<"[d] wylosowano hasla\n";
}

void Bingo::skresl_w_tablicy()
{
    std::cout<<"\nPodaj odpowiednie wartosci aby skreslic wybrany element z tabeli\n";
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

    //std::cout<<"[d] skreslono w tablicy\n";
}

bool Bingo::czy_koniec_gry()
{
    for(int i=0; i<this->rozmiar; i++)
    {
        if(this->suma_wiersze[i] == this->rozmiar|| this->suma_kolumny[i] == this->rozmiar)
        {
            std::cout<<"\n!!!!!!!!!!!!BINGO!!!!!!!!!!!!\n";
            return 1;
        }
    }
    //std::cout<<"[d] to nie koniec gry\n";
    return 0;
}

Lista* Bingo::get_sciezki()
{
    //std::cout<<"[d] getter sciezek\n";
    return this->lista_sciezek;
}

Lista* Bingo::get_hasla()
{
    //std::cout<<"[d] getter hasel\n";
    return this->lista_hasel;
}

int* Bingo::get_suma_wiersze()
{
    //std::cout<<"[d] getter wierszy\n";
    return this->suma_wiersze;
}

int* Bingo::get_suma_kolumny()
{
    //std::cout<<"[d] getter kolumn\n";
    return this->suma_kolumny;
}

int Bingo::set_rozmiar()
{
    int n = this->sprawdzenie_int();
    while(n<2)
    {
        std::cout<<"Bingo nie moze byc mniejsze niz 2x2\n";
        n = this->sprawdzenie_int();
    }
    while(n>3)
    {
        std::cout<<"Na ten moment w bazie danych nie ma wystarczajacej liczby hasel do zapelnienia tej wielkosci tablicy.\nSprobuj wybrac mnijeszy rozmiar:\n";
        n = this->sprawdzenie_int();
    }
    //std::cout<<"[d] ustawiono rozmiar\n";
    return n;
}

int Bingo::set_wk()
{
    int n = this->sprawdzenie_int();
    while(n<1 || n>this->rozmiar)
    {
        std::cout<<"Podaj poprawny numer \n";
        n = this->sprawdzenie_int();
    }
    //std::cout<<"[d] ustawiono wiersze/kolumny\n";
    return n;
}

