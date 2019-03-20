#ifndef TABLICAMIESZAJACA_H
#define TABLICAMIESZAJACA_H

#include "Lista.h"


template<typename Typ, typename TypKlucza>
class TablicaMieszajaca
{
    ListaDwukierunkowa<Typ>* array;
    int rozmiar;
    int (*func)(const TypKlucza& key);

public:
    TablicaMieszajaca(int n, int (*func)(const TypKlucza& key)){
        array = new ListaDwukierunkowa<Typ>[n];
        rozmiar = n;
        this->func = func;
    }

    ~TablicaMieszajaca(){
        delete[] array;
    }

    int calcIndex(const TypKlucza& key){
        int index = func(key) % rozmiar;
        if(index < 0) index+=rozmiar;
        return index;
    }

    void insert(const TypKlucza& key, const Typ& value){
        int index = calcIndex(key);
        array[index].dodajOgon(value);
    }

    ListaDwukierunkowa<Typ>& operator[](const TypKlucza& key){
        int index = calcIndex(key);
        return array[index];
    }

    void remove(const TypKlucza& key){
        int index = calcIndex(key);
        array[index].empty(); //usun wszystkie elementy z z listy
    }

    friend std::ostream& operator<<(std::ostream& str, const TablicaMieszajaca& obj){

        for(int i=0;i<obj.rozmiar;++i){
            str<<"["<<obj.array[i]<<"]"<<std::endl;
        }

        return str;
    }
};




#endif // TABLICAMIESZAJACA_H
