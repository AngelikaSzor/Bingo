#include "lista.h"

Lista::Lista()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->rozmiar = 0;
}
Lista::~Lista()
{
    while(this->head)
    {
       Element_listy* temp = this->head;
       this->head = this->head->next;
       delete temp;
    }
    this->tail=nullptr;
}

void Lista::dodaj_na_koncu(std::string &napis)
{
    Element_listy* temp = new Element_listy;
    temp->dane = napis;
    temp->next = nullptr;
    if(this->head == nullptr)
    {
        this->head = temp;
       // std::cout<<"head: "<<this->head<<'\n';
        this->tail = temp;
    }
    else
    {
        this->tail->next = temp;
       //std::cout<<"tail: "<<this->tail<< ' ' << "tail->next: " << tail->next << '\n';
        this->tail = this->tail->next;
    }
    this->rozmiar ++;
   //std::cout << this->rozmiar << '\n';
}
void Lista::drukuj_liste()
{
    Element_listy* it = this->head;
    int iteracja=1;
    while(it)
    {
        std::cout<<iteracja<<". "<<it->dane<<'\n';
        it = it->next;
        iteracja++;
    }
}

void Lista::getDane(int indeks, std::string &dane)
{
    Element_listy *temp;
    temp = this->head;
    for(int i = 0; i < indeks; i++)
    {
        temp = temp->next;
    }
    dane = temp->dane;
}

int Lista::get_rozmiar()
{
    return this->rozmiar;
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
    return wyjety;
}
