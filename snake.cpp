#include"snake.h"
#include"sfera.h"


void Snake::dodaje(int rodzaj)
{
     Snake*nowy;
     Snake*W;
    int i;
    for(i=0;i<20;i++)
    {

            nowy  =new Snake;



    nowy->kierunek = this->kierunek;
    nowy->predkosc = this->next->predkosc;

    nowy->x = this->next->x;
    nowy->y = this->next->y;

    nowy->rodzaj=rodzaj;
    nowy->next=this->next;
    this->next=nowy;

    W = nowy->next;
    while (W!=NULL)
    {
        if (W->next != NULL)
        {


        W->x = W->next->x;
        W->y = W->next->y;
        W->kierunek = W->next->kierunek;
        }
        else
        {
            W->x = W->x - cos(W->kierunek)*WIELKOSC/20;
            W->y = W->y - sin(W->kierunek)*WIELKOSC/20;
        }
        W=W->next;
    }
    }
}
void Snake::usuwa()
{
     Snake*W;
    int i;
    for(i=0;i<20;i++)
        {

        W=this->next;
        while (W->next->next!=NULL)
        {

            W=W->next;
        }
        delete(W->next);
        W->next=NULL;
}
        }

int Snake::zeruj()
{
    Snake*W = this;


    while(W!=NULL)
    {
        W->rodzaj=0;
        W = W->next;
    }
    return 0;

}
int Snake::sprawdz_kolizje()
{
    Snake*W = this;
   int licznik = 0;
    float x1,x2, y1,y2;
        x1 = reszta_niedoknca(this->x,WX);
        y1 = reszta_niedoknca(this->y,WY);


    while(W!=NULL)
    {
            x2 = reszta_niedoknca(W->x,WX);
            y2 = reszta_niedoknca(W->y,WY);
            if(dzieli_sie(licznik,20)&&licznik>=40)
            {
                if(sqrt(pow(x1-x2,2)+pow(y1-y2,2))<WIELKOSC) return 1;

             }
        licznik++;
        W = W->next;
    }
    return 0;

}

