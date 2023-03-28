#include "lista.h"

Lista::Lista()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->rozmiar = 0;
    //std::cout<<"[d] utworzono liste head: " << this->head<<'\n';
}
Lista::~Lista()
{
    //std::cout << "[d] usuwam liste head: " << this->head;
    while(this->head)
    {
       Element_listy* temp = this->head;
       this->head = this->head->next;
       delete temp;
    }
    this->tail=nullptr;

    //std::cout<<"[d] usunieto liste\n";
}

void Lista::dodaj_na_koncu(std::string &napis)
{
    Element_listy* temp = new Element_listy;
    temp->dane = napis;
    temp->next = nullptr;
    if(this->head == nullptr)
    {
        this->head = temp;
        //std::cout<<"head: "<<this->head<<'\n';
        this->tail = temp;
    }
    else
    {
        this->tail->next = temp;
        //std::cout<<"tail: "<<this->tail<< ' ' << "tail->next: " << tail->next << '\n';
        this->tail = this->tail->next;
    }
    this->rozmiar ++;
    //std::cout << "rozmiar: " << this->rozmiar << '\n';
   //std::cout<<"[d] dodano element na koniec\n";
}

std::string Lista::wyjmij_z_listy(int indeks)
{
    std::string wyjety;
    Element_listy* temp;
    temp = this->head;
    if(indeks == 0)
    {
        wyjety = temp->dane;
        this->head = this->head ->next ;
        delete temp;
    }
    else
    {
        for(int i=0; i<indeks-1; i++)
        {
            temp = temp->next;
        }
        Element_listy* temp2;
        wyjety = temp->next->dane;
        temp2 = temp->next->next;
        delete temp->next;

        temp->next = temp2;

    }
    this->rozmiar--;
    //std::cout<<"[d] wyjeto element z listy\n";
    return wyjety;
}

void Lista::drukuj_liste()
{
    Element_listy* it = this->head;
    int iteracja=0;
    while(it)
    {
        std::cout<<iteracja<<". "<<it->dane<<'\n';
        it = it->next;
        iteracja++;
    }

    //std::cout <<"[d] wydrukowano liste\n";
}
int Lista::sprawdzenie_int()
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
    std::cout<<"[d] pobrano bezpiecznie inta\n";
    return n;
}
void Lista::getDane( std::string &dane)
{

    Element_listy *temp;
    temp = this->head;
    int indeks = 0;
    indeks = sprawdzenie_int();
    while(indeks<-1 || indeks>3)
    {
        if(indeks>-1 && indeks<4)
        {
            for(int i = 0; i < indeks+1; i++)
            {
                temp = temp->next;
            }
            dane = temp->dane;
        }
        else
        {
            std::cout<<"\nPodaj poprawny numer wybranej bazy hasel\n";
            indeks = sprawdzenie_int();
        }

    }
}

int Lista::get_rozmiar()
{
    return this->rozmiar;
}


