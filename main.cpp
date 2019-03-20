#include <iostream>
#include <vector>
#include <list>
#include "Lista.h"
#include "Stos.h"
#include "KolejkaPriorytetowa.h"
#include "Kolejka.h"
#include "TablicaMieszajaca.h"

using namespace std;

void testListy(){
   ListaDwukierunkowa<int>* obj = new ListaDwukierunkowa<int>();

   obj->dodajOgon(15);
   obj->dodajOgon(20);
   obj->dodajOgon(25);
   obj->dodajGlowe(14);
   obj->dodajWSrodku(30,2);
   obj->dodajWSrodku(222,10);
   obj->dodajWSrodku(0,4);
   obj->usunSrodek(2);
   obj->usunSrodek(3);

    cout << "Zawartosc listy:" << endl;
    cout << *obj << endl;
    cout << "Pierwszy (po glowie) wyraz listy: " << *(*obj)[1] << endl;
    delete obj;
}

///////////////////////////////////////////////////////////////////////

void testStosu(){
    Stos<int>* stos = new Stos<int>;
    stos->push(2);
    stos->push(3);
    stos->push(4);
    stos->push(5);

    stos->pop();

    cout << "Zawartosc stosu: " << endl;
    cout << *stos << endl;
    cout << "Czy stos jest pusty?: " << stos->isEmpty() << endl;
}

/////////////////////////////////////////////////////////////////////

void testKP(){
    KolejkaPriorytetowa<int> kolejka ;
    kolejka.enqueue(2, 10);
    kolejka.enqueue(3, 15);
    kolejka.enqueue(7, 1);
    kolejka.enqueue(20, 5);
    kolejka.enqueue(32, 20);
    kolejka.dequeue();
    kolejka.dequeue();

    cout << "Zawartosc kolejki priorytetowej (priorytet):" << endl;
    cout << kolejka << endl;
}

////////////////////////////////////////////////////////////////////

void testKolejki(){
    Kolejka<int>* kolejka = new Kolejka<int>;
    kolejka->enqueue(1);
    kolejka->enqueue(2);
    kolejka->enqueue(3);
    kolejka->enqueue(4);
    kolejka->enqueue(5);
    kolejka->dequeue();
    kolejka->dequeue();

    cout << "Zawartosc kolejki:" << endl;
    cout << *kolejka << endl;
}

////////////////////////////////////////////////////////

int hashCalcInt(const int& i){

    int k = i;
    int hash = 1;
    while(k>0){
        hash = hash * i;
        hash ^= k;
        k/=2;
    }

    return hash;
}

//////////////////////////////////////////////////////

int hashCalcString(const string& i){

    int hash = 1;

    for(int j=0;j<i.size();++j){
        hash += i[j];
        hash ^= j;
    }

    return hash;
}

///////////////////////////////////////////////////////

void testTablicyMieszajacej(){
    cout << "======Tablica int(key: int)======" << endl;
    TablicaMieszajaca<int, int> tab(10, hashCalcInt);
    tab.insert(1000, 1);
    tab.insert(1001, 12);
    tab.insert(1002, 13);
    tab.insert(1003, 14);
    tab.insert(1004, 15);

    cout << "Tablica intow: \n" << tab << endl;

    cout << "======Tablica string(key: string)======" << endl;
    TablicaMieszajaca<string, string> stringTab(10, hashCalcString);
    stringTab.insert("AAA", "ala");
    stringTab.insert("BBB", "ma");
    stringTab.insert("CCC", "malego");
    stringTab.insert("ABC", "szarego");
    stringTab.insert("CBA", "kotka");

    cout << stringTab << endl;
    cout << "Pobranie 'AAA': " << stringTab["AAA"] << endl;
    cout << "Pobranie 'AAA'[0]: " << *(stringTab["AAA"][0]) << endl;

    stringTab.remove("AAA");
    stringTab.remove("BBB");
    stringTab.remove("CCC");
    stringTab.remove("ABC");
    stringTab.remove("CBA");

    cout << "Tablica po usunieciu wszystkich kluczy: \n" << stringTab << endl;
}

///////////////////////////////////////////////////////////////////////

int main()
{
    cout << "Test tablicy mieszajacej:" << endl;
    testTablicyMieszajacej();
    cout << endl;
    cout << "Test kolejki:" << endl;
    testKolejki();
    cout << endl;
    cout << "Test listy:" << endl;
    testListy();
    cout << endl;
    cout << "Test stosu:" << endl;
    testStosu();
    cout << endl;
    cout << "Test kolejki priorytetowej:" << endl;
    testKP();

    return 0;
}
