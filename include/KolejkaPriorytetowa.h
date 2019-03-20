#ifndef KOLEJKAPRIORYTETOWA_H
#define KOLEJKAPRIORYTETOWA_H
#include <iostream>

template <typename Typ>
class ElementKolejkiPriorytetowej{
    Typ wart;
    int priorytet;
    ElementKolejkiPriorytetowej<Typ>* nast;
public:
    ElementKolejkiPriorytetowej(Typ wartosc, int prio) {wart = wartosc; priorytet = prio; nast = nullptr;}
    Typ pokazWart() const {return wart;}
    int pokazPrio() const {return priorytet;}
    ElementKolejkiPriorytetowej<Typ>* pokazNast() const {return nast;}
    void ustawNast(ElementKolejkiPriorytetowej<Typ>* elem) {nast = elem;}
};

////////////////////////////////////////////////////////////////////////////////

template <typename Typ>
class KolejkaPriorytetowa{
    ElementKolejkiPriorytetowej<Typ>* glowa;
    public:
        ElementKolejkiPriorytetowej<Typ>* pokazGlowe() const {return glowa;}
        KolejkaPriorytetowa() {glowa = nullptr;}
        void enqueue(Typ a, int prio);
        Typ dequeue();
        ~KolejkaPriorytetowa<Typ>();
    protected:

    private:
};

////////////////////////////////////////////////////////////////////////////////

template <typename Typ>
void KolejkaPriorytetowa<Typ>::enqueue(Typ a, int prio){
    if(this->glowa == nullptr) glowa =  new ElementKolejkiPriorytetowej<Typ>(a, prio);
    else if(glowa->pokazPrio() < prio) {
        ElementKolejkiPriorytetowej<Typ>* nowy = new ElementKolejkiPriorytetowej<Typ>(a, prio);
        nowy->ustawNast(glowa);
        glowa = nowy;
    }
    else {
        ElementKolejkiPriorytetowej<Typ>* buff = glowa;
        while(buff->pokazNast() != nullptr){
            if(buff->pokazNast()->pokazPrio() < prio) break;
            buff = buff->pokazNast();
        }
        ElementKolejkiPriorytetowej<Typ>* nowy = new ElementKolejkiPriorytetowej<Typ>(a, prio);
        nowy->ustawNast(buff->pokazNast());
        buff->ustawNast(nowy);
    }
}

////////////////////////////////////////////////////////////////////////////////

template <typename Typ>
Typ KolejkaPriorytetowa<Typ>::dequeue(){
    ElementKolejkiPriorytetowej<Typ>* buff = glowa->pokazNast();
    Typ wart = glowa->pokazWart();
    delete glowa;
    glowa = buff;
    return wart;
}

////////////////////////////////////////////////////////////////////////////////

template <typename Typ>
std::ostream& operator << (std::ostream& str, const ElementKolejkiPriorytetowej<Typ>& obj){
    const ElementKolejkiPriorytetowej<Typ>* buff = &obj;

        str << buff->pokazWart() << " (" << buff->pokazPrio() << ")";
    return str;
}

//////////////////////////////////////////////////////////////////////////////

template <typename Typ>
KolejkaPriorytetowa<Typ>::~KolejkaPriorytetowa<Typ>(){
    ElementKolejkiPriorytetowej<Typ>* buff = glowa;
    ElementKolejkiPriorytetowej<Typ>* buff2 = glowa;
    while(buff != nullptr){
        buff2 = buff->pokazNast();
        delete buff;
        buff = buff2;
    }

}

////////////////////////////////////////////////////////////////////////////////

template <typename Typ>
std::ostream& operator << (std::ostream& str, const KolejkaPriorytetowa<Typ>& obj){
    const ElementKolejkiPriorytetowej<Typ>* buff = obj.pokazGlowe();
    while(buff != nullptr){
        str << *buff << std::endl;
        buff = buff->pokazNast();
    }
    return str;

}

#endif // KOLEJKAPRIORYTETOWA_H
