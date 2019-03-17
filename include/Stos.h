#ifndef STOS_H
#define STOS_H
#include <iostream>

template <typename Typ>
class KomorkaStosu{
    Typ wart;
    KomorkaStosu<Typ>* nast;
public:
    KomorkaStosu<Typ>(Typ a) {wart = a; nast = nullptr;}
    Typ pokazWart() const {return wart;}
    const KomorkaStosu<Typ>* pokazNast() const {return nast;}
    KomorkaStosu<Typ>* pokazNast() {return nast;}
    void ustawNast(KomorkaStosu<Typ>* a);
};

template <typename Typ>
class Stos{
    KomorkaStosu<Typ>* glowa;
public:
    Stos<Typ>() {glowa = nullptr;}
    const KomorkaStosu<Typ>* pokazGlowe() const {return glowa;}
    void push(Typ a);
    Typ pop();
    bool isEmpty();
};

///////////////////////////////////////////////////////////////////////////////////

template <typename Typ>
void KomorkaStosu<Typ>::ustawNast(KomorkaStosu<Typ>* a){
    this->nast = a;
}

template <typename Typ>
std::ostream& operator << (std::ostream& str, const KomorkaStosu<Typ>& obj){
    str << obj.pokazWart();
    return str;
}

///////////////////////////////////////////////////////////////////////////////////

template <typename Typ>
void Stos<Typ>::push(Typ a){
    KomorkaStosu<Typ>* buff2 = new KomorkaStosu<Typ>(a);
    buff2->ustawNast(glowa);
    glowa = buff2;
    //std::cout << glowa << std::endl;
}

template <typename Typ>
Typ Stos<Typ>::pop(){
    KomorkaStosu<Typ>* buff = glowa->pokazNast();
    Typ ret = glowa->pokazWart();
    delete glowa;
    glowa = buff;
    return ret;
}

template <typename Typ>
bool Stos<Typ>::isEmpty(){
    if(glowa == nullptr) return 1;
    else return 0;
}

template <typename Typ>
std::ostream& operator << (std::ostream& str, const Stos<Typ>& obj){
    const KomorkaStosu<Typ>* buff = obj.pokazGlowe();
    while(buff != nullptr){
        str << *buff << std::endl;
        buff = buff->pokazNast();
    }
    return str;
}











/*
template <typename Typ>
class Stos{
    Typ element;
    Stos<Typ>* nast;

    public:
        Stos<Typ>() {nast = nullptr;}
        Stos<Typ>(Typ a) {nast = nullptr; element = a;}
        Stos<Typ>* pokaz_nast() const {return nast;}
        Typ pokaz_elem() const {return element;}
        Stos<Typ>* push(Typ a);
        Stos<Typ>* pop();

    protected:

    private:
};

template <typename Typ>
Stos<Typ>* Stos<Typ>::push(Typ a){
    Stos<Typ>* nowy = new Stos(a);
    nowy->nast = this;
    return nowy;
}

template <typename Typ>
Stos<Typ>* Stos<Typ>::pop(){
    Stos<Typ> buff = this;
    Stos<Typ> buff2 = buff->nast;
    delete buff;
    return buff2;
}

template <typename Typ>
std::ostream& operator << (std::ostream& str, const Stos<Typ>& obj){
    //std::cout << "ala ma kota" << std::endl;
    const Stos<Typ>* buff;
    buff = &obj;

    while (buff != nullptr){
        str << buff->pokaz_elem() << ", " << buff->pokaz_nast() << std::endl;
        buff = buff->pokaz_nast();
    }
    return str;
}

*/

#endif // STOS_H
