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
        ///constructeur qui charge le graphe en memoire
        //format du fichier ordre/liste des sommets/taille/liste des arêtes
        graphe(std::string,std::string);
        ~graphe();
        std::vector<std::vector<bool>> rendrebinaire();
        void afficher() const;
        void kruskal(Svgfile &svgout) const;
        void filtre1();
        void filtre2();
        void dessiner(Svgfile &svgout) ;



    protected:

    private:
        /// Le réseau est constitué d'une collection de sommets
        std::unordered_map<int,Sommet*> m_sommets;///stockee dans une map (cle=id du sommet, valeur= pointeur sur le sommet)
        std::unordered_map<int,Aretes*> m_aretes;
        //std::vector<int> v1;

        int *cc;



};

#endif // GRAPHE_H
