#ifndef KOLEJKA_H
#define KOLEJKA_H
#include <iostream>

template <typename Typ>
class ElementKolejki{
    Typ wart;
    ElementKolejki<Typ>* nast;
public:
    ElementKolejki(Typ wartosc) {wart = wartosc; nast = nullptr;}
    Typ pokazWart() const {return wart;}
    ElementKolejki<Typ>* pokazNast() const {return nast;}
    void ustawNast(ElementKolejki<Typ>* elem) {nast = elem;}
};

////////////////////////////////////////////////////////////////////////////////

template <typename Typ>
class Kolejka{
    ElementKolejki<Typ>* glowa;
    public:
        ElementKolejki<Typ>* pokazGlowe() const {return glowa;}
        Kolejka<Typ>() {glowa = nullptr;}
        void enqueue(Typ a);
        Typ dequeue();
        ~Kolejka<Typ>();
    protected:

    private:
};

////////////////////////////////////////////////////////////////////////////////

template <typename Typ>
void Kolejka<Typ>::enqueue(Typ a){
    if(this->glowa == nullptr) glowa =  new ElementKolejki<Typ>(a);
    else {
        ElementKolejki<Typ>* buff = glowa;
        ElementKolejki<Typ>* nowy = new ElementKolejki<Typ>(a);
        nowy->ustawNast(buff->pokazNast());
        buff->ustawNast(nowy);
    }
}

////////////////////////////////////////////////////////////////////////////////

template <typename Typ>
Typ Kolejka<Typ>::dequeue(){
    ElementKolejki<Typ>* buff = glowa->pokazNast();
    Typ wart = glowa->pokazWart();
    delete glowa;
    glowa = buff;
    return wart;
}

////////////////////////////////////////////////////////////////////////////////

template <typename Typ>
std::ostream& operator << (std::ostream& str, const ElementKolejki<Typ>& obj){
    const ElementKolejki<Typ>* buff = &obj;

        str << buff->pokazWart();
    return str;
}

////////////////////////////////////////////////////////////////////////////////

template <typename Typ>
Kolejka<Typ>::~Kolejka<Typ>(){
    ElementKolejki<Typ>* buff = glowa;
    ElementKolejki<Typ>* buff2 = glowa;
    while(buff != nullptr){
        buff2 = buff->pokazNast();
        delete buff;
        buff = buff2;
    }
}

////////////////////////////////////////////////////////////////////////////////

template <typename Typ>
std::ostream& operator << (std::ostream& str, const Kolejka<Typ>& obj){
    const ElementKolejki<Typ>* buff = obj.pokazGlowe();
    while(buff != nullptr){
        str << *buff << std::endl;
        buff = buff->pokazNast();
    }
    return str;

}

#endif // KOLEJKAPRIORYTETOWA_H
