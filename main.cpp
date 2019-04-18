#include <iostream>
#include "graphe.h"
#include "svgfile.h"


int main()
{
   Svgfile svgout;
    graphe g{"broadway.txt","broadway_poids.txt"};
    g.afficher();
    g.dessiner(svgout);
    g.kruskal();
    return 0;
}

