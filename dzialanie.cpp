#include "maszyna_stanow.h"


void MenuTryb::dzialanie()
{
    rysuje_menu_tryb(stan_menu_tryb,&T);
    glLoadIdentity();
}

void MenuPoziom::dzialanie()
{
    rysuje_menu(G.poziom,&T);
    glLoadIdentity();
}

void Gra::dzialanie()
{
                G.punkty = G.ilosc_zjedzonych_sfer_n + G.ilosc_zjedzonych_sfer_z*5;
                rysuje_tlo(&T);
               if(S) S->rysuje_sfere(&T);
              if(Z) Z->rysuje_sfere(&T);
              if(D) D->rysuje_sfere(&T);
                glowa->rysuje(&T);
                rysuje_pasek(G.poziom,&T);
                if (timer % 50 == 0) G.liczba_czlonow = glowa->liczy_czlony();
                rysuje_liczbe(203,541,0.15,G.liczba_czlonow,&T);
                rysuje_liczbe(354,514,0.12,G.ilosc_zjedzonych_sfer_n,&T);
                rysuje_liczbe(495,515,0.12,G.ilosc_zjedzonych_sfer_z,&T);
                rysuje_liczbe(653,516,0.12,G.ilosc_zjedzonych_sfer_d,&T);
                rysuje_liczbe(342,560,0.12,G.punkty,&T);
                if (stan_menu_tryb == 3)
                {
                    if(G.ilosc_zjedzonych_sfer_z==G.cel_poziomu&&G.oczekiwanie_na_czache==0)
                    {
                        G.oczekiwanie_na_czache=1;
                        delete(S);
                        S=NULL;
                        delete(D);
                        D=NULL;
                        delete(Z);
                        Z=NULL;
                        G.czas_pomiedzy_zlymi=0;
                        G.czas_pomiedzy_dobrymi=0;
                        C=new Sfera;
                        C->generuje(CZACHA);




                    }
                    if(G.ilosc_zjedzonych_sfer_z!=G.cel_poziomu)
                        rysuje_liczbe(750,10,0.36,G.cel_poziomu-G.ilosc_zjedzonych_sfer_z,&T);

                    if(C) C->rysuje_sfere(&T);
                }


                glowa->porusza();

                if(glowa->sprawdz_kolizje()==1)
                    stan_gry= KONIEC;
                if(S)if(S->sprawdz_kolizje_sfery(glowa)==1)
                {
                     PlaySound("muzyka/zbieranie.wav", NULL, SND_FILENAME | SND_ASYNC | SND_NOSTOP  );
                    S->generuje(NEUTRALNA);
                    glowa->dodaje(NEUTRALNA);
                    G.czas_kolorowania=100;
                    G.koloruj_czlony=1;
                    G.ilosc_zjedzonych_sfer_n++;
                }
                if (G.koloruj_czlony>0)
                {

                    if(G.czas_kolorowania>0)
                        G.czas_kolorowania--;
                    else
                    {
                        glowa->zeruj();
                        G.koloruj_czlony=0;
                        if(G.usuwanie>0)
                        {
                            for(i=0;i<G.usuwanie;i++)
                            glowa->usuwa();
                            G.usuwanie=0;
                        }
                    }
                }
                if(G.blokada_skretu>0)
                {
                    G.blokada_skretu--;
                    if (G.blokada_skretu==0) glowa->kierunek=G.ostatni_kierunek;
                }
                if(G.ilosc_zjedzonych_sfer_n==3 && G.zjadl_trzy_sfery == FALSE)
                {
                    G.czas_pomiedzy_zlymi = rand()%600+1;
                    G.czas_pomiedzy_dobrymi = rand()%600+1;
                    G.zjadl_trzy_sfery = TRUE;
                }
                if(G.czas_pomiedzy_zlymi>0)
                {
                    G.czas_pomiedzy_zlymi--;
                    if(G.czas_pomiedzy_zlymi==0)
                    {
                        Z=new Sfera;
                         Z->generuje(ZLA);
                    }

                }
                if(G.czas_pomiedzy_dobrymi>0)
                {
                    G.czas_pomiedzy_dobrymi--;
                    if(G.czas_pomiedzy_dobrymi==0)
                    {
                        D=new Sfera;
                         D->generuje(DOBRA);
                    }

                }
                if(Z)
                 if(Z->sprawdz_kolizje_sfery(glowa)==1)
                {
                    delete(Z);
                    Z=NULL;
                    G.ilosc_zjedzonych_sfer_z++;
                    G.czas_pomiedzy_zlymi= rand()%600+1;
                    for(i=0;i<rand()%5+2;i++)
                        glowa->dodaje(ZLA);
                    G.czas_kolorowania=100;
                    G.koloruj_czlony=2;
                }

                  if(D)
                 if(D->sprawdz_kolizje_sfery(glowa)==1)
                {
                    delete(D);
                    D=NULL;
                    G.ilosc_zjedzonych_sfer_d++;
                    G.czas_pomiedzy_dobrymi= rand()%600+1;
                    G.usuwanie=rand()%5+2;
                    if(G.usuwanie>glowa->liczy_czlony())
                        G.usuwanie=glowa->liczy_czlony();
                    glowa->koloruje_usuwane(G.usuwanie);
                    G.czas_kolorowania= 50;
                    G.koloruj_czlony=3;




                }
}

void Koniec::dzialanie()
{
    rysuje_tlo(&T);
    glowa->rysuje(&T);
    rysuje_menu_koniec(stan_menu_koncowego,&T);
    rysuje_pasek(G.poziom,&T);
    rysuje_liczbe(203,541,0.15,G.liczba_czlonow,&T);
    rysuje_liczbe(354,514,0.12,G.ilosc_zjedzonych_sfer_n,&T);
    rysuje_liczbe(495,515,0.12,G.ilosc_zjedzonych_sfer_z,&T);
    rysuje_liczbe(653,516,0.12,G.ilosc_zjedzonych_sfer_d,&T);
    rysuje_liczbe(342,560,0.12,G.punkty,&T);

}

void Wyjscie::dzialanie()
{
    rysuje_menu_wyjscia(stan_menu_wyjscia,&T);
}
