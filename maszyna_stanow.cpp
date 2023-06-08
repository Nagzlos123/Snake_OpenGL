#include "maszyna_stanow.h"

void MaszynaStanow::obsluga_klawiszy(int klawisz)
{
    biezacy_stan->obsluga_klawiszy(klawisz);
}

void MaszynaStanow::rysuje()
{
    biezacy_stan->rysuje();
}

void MaszynaStanow::dzialanie()
{
    biezacy_stan->dzialanie();
}

