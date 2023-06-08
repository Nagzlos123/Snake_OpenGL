#include "maszyna_stanow.h"

void MenuTryb::obsluga_klawiszy(int klawisz)
{
   switch(klawisz)
   {
                    case VK_ESCAPE:
                        poprzedni_stan=stan_gry;
                        stan_gry= WYJSCIE;
                    break;
                    case VK_UP:
                        if(stan_menu_tryb<3)
                            stan_menu_tryb++;

                        break;
                    case VK_DOWN:
                        if(stan_menu_tryb>1)
                            stan_menu_tryb--;

                        break;
                    case VK_RETURN:
                    case VK_SPACE:
                        if(stan_menu_tryb==1)
                        {
                             poprzedni_stan=stan_gry;
                            stan_gry= WYJSCIE;
                        }

                            else
                        stan_gry=MENU_POZIOM;
                        break;
   }
}
void MenuPoziom::obsluga_klawiszy(int klawisz)
{
    switch(klawisz)
    {
                        case VK_ESCAPE:
                            poprzedni_stan=stan_gry;
                                stan_gry= WYJSCIE;
                            break;
                        case VK_RIGHT:
                            if(G.poziom<3)
                                G.poziom++;

                            break;
                        case VK_LEFT:
                            if(G.poziom>1)
                                G.poziom--;

                            break;
                        case VK_RETURN:
                        case VK_SPACE:

                        nowa_gra(&G, glowa);
                            stan_gry= GRA;
                            S=new Sfera;
                           S->generuje(NEUTRALNA);
                           if(Z)
                           {
                               delete(Z);
                                Z=NULL;
                           }
                             if(D)
                           {
                               delete(D);
                                D=NULL;
                           }
                            break;
    }
}

void Gra::obsluga_klawiszy(int klawisz)
{
    switch(klawisz)
    {
                    case VK_ESCAPE:
                        poprzedni_stan=stan_gry;
                        stan_gry= WYJSCIE;
                    break;
                    case VK_UP:
                    case 'W':
                        glowa->zmien_kierunek(M_PI_2,&G);
                        break;
                    case VK_DOWN:
                    case 'S':
                        glowa->zmien_kierunek(3*M_PI_2,&G);
                        break;
                    case VK_RIGHT:
                    case 'D':
                        glowa->zmien_kierunek(0,&G);
                        break;
                    case VK_LEFT:
                    case 'A':
                        glowa->zmien_kierunek(M_PI,&G);
                        break;

    }
}

void Koniec::obsluga_klawiszy(int klawisz)
{
    switch(klawisz)
    {
                    case VK_RIGHT:
                        if(stan_menu_koncowego==1)
                            stan_menu_koncowego=2;

                        break;
                    case VK_LEFT:
                        if(stan_menu_koncowego==2)
                            stan_menu_koncowego=1;

                        break;
                    case VK_SPACE:
                    case VK_RETURN:
                        if(stan_menu_koncowego==1)
                            stan_gry= MENU_POZIOM;
                        else

                           stan_gry= WYJSCIE;

                        break;

    }
}

void Wyjscie::obsluga_klawiszy(int klawisz)
{
    switch(klawisz)
    {
                    case VK_RIGHT:
                        if(stan_menu_wyjscia==1)
                            stan_menu_wyjscia=2;

                        break;
                    case VK_LEFT:
                        if(stan_menu_wyjscia==2)
                            stan_menu_wyjscia=1;

                        break;
                    case VK_SPACE:
                    case VK_RETURN:
                        if(stan_menu_wyjscia==1)
                            PostQuitMessage(0);

                        else
                            if(stan_gry)

                           stan_gry= poprzedni_stan;

                        break;
    }
}
