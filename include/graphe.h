#ifndef GRAPHE_H
#define GRAPHE_H
#include <string>
#include <unordered_map>
#include <vector>
#include "sommet.h"
#include "aretes.h"
#include "svgfile.h"

class graphe
{
    public:
        ///constructeur qui charge le graphe en m�moire
        //format du fichier ordre/liste des sommets/taille/liste des ar�tes
        graphe(std::string,std::string);
        ~graphe();
        void afficher() const;
        void kruskal() const;
        int trouver_sommet(int);
        //void bruteforce() const;
        void dessiner(Svgfile &svgout) ;
        void attribuerbinaire();



    protected:

    private:
        /// Le r�seau est constitu� d'une collection de sommets
        std::unordered_map<int,Sommet*> m_sommets;//stock�e dans une map (cl�=id du sommet, valeur= pointeur sur le sommet)
        std::unordered_map<int,Aretes*> m_aretes;
        std::vector<int> v1;

        int *cc;
        //std::vector<vector<int>> v2;



};

#endif // GRAPHE_H
