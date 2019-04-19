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
        ///constructeur qui charge le graphe en mémoire
        //format du fichier ordre/liste des sommets/taille/liste des arêtes
        graphe(std::string,std::string);
        ~graphe();
        void afficher() const;
        void kruskal(Svgfile &svgout) const;
        //std::vector<Aretes*> bruteforce(std::vector<Aretes*>);
        void dessiner(Svgfile &svgout) ;
        //int getidg();



    protected:

    private:
        /// Le réseau est constitué d'une collection de sommets
        std::unordered_map<int,Sommet*> m_sommets;//stockée dans une map (clé=id du sommet, valeur= pointeur sur le sommet)
        std::unordered_map<int,Aretes*> m_aretes;

        //std::vector<int> v1;

        int *cc;
        //int idg;


};

#endif // GRAPHE_H
