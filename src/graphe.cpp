#include <fstream>
#include <iostream>
#include "graphe.h"
#include "aretes.h"
#include "svgfile.h"

using namespace std;

graphe::graphe(std::string nomFichier1,std::string nomFichier2)
{
    std::ifstream ifs{nomFichier1};
    std::ifstream fs2{nomFichier2};
    int ordre;
    ifs >> ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    std::string id;
    double x,y;
    //lecture des sommets
    for (int i=0; i<ordre; ++i)
    {
        ifs>>id;
        ifs>>x;
        ifs>>y;
        m_sommets.insert({id,new Sommet{id,x,y}});
    }
    int taille;
    ifs >> taille;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");
    std::string id_voisin;
    //lecture des aretes
    std::string ida;
    std::string S1;
    std::string S2;
    float poids1;
    float poids2;
    double taille1;
    double nbpoids;
    fs2>>taille1;
    std::cout<<taille1;
    fs2>>nbpoids;
    std::cout<<nbpoids<<std::endl;

    for (int i=0; i<taille; ++i)
    {
        ifs>>ida;
        ifs>>S1;
        ifs>>S2;
        fs2>>ida;
        fs2>>poids1;
        fs2>>poids2;
        m_aretes.insert({ida,new Aretes{ida,S1,S2,poids1,poids2}});

    }

}

void graphe::afficher() const
{
    std::cout<<"  ordre : " << m_sommets.size()<<std::endl;
    for(auto s : m_sommets)
    {
        s.second->afficherData();
///        s.second->afficherVoisins();
        std::cout << std::endl;
    };

    std::cout<<"  taille : " << m_aretes.size()<<std::endl;
    for(auto s : m_aretes)
    {
        std::cout << "  aretes :  ";
        s.second->afficherData();
        std::cout << std::endl;
    };

}
void graphe::dessiner(Svgfile &svgout)
{
    //svgout.addGrid();
    for (auto it: m_sommets)
    {

        svgout.addDisk(it.second->getx(),it.second->gety(),9,"blue");

    }
    for (auto a: m_aretes)
    {
        std::string b=a.second->getS1();
        Sommet* b2=m_sommets.at(b);

        std::string c=a.second->getS2();
        Sommet* c2=m_sommets.at(c);
        svgout.addLine(b2->getx(),b2->gety(),c2->getx(),c2->gety(),"blue");
    }

}
/*
void graphe::bruteforce() const
{int ordre;
for (int i=0;i< ordre;i++;)
v1.pushback
{if (ordre!=ordre-1)

};
}*/

void graphe::attribuerbinaire()
{
    for (auto b: m_aretes)
        v1.push_back(b.second->getida());
    int taille1=v1.size();
}

graphe::~graphe()
{
}
