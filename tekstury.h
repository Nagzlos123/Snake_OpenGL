#ifndef TEKSTURY_H_INCLUDED
#define TEKSTURY_H_INCLUDED

#include <windows.h>
#include <gl/gl.h>
#include "include/png.h"

class Tekstura
{
    public:
    GLuint ID ;
    int szerokosc;
    int wysokosc;
    int alfa;
    GLubyte *obraz;

int laduj_teksture(char *name);
};

class Tekstury
{
public:
    Tekstura leb;
    Tekstura czlon;
    Tekstura ogon;
    Tekstura tlo;
    Tekstura menu_poziom;
    Tekstura poziom_latwy;
    Tekstura poziom_normalny;
    Tekstura poziom_trudny;
    Tekstura napis_latwy;
    Tekstura napis_normalny;
    Tekstura napis_trudny;
    Tekstura koniec_tak;
    Tekstura koniec_nie;
    Tekstura sfera_neutralna;
    Tekstura sfera_zla;
    Tekstura sfera_dobra;
    Tekstura czacha;
    Tekstura czlon_neutralny;
    Tekstura czlon_zly;
    Tekstura czlon_dobry;
    Tekstura pasek;
    Tekstura dodatek;
    Tekstura cyfry;
    Tekstura przycisk_nie;
    Tekstura tryb_kampani;
    Tekstura tryb_przetrfania;
    Tekstura menu_tryb;
    Tekstura wyjscie_tak;
    Tekstura wyjscie_nie;

    void laduj_tekstury();
};


#endif // TEKSTURY_H_INCLUDED
