#ifndef LISTA_H
#define LISTA_H
#include <iostream>


template <typename Typ>
class ElementListy
{
    Typ wart;
    ElementListy<Typ>* nast;
    ElementListy<Typ>* poprz;

    public:
        ElementListy<Typ>(Typ a);
        ~ElementListy<Typ>();
        ElementListy<Typ>* ogon();
        Typ pokaz_wart() const {return wart;}
        ElementListy<Typ>* pokaz_nast() const {return nast;}
        ElementListy<Typ>* pokaz_poprz() const {return poprz;}
        ElementListy<Typ>* push_end(Typ a);
        ElementListy<Typ>* push_front(Typ a);
        ElementListy<Typ>* push_in_the_middle(Typ a, int gdzie);
        ElementListy<Typ>* remove(int ktory);
        ElementListy<Typ>* remove_end();
        ElementListy<Typ>* operator [] (int index);
    protected:

    private:
};

///////////////////////////////////////////////

template <typename Typ>
class ListaDwukierunkowa{
    ElementListy<Typ>* glowa;
    ElementListy<Typ>* ogon;
public:
    ListaDwukierunkowa<Typ>() {glowa = nullptr; ogon = nullptr;}
    ElementListy<Typ>* pokazGlowe() const {return glowa;}
    ElementListy<Typ>* pokazOgon() const {return ogon;}
    void dodajGlowe(Typ a);
    void dodajOgon(Typ a);
    void dodajWSrodku(Typ a, int gdzie);
    void usunGlowe();
    void usunOgon();
    void usunSrodek(int ktory);
    ElementListy<Typ>* operator [] (int ktory);
    ~ListaDwukierunkowa<Typ>();

    void empty(){
        ElementListy<Typ>*buff = glowa;
        ElementListy<Typ>*buff2 = glowa;
        while(buff != nullptr){
            buff2 = buff->pokaz_nast();
            delete buff;
            buff = buff2;
        }
        glowa = nullptr;
    }
};

////////////////////////////////////////////////////////////////////////////////////////

template <typename Typ>
ElementListy<Typ>::ElementListy(Typ a){
    nast = nullptr;
    poprz = nullptr;
    wart = a;
}

////////////////////////////////////////////////////////////////////////////////////

template <typename Typ>
ElementListy<Typ>::~ElementListy()
{
    //dtor
}

/////////////////////////////////////////////////////////////////////////////////////

template <typename Typ>
ElementListy<Typ>* ElementListy<Typ>::ogon(){
    ElementListy* buff;
    buff = this;
    while(buff->nast != nullptr){
        buff = buff->nast;
    }
    return buff;
}

/////////////////////////////////////////////////////////////////////////////////////

template <typename Typ>
ElementListy<Typ>* ElementListy<Typ>::push_end(Typ a){
    ElementListy* buff;
    buff = this;

    while(buff->nast != nullptr){
        buff = buff->nast;
    }
    ElementListy* elem = new ElementListy(a);
    buff->nast = elem;
    elem->poprz = buff;
    elem->nast = nullptr;

    return elem;
}

//////////////////////////////////////////////////////////////////////////////////////

template <typename Typ>
ElementListy<Typ>* ElementListy<Typ>::push_front(Typ a){
    ElementListy* elem = new ElementListy(a);
    elem->nast = this;
    this->poprz = elem;

    return elem;
}

//////////////////////////////////////////////////////////////////////////////////////

template <typename Typ>
ElementListy<Typ>* ElementListy<Typ>::push_in_the_middle(Typ a, int gdzie){
    if(gdzie == 0) return push_front(a);
    ElementListy* elem = new ElementListy(a);

    ElementListy* buff;
    ElementListy* buff2;
    buff = this;
    int i = 1;
    while(i < gdzie){
        buff = buff->nast;
        ++i;
        if(buff->nast == nullptr){
            buff->push_end(a);
            return this;
        }
    }

    buff2 = buff->nast;
    buff->nast = elem;
    elem->nast = buff2;
    buff2->poprz = elem;
    elem->poprz = buff;

    return this;
}

////////////////////////////////////////////////////////////////////////////////////

template <typename Typ>
ElementListy<Typ>* ElementListy<Typ>::remove(int ktory){
    ElementListy* buff = this;
    ElementListy* buff2 = buff->nast;
    ElementListy* poprz2;
    if(ktory == 0) {
        buff2->poprz = nullptr;
        delete buff;
        return buff2;
    }
    poprz2 = buff->poprz;
    int i = 0;
    while(i < ktory){
        buff = buff->nast;
        ++i;
        if(buff->nast == nullptr){
            buff2 = buff->poprz;
            delete buff;
            buff2->nast = nullptr;
            return this;
        }
    }
    buff2 = buff->nast;
    poprz2 = buff->poprz;
    poprz2->nast = buff2;
    buff2->poprz = poprz2;
    delete buff;
    return this;
}

