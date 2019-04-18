#include <iostream>
#include "graphe.h"
#include "svgfile.h"


int main()
{
   Svgfile svgout;
    graphe g{"manhattan.txt","manhattan_poids.txt"};
    g.afficher();
    g.dessiner(svgout);
    return 0;
}