void nowa_gra(struct zmienne_gry*G,  Snake * glowa)
{
    G->cel_poziomu=2;
    G->oczekiwanie_na_czache=0;
    G->poziom_kampanii=1;
    G->czas_pomiedzy_zlymi=0;
    G->czas_pomiedzy_dobrymi=0;
    G->czas_kolorowania = 0;
   G->koloruj_czlony = 0;
    G->blokada_skretu=0;
    G->ostatni_kierunek=0;
    G->ilosc_zjedzonych_sfer_n=0;
    G->ilosc_zjedzonych_sfer_z=0;
    G->ilosc_zjedzonych_sfer_d=0;
    G->usuwanie=0;
    G->liczba_czlonow=0;
    G->zjadl_trzy_sfery=0;
    G->punkty=0;
     Snake*W=glowa;
    glowa->x = WX/2;
    glowa->y = WY/2;
    glowa->kierunek = 0;
    glowa->predkosc = G->poziom+1;
    glowa->rodzaj=0;
int i;
    for(i=0;i<20;i++)
    {


    W->next  = new Snake;
    W = W-> next;
    W->x = glowa->x - WIELKOSC*(i+1);
    W->y = glowa->y;
    W->kierunek = 0;
    W->predkosc = G->poziom+2;
    W->rodzaj=0;
    }
    W->next = NULL;


}
void Snake::koloruje_usuwane(int liczba)
{
    int liczba_czlonow=0;
    int i;
     Snake*W=this;
    for(i=0;i<(1+liczba*20);i++)
    {
      W->rodzaj=DOBRA;
    W=W->next;
    }
    //return (liczba_czlonow/20)-1;
}
int Snake::liczy_czlony()
{
    int liczba_czlonow=0;
     Snake*W=this;
    while(W!=NULL)
    {
        liczba_czlonow++;
    W=W->next;
    }
    return (liczba_czlonow/20)-1;
}
void Snake::rysuje (Tekstury *T)
{
     Snake*W = this;
    float x,y;
    int licznik = 0;
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    while(W!=NULL)
    {
        if(dzieli_sie(licznik,20))
        {

        x = reszta_niedoknca(W->x,WX);
        y = reszta_niedoknca(W->y,WY);
        glPushMatrix();

        glTranslatef(x,y,0);
        glRotatef(W->kierunek*180/M_PI,0,0,1);
        if(W==this)
        {
            glBindTexture(GL_TEXTURE_2D, T->leb.ID);
         glColor3f(1.0f,1.0f,1.0f);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f,1.0f);glVertex2i( - WIELKOSC/2, - 0.75*WIELKOSC  );
            glTexCoord2f(0.0f,0.0f);glVertex2i( - WIELKOSC/2,  0.75*WIELKOSC  );
            glTexCoord2f(1.0f,0.0f);glVertex2i(  0.75*WIELKOSC,  0.75*WIELKOSC  );
            glTexCoord2f(1.0f,1.0f);glVertex2i(  0.75*WIELKOSC, - 0.75*WIELKOSC  );

        glEnd();
       }
        else if(W->next==NULL)
        {
             glBindTexture(GL_TEXTURE_2D, T->ogon.ID);
        glColor3f(1.0f,1.0f,1.0f);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f,1.0f);glVertex2i(- 1.5*WIELKOSC,- 0.75*WIELKOSC  );
            glTexCoord2f(0.0f,0.0f);glVertex2i(- 1.5*WIELKOSC, 0.75*WIELKOSC  );
            glTexCoord2f(1.0f,0.0f);glVertex2i( WIELKOSC/2, 0.75*WIELKOSC  );
            glTexCoord2f(1.0f,1.0f);glVertex2i( WIELKOSC/2,- 0.75*WIELKOSC  );

        glEnd();

        }
        else
        {
            switch(W->rodzaj)
            {

            case 0 : glBindTexture(GL_TEXTURE_2D, T->czlon.ID);break;
            case 1 : glBindTexture(GL_TEXTURE_2D, T->czlon_neutralny.ID);break;
            case 2 : glBindTexture(GL_TEXTURE_2D, T->czlon_zly.ID);break;
            case 3 : glBindTexture(GL_TEXTURE_2D, T->czlon_dobry.ID);break;

            }

        glColor3f(1.0f,1.0f,1.0f);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f,1.0f);glVertex2i(- WIELKOSC/2,- WIELKOSC/2  );
            glTexCoord2f(0.0f,0.0f);glVertex2i(- WIELKOSC/2, WIELKOSC/2  );
            glTexCoord2f(1.0f,0.0f);glVertex2i( WIELKOSC/2, WIELKOSC/2  );
            glTexCoord2f(1.0f,1.0f);glVertex2i( WIELKOSC/2,- WIELKOSC/2  );

        glEnd();

        }

        glPopMatrix();
        }
        licznik++;
        W = W->next;
    }

    glDisable(GL_BLEND);
}
void Snake::porusza ()
{
     Snake*P=NULL;
     Snake*W = this;
    while(W!=NULL)
    {
        if(W==this)
        {


        W->x+=cos(W->kierunek)*W->predkosc;
        W->y+=sin(W->kierunek)*W->predkosc;
        }
        else
        {
            W->kierunek = oblicz_kierunek(W->x,W->y,P->x,P->y);
            W->x = P->x - cos(W->kierunek)*WIELKOSC/20;
            W->y = P->y - sin(W->kierunek)*WIELKOSC/20;
        }
        P=W;
        W = W->next;
    }

}

void Snake::zmien_kierunek ( float kierunek,struct zmienne_gry*G)
{

    if(fabs(this->kierunek-kierunek) - M_PI < 0.01 &&
       fabs(this->kierunek-kierunek) - M_PI > -0.01) return;

    G->ostatni_kierunek = kierunek;
    if(G->blokada_skretu==0)
    {
        G->blokada_skretu=WIELKOSC/this->predkosc+1;
    }
    else
    {
        return;
    }


   // else
    this->kierunek = kierunek;


}



