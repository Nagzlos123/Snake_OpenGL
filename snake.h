#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#include"main.h"

class Snake{
    public:
    float x;
    float y;
    float kierunek;
    float predkosc;
    int rodzaj;
    Snake*next;

    void rysuje (Tekstury *T);
void porusza ();
void zmien_kierunek ( float kierunek,struct zmienne_gry*G);
int sprawdz_kolizje();
void dodaje(int rodzaj);
void usuwa();
int zeruj();
int liczy_czlony();
void koloruje_usuwane(int liczba);
};

void nowa_gra(struct zmienne_gry*G,  Snake * glowa);



#endif // SNAKE_H_INCLUDED
