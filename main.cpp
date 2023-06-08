#include "main.h"
#include "tekstury.h"
#include "sfera.h"
#include "snake.h"
#include <time.h>


void rysuje_liczbe(float x, float y, float rozmiar, int liczba,  Tekstury * T)
{
    int i,cyfra;


    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBindTexture(GL_TEXTURE_2D, T->cyfry.ID);
    glPushMatrix();
    glTranslatef(x,y,0);
    i = 0;

    if (liczba == 0)
    {
        glPushMatrix();
        glScalef(rozmiar, rozmiar, rozmiar);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);glVertex2i(0,0);
            glTexCoord2f(0.0f,1.0f);glVertex2i(0,120);
            glTexCoord2f(0.1f,1.0f);glVertex2i(100,120);
            glTexCoord2f(0.1f,0.0f);glVertex2i(100,0);

        glEnd();
        glPopMatrix();
    }
    else
    while (liczba > 0)
    {
        cyfra = liczba % 10;
        liczba = liczba / 10;
        glPushMatrix();
        glScalef(rozmiar, rozmiar, rozmiar);
        glTranslatef(-i*100,0,0);
        glBegin(GL_QUADS);
            glTexCoord2f(0.1f*cyfra,0.0f);glVertex2i(0,0);
            glTexCoord2f(0.1f*cyfra,1.0f);glVertex2i(0,120);
            glTexCoord2f(0.1f*cyfra+0.1f,1.0f);glVertex2i(100,120);
            glTexCoord2f(0.1f*cyfra+0.1f,0.0f);glVertex2i(100,0);

        glEnd();
        glPopMatrix();
        i++;
    }
    glPopMatrix();
    glDisable(GL_BLEND);
}


int dzieli_sie(int liczba,int dzielnik)
{
    int x = liczba;
    while(x>0)
    {
        x-= dzielnik;
    }
    if(x==0) return 1;
    else return 0;
}

float reszta_niedoknca(float liczba,float dzielnik)
{
    float x = liczba;

    if(x>0)
    {
        while(x>0)
        {
            x-= dzielnik;
        }
        return x+dzielnik;
    }
    else
    {
        while(x<0)
        {
            x+= dzielnik;
        }
        return x;
    }

}
float oblicz_kierunek(float x1, float y1, float x2, float y2) // funkcja oblicza kierunek do podanego punktu
{
     float wynik;
     float X = x2 - x1;
     float Y = y2 - y1;
	 if ( X == 0 && Y == 0) return 0;

     if (fabs(Y) > fabs(X))
     {
        wynik = fabs(Y)/Y * M_PI_2 - atan(X/Y);

     }
     else
     {
        wynik = M_PI_2 - M_PI_2 * fabs(X)/X + atan(Y/X);
     }
     if (wynik < 0) wynik += 2*M_PI;
     return wynik;
}
void rysuje_tlo ( Tekstury*T)
{
    glBindTexture(GL_TEXTURE_2D, T->tlo.ID);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);glVertex2i(0,0);
            glTexCoord2f(0.0f,1.0f);glVertex2i(0,WY);
            glTexCoord2f(1.0f,1.0f);glVertex2i(WX,WY);
            glTexCoord2f(1.0f,0.0f);glVertex2i(WX,0);

        glEnd();

}
void rysuje_pasek (int poziom, Tekstury*T)
{
    glBindTexture(GL_TEXTURE_2D, T->pasek.ID);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);glVertex2i(WX*0.15,WY);
            glTexCoord2f(0.0f,1.0f);glVertex2i(WX*0.15,WY1);
            glTexCoord2f(1.0f,1.0f);glVertex2i(WX*0.85,WY1);
            glTexCoord2f(1.0f,0.0f);glVertex2i(WX*0.85,WY);

        glEnd();
    glBindTexture(GL_TEXTURE_2D, T->dodatek.ID);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);glVertex2i(WX*0.0,WY);
            glTexCoord2f(0.0f,1.0f);glVertex2i(WX*0.0,WY1);
            glTexCoord2f(1.0f,1.0f);glVertex2i(WX*0.15,WY1);
            glTexCoord2f(1.0f,0.0f);glVertex2i(WX*0.15,WY);

        glEnd();
    glBindTexture(GL_TEXTURE_2D, T->dodatek.ID);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);glVertex2i(WX*1.0,WY);
            glTexCoord2f(0.0f,1.0f);glVertex2i(WX*1.0,WY1);
            glTexCoord2f(1.0f,1.0f);glVertex2i(WX*0.85,WY1);
            glTexCoord2f(1.0f,0.0f);glVertex2i(WX*0.85,WY);

        glEnd();


            glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

            switch(poziom)
    {
    case 1 : glBindTexture(GL_TEXTURE_2D, T->napis_latwy.ID);

glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);glVertex2i(570,550);
            glTexCoord2f(0.0f,1.0f);glVertex2i(570, 570);
            glTexCoord2f(1.0f,1.0f);glVertex2i(622,570);
            glTexCoord2f(1.0f,0.0f);glVertex2i(622,550);

        glEnd();
    break;
        case 2 : glBindTexture(GL_TEXTURE_2D, T->napis_normalny.ID);
glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);glVertex2i(570,550);
            glTexCoord2f(0.0f,1.0f);glVertex2i(570, 570);
            glTexCoord2f(1.0f,1.0f);glVertex2i(630,570);
            glTexCoord2f(1.0f,0.0f);glVertex2i(630,550);
        glEnd();
        break;
        case 3 : glBindTexture(GL_TEXTURE_2D, T->napis_trudny.ID);
glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);glVertex2i(570,550);
            glTexCoord2f(0.0f,1.0f);glVertex2i(570, 570);
            glTexCoord2f(1.0f,1.0f);glVertex2i(622,570);
            glTexCoord2f(1.0f,0.0f);glVertex2i(622,550);
        glEnd();
        break;
    }



        glDisable(GL_BLEND);
}
void rysuje_menu_tryb (int stan, Tekstury*T)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

     glBindTexture(GL_TEXTURE_2D, T->menu_tryb.ID);
    glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);glVertex2i(WX*0.2,WY1*0.2);
            glTexCoord2f(0.0f,1.0f);glVertex2i(WX*0.2,WY1*0.8);
            glTexCoord2f(1.0f,1.0f);glVertex2i(WX*0.8,WY1*0.8);
            glTexCoord2f(1.0f,0.0f);glVertex2i(WX*0.8,WY1*0.2);

        glEnd();
    switch(stan)
    {
    case 1 : glBindTexture(GL_TEXTURE_2D, T->przycisk_nie.ID);
    glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);glVertex2i(WX*0.448,WY1*0.247);
            glTexCoord2f(0.0f,1.0f);glVertex2i(WX*0.448,WY1*0.356);
            glTexCoord2f(1.0f,1.0f);glVertex2i(WX*0.580,WY1*0.356);
            glTexCoord2f(1.0f,0.0f);glVertex2i(WX*0.580,WY1*0.237);

        glEnd();

    break;
        case 2 : glBindTexture(GL_TEXTURE_2D, T->tryb_przetrfania.ID);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);glVertex2i(WX*0.282,WY1*0.373);
            glTexCoord2f(0.0f,1.0f);glVertex2i(WX*0.282,WY1*0.480);
            glTexCoord2f(1.0f,1.0f);glVertex2i(WX*0.722,WY1*0.480);
            glTexCoord2f(1.0f,0.0f);glVertex2i(WX*0.722,WY1*0.373);

        glEnd();
        break;
        case 3 : glBindTexture(GL_TEXTURE_2D, T->tryb_kampani.ID);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);glVertex2i(WX*0.282,WY1*0.509);
            glTexCoord2f(0.0f,1.0f);glVertex2i(WX*0.282,WY1*0.616);
            glTexCoord2f(1.0f,1.0f);glVertex2i(WX*0.722,WY1*0.616);
            glTexCoord2f(1.0f,0.0f);glVertex2i(WX*0.722,WY1*0.509);
        glEnd();
        break;
    }


glDisable(GL_BLEND);
}




