#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <windows.h>
#include <gl/gl.h>
#include <math.h>
#include "tekstury.h"

#define WX 800
#define WY 500
#define WY1 600
#define WIELKOSC WX/20
#define GRA 0
#define GRA_KAMPANIA 1
#define MENU_TRYB 2
#define MENU_POZIOM 3
#define KONIEC 4
#define WYJSCIE 5





class zmienne_gry
{
    public:
    int poziom;

    int czas_pomiedzy_zlymi;
    int czas_pomiedzy_dobrymi;
    int czas_kolorowania ;
    int koloruj_czlony;
    int blokada_skretu;
    float ostatni_kierunek;
    int ilosc_zjedzonych_sfer_n;
    int ilosc_zjedzonych_sfer_z;
    int ilosc_zjedzonych_sfer_d;
    int punkty;
    int usuwanie;
    int liczba_czlonow;
    int zjadl_trzy_sfery;
    int cel_poziomu;
    int poziom_kampanii;
    int oczekiwanie_na_czache;
    int boss;
};

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
void EnableOpenGL(HWND hwnd, HDC*, HGLRC*);
void DisableOpenGL(HWND, HDC, HGLRC);
void rysuje_tlo (Tekstury *T);
void rysuje_menu (int poziom,Tekstury*T);
void rysuje_menu_koniec (int stan,Tekstury*T);
void rysuje_menu_tryb (int stan,Tekstury*T);
void rysuje_menu_wyjscia (int stan,Tekstury*T);
void rysuje_pasek (int poziom,Tekstury*T);
float oblicz_kierunek(float x1, float y1, float x2, float y2);
int dzieli_sie(int liczba,int dzielnik);
float reszta_niedoknca(float liczba,float dzielnik);
void rysuje_liczbe(float x, float y, float rozmiar, int liczba, Tekstury * T);

#endif // MAIN_H_INCLUDED
