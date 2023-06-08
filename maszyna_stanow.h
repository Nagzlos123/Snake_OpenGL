#ifndef MASZYNA_STANOW_H_INCLUDED
#define MASZYNA_STANOW_H_INCLUDED

class StanGry
{
public:
    virtual void obsluga_klawiszy(int klawisz)=0;
    virtual void rysuje()=0;
    virtual void dzialanie()=0;

};

class MaszynaStanow
{
private:
    StanGry* biezacy_stan;
public:
    void obsluga_klawiszy(int klawisz);
    void rysuje();
    void dzialanie();
    void zmiana_stanu(StanGry*nowy_stan);

};

class MenuTryb:public StanGry
{
    void obsluga_klawiszy(int klawisz);
    void rysuje();
    void dzialanie();
};

class MenuPoziom:public StanGry
{
    void obsluga_klawiszy(int klawisz);
    void rysuje();
    void dzialanie();
};

class Gra:public StanGry
{
    void obsluga_klawiszy(int klawisz);
    void rysuje();
    void dzialanie();
};

class Koniec:public StanGry
{
    void obsluga_klawiszy(int klawisz);
    void rysuje();
    void dzialanie();
};
class Wyjscie:public StanGry
{
    void obsluga_klawiszy(int klawisz);
    void rysuje();
    void dzialanie();
};

// Klasy: MenuPoziom, Gra, Koniec, Wyjscie
// Pliki: obsluga_klawiszy.cpp, rysuje.cpp, dzialanie.cpp


#endif // MASZYNA_STANOW_H_INCLUDED