void rysuje_menu (int poziom, Tekstury*T)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

     glBindTexture(GL_TEXTURE_2D, T->menu_poziom.ID);
    glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);glVertex2i(WX*0.1,WY1*0.2);
            glTexCoord2f(0.0f,1.0f);glVertex2i(WX*0.1,WY1*0.8);
            glTexCoord2f(1.0f,1.0f);glVertex2i(WX*0.9,WY1*0.8);
            glTexCoord2f(1.0f,0.0f);glVertex2i(WX*0.9,WY1*0.2);

        glEnd();
    switch(poziom)
    {
    case 1 : glBindTexture(GL_TEXTURE_2D, T->poziom_latwy.ID);
    glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);glVertex2i(WX*0.159,WY1*0.362);
            glTexCoord2f(0.0f,1.0f);glVertex2i(WX*0.159,WY1*0.492);
            glTexCoord2f(1.0f,1.0f);glVertex2i(WX*0.379,WY1*0.492);
            glTexCoord2f(1.0f,0.0f);glVertex2i(WX*0.379,WY1*0.362);

        glEnd();

    break;
        case 2 : glBindTexture(GL_TEXTURE_2D, T->poziom_normalny.ID);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);glVertex2i(WX*0.402,WY1*0.363);
            glTexCoord2f(0.0f,1.0f);glVertex2i(WX*0.402,WY1*0.493);
            glTexCoord2f(1.0f,1.0f);glVertex2i(WX*0.622,WY1*0.493);
            glTexCoord2f(1.0f,0.0f);glVertex2i(WX*0.622,WY1*0.363);

        glEnd();
        break;
        case 3 : glBindTexture(GL_TEXTURE_2D, T->poziom_trudny.ID);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);glVertex2i(WX*0.650,WY1*0.362);
            glTexCoord2f(0.0f,1.0f);glVertex2i(WX*0.650,WY1*0.492);
            glTexCoord2f(1.0f,1.0f);glVertex2i(WX*0.870,WY1*0.492);
            glTexCoord2f(1.0f,0.0f);glVertex2i(WX*0.870,WY1*0.362);

        glEnd();
        break;
    }


glDisable(GL_BLEND);
}

void rysuje_menu_koniec (int stan, Tekstury*T)
{
    switch(stan)
    {
    case 1 : glBindTexture(GL_TEXTURE_2D, T->koniec_tak.ID);break;
        case 2 : glBindTexture(GL_TEXTURE_2D, T->koniec_nie.ID);break;


    }
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);glVertex2i(WX*0.3,WY*0.2);
            glTexCoord2f(1.0f,0.0f);glVertex2i(WX*0.7,WY*0.2);
            glTexCoord2f(1.0f,1.0f);glVertex2i(WX*0.7,WY*0.8);
            glTexCoord2f(0.0f,1.0f);glVertex2i(WX*0.3,WY*0.8);

        glEnd();
        glDisable(GL_BLEND);
}
void rysuje_menu_wyjscia (int stan, Tekstury*T)
{
    switch(stan)
    {
    case 1 : glBindTexture(GL_TEXTURE_2D, T->wyjscie_tak.ID);break;
        case 2 : glBindTexture(GL_TEXTURE_2D, T->wyjscie_nie.ID);break;


    }
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);glVertex2i(WX*0.2,WY*0.2);
            glTexCoord2f(1.0f,0.0f);glVertex2i(WX*0.8,WY*0.2);
            glTexCoord2f(1.0f,1.0f);glVertex2i(WX*0.8,WY*0.8);
            glTexCoord2f(0.0f,1.0f);glVertex2i(WX*0.2,WY*0.8);

        glEnd();
        glDisable(GL_BLEND);
}
int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    WNDCLASSEX wcex;
    HWND hwnd;
    HDC hDC;
    HGLRC hRC;
    MSG msg;
    BOOL bQuit = FALSE;
     Tekstury T;
    Sfera *S=NULL ;
    Sfera *Z=NULL;
    Sfera *D=NULL ;
    Sfera *C=NULL ;
    int stan_gry = MENU_TRYB;
    int poprzedni_stan= 0;
    int stan_menu_koncowego = 1;
    int stan_menu_wyjscia = 1;
    int stan_menu_tryb = 2;
    struct zmienne_gry G;
     Snake*glowa = NULL;
    int i=0;
    int fullscreen = 0;
    int timer = 0;