//////////////////////////////////////////////////////////////////////////////////

template <typename Typ>
ElementListy<Typ>* ElementListy<Typ>::remove_end(){
    ElementListy<Typ>* buff = this;
    ElementListy<Typ>* buff2 = this;
    while(buff->pokaz_nast() != nullptr){
        buff = buff->nast;
    }
        buff2 = buff->poprz;
        delete buff;
        buff2->nast = nullptr;
        return this;
}

/////////////////////////////////////////////////////////////////////////////////

template <typename Typ>
ElementListy<Typ>* ElementListy<Typ>::operator [](int index){
    ElementListy<Typ>* buff = this;
    int i=0;

    if(index == 0) return this;

    while(i < index && buff->nast != nullptr){
        //std::cout << buff << std::endl;
        buff = buff->nast;
        if(buff->pokaz_nast() == nullptr) {
            return buff;
        }
        ++i;
    }
    return buff;
}

///////////////////////////////////////////////////////////////////////////////

template <typename Typ>
std::ostream& operator << (std::ostream& str, const ElementListy<Typ>& obj){
    const ElementListy<Typ>* buff;
    buff = &obj;
  //  while(buff != nullptr){
    str <<buff->pokaz_wart() << ", ";
 //   buff = buff->pokaz_nast();
   // }
    return str;

}

///////////////////////////////////////////////////////////////////////////////

template <typename Typ>
ListaDwukierunkowa<Typ>::~ListaDwukierunkowa<Typ>(){
    ElementListy<Typ>*buff = glowa;
    ElementListy<Typ>*buff2 = glowa;
    while(buff != nullptr){
        buff2 = buff->pokaz_nast();
        delete buff;
        buff = buff2;
    }
}

//////////////////////////////////////////////////////////////////////////////

template <typename Typ>
void ListaDwukierunkowa<Typ>::dodajGlowe(Typ a){
    //ElementListy<Typ>* buff;
    if(this->pokazGlowe() == nullptr){
        this->glowa = new ElementListy<Typ>(a);
        this->ogon = this->glowa;
    }
    else this->glowa = this->glowa->push_front(a);
    //this->glowa = buff;
}

/////////////////////////////////////////////////////////////////////////////

template <typename Typ>
void ListaDwukierunkowa<Typ>::dodajOgon(Typ a){
    //ElementListy<Typ>* buff;
    if(this->pokazOgon() == nullptr){
        this->ogon = new ElementListy<Typ>(a);
        this->glowa = this->ogon;
    }
    else this->ogon = this->ogon->push_end(a);
    //this->ogon;
}

/////////////////////////////////////////////////////////////////////////////

template <typename Typ>
void ListaDwukierunkowa<Typ>::dodajWSrodku(Typ a, int gdzie){
    if(this->pokazGlowe() == nullptr){
        this->glowa = new ElementListy<Typ>(a);
        this->ogon = this->glowa;
    }
    else if(this->pokazOgon() == nullptr){
        this->ogon = new ElementListy<Typ>(a);
        this->glowa = this->ogon;
    }
    else this->glowa->push_in_the_middle(a,gdzie);
}

///////////////////////////////////////////////////////////////////////////////

template <typename Typ>
void ListaDwukierunkowa<Typ>::usunGlowe(){
    if(this->pokazGlowe() == nullptr) std::cout << "brak glowy" << std::endl;
    else {
        this->glowa->remove(0);
        this->glowa = this->glowa->pokaz_nast();
    }
}

///////////////////////////////////////////////////////////////////////////////

template <typename Typ>
void ListaDwukierunkowa<Typ>::usunOgon(){
    if(this->pokazOgon() == nullptr) std::cout << "brak ogona" << std::endl;
    else this->glowa->remove_end();
}

////////////////////////////////////////////////////////////////////////////////

template <typename Typ>
void ListaDwukierunkowa<Typ>::usunSrodek(int ktory){
    if(this->pokazOgon() == nullptr || this->pokazGlowe() == nullptr) std::cout << "brak srodka" << std::endl;
    else this->glowa->remove(ktory);
}


template <typename Typ>
ElementListy<Typ>* ListaDwukierunkowa<Typ>::operator [] (int ktory){
    if(this->pokazGlowe() == nullptr) return nullptr;
    ElementListy<Typ>* buff = (*this->glowa)[ktory];
    return buff;
}

////////////////////////////////////////////////////////////////////////////////

template <typename Typ>
std::ostream& operator << (std::ostream& str, const ListaDwukierunkowa<Typ>& obj){
    if(obj.pokazGlowe() == nullptr) str << "[]";
    else {
        ElementListy<Typ>* buff = obj.pokazGlowe();
        while(buff != nullptr){
            str << *buff;
            buff = buff->pokaz_nast();
        }
    }
    return str;
}

#endif // LISTA_H




