srand(time(0));

    /* register window class */
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_OWNDC;
    wcex.lpfnWndProc = WindowProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = "GLSample";
    wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);;


    if (!RegisterClassEx(&wcex))
        return 0;

    /* create main window */
    hwnd = CreateWindowEx(0,
                          "GLSample",
                          "OpenGL Sample",
                          WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          WX,
                          625,
                          NULL,
                          NULL,
                          hInstance,
                          NULL);

    ShowWindow(hwnd, nCmdShow);
    ShowCursor(FALSE);
    /* enable OpenGL for the window */
    EnableOpenGL(hwnd, &hDC, &hRC);

    T.laduj_tekstury();

   glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);

    glowa = new Snake;
  G.poziom= 2;
  nowa_gra(&G, glowa);


    PlaySound("muzyka/Platformer2.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NOSTOP );


    /* program main loop */
    while (!bQuit)
    {
        /* check for messages */
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
        if (msg.message== WM_KEYDOWN)
        {
            if (msg.wParam == VK_F1)
            {
                fullscreen = 1 - fullscreen;
                if (fullscreen)
                    SendMessage(hwnd, WM_SYSCOMMAND, SC_MAXIMIZE, 0);
                else
                    SendMessage(hwnd, WM_SYSCOMMAND, SC_RESTORE, 0);
            }

            switch(stan_gry)
            {
                 case MENU_TRYB:
                switch (msg.wParam)
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
                break;
            case MENU_POZIOM:
                switch (msg.wParam)
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
                 break;
            case GRA:
                switch (msg.wParam)
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
                break;
              /*  case GRA_KAMPANIA:
                switch (msg.wParam)
                {
                    case VK_ESCAPE:
                        poprzedni_stan=stan_gry;
                        stan_gry= WYJSCIE;
                    break;
                    case VK_UP:
                    case 'W':
                        zmien_kierunek(glowa,M_PI_2,&G);
                        break;
                    case VK_DOWN:
                    case 'S':
                        zmien_kierunek(glowa,3*M_PI_2,&G);
                        break;
                    case VK_RIGHT:
                    case 'D':
                        zmien_kierunek(glowa,0,&G);
                        break;
                    case VK_LEFT:
                    case 'A':
                        zmien_kierunek(glowa,M_PI,&G);
                        break;
                }
                break;*/
            case KONIEC:
                switch (msg.wParam)
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
                break;
                  case WYJSCIE:
                switch (msg.wParam)
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
                break;
           }

        }
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            /* OpenGL animation code goes here */

            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glPushMatrix();

            switch(stan_gry)
            {
            case MENU_TRYB:
        rysuje_menu_tryb(stan_menu_tryb,&T);
        glLoadIdentity();
                break;
            case MENU_POZIOM:
        rysuje_menu(G.poziom,&T);
        glLoadIdentity();
                break;
            case GRA:
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

                break;
            case KONIEC:

                rysuje_tlo(&T);
                glowa->rysuje(&T);
                rysuje_menu_koniec(stan_menu_koncowego,&T);
                rysuje_pasek(G.poziom,&T);
                rysuje_liczbe(203,541,0.15,G.liczba_czlonow,&T);
                rysuje_liczbe(354,514,0.12,G.ilosc_zjedzonych_sfer_n,&T);
                rysuje_liczbe(495,515,0.12,G.ilosc_zjedzonych_sfer_z,&T);
                rysuje_liczbe(653,516,0.12,G.ilosc_zjedzonych_sfer_d,&T);
                rysuje_liczbe(342,560,0.12,G.punkty,&T);

                break;
            case WYJSCIE:
                rysuje_menu_wyjscia(stan_menu_wyjscia,&T);
                break;

            }



            glPopMatrix();

            SwapBuffers(hDC);

            Sleep (10);
            timer++;
        }
    }

    /* shutdown OpenGL */
    DisableOpenGL(hwnd, hDC, hRC);

    /* destroy the window explicitly */
    DestroyWindow(hwnd);

    return msg.wParam;
}

    LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    int height, width;
    switch (uMsg)
    {
        case WM_CLOSE:
            PostQuitMessage(0);

        case WM_SIZE:
            height=HIWORD(lParam);
            width=LOWORD(lParam);
            glViewport((width-height*4.0/3.0)/2,0,height*4.0/3.0,height);

        break;

        case WM_DESTROY:
            return 0;


        break;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}

void EnableOpenGL(HWND hwnd, HDC* hDC, HGLRC* hRC)
{
    PIXELFORMATDESCRIPTOR pfd;

    int iFormat;

    /* get the device context (DC) */
    *hDC = GetDC(hwnd);

    /* set the pixel format for the DC */
    ZeroMemory(&pfd, sizeof(pfd));

    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW |
                  PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    iFormat = ChoosePixelFormat(*hDC, &pfd);

    SetPixelFormat(*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext(*hDC);

    wglMakeCurrent(*hDC, *hRC);

    glMatrixMode(GL_PROJECTION);			// wybiera macierz rzutowania
	glLoadIdentity();					// resetuje macierz rzutowania

	// wyznacza proporcje obrazu
    glOrtho(0,WX,0,WY1,1,-1);

    glMatrixMode(GL_MODELVIEW);				// wybiera macierz modelowania
	glLoadIdentity();						// resetuje macierz modelowania

	glEnable(GL_COLOR_MATERIAL);
	/*glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);*/
}

void DisableOpenGL (HWND hwnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hRC);
    ReleaseDC(hwnd, hDC);
}

