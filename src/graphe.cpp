#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
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
    int id;
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
    //lecture des aretes
    int ida;
    int S1;
    int S2;
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
//       s.second->afficherVoisins();
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
        int b=a.second->getS1();
        Sommet* b2=m_sommets.at(b);

        int c=a.second->getS2();
        Sommet* c2=m_sommets.at(c);
        svgout.addLine(b2->getx(),b2->gety(),c2->getx(),c2->gety(),"blue");
    }


}


void graphe::kruskal(Svgfile &svgout) const
{
    std::vector<Aretes*> T;
    std::vector<Aretes*> m_a;
    for(auto s: m_aretes)
    {
        m_a.push_back(s.second);
    }
    std::sort(m_a.begin(),m_a.end(), [](Aretes* a1, Aretes* a2)
    {
        return (a1->getpoids1() < a2->getpoids1());
    }
             );

    std::cout<<" taille " <<m_aretes.size()<<std::endl;
    for(auto s : m_a)
    {
        s->afficherData();

        std::cout<< std::endl;
    };

    int ordre=m_sommets.size();
    int i=0;
    for(auto element:m_sommets)
    {
        element.second->putCC(i);
        i++;
    }

    int cptaretes=0,j=0;

    do
    {
        int cc1,cc2;
        ///attribuer � chaque sommet un num�ro de composante connexe
        cc1 = (m_sommets.find(m_a[j]->getS1()))->second->getCC();
        cc2 = (m_sommets.find(m_a[j]->getS2()))->second->getCC();

        if (cc1 != cc2)
        {
            std::cout<<m_a[j]->getida()<<std::endl;
            T.push_back(m_a[j]); ///on ajoute la donn�e � l'arbre
            ///cc[cc2];///tableau de connexit�
            (m_sommets.find(m_a[j]->getS2()))->second->putCC(cc1);
            cptaretes++;
            for(auto element:m_sommets)
            {
                if(element.second->getCC()==cc2)
                    element.second->putCC(cc1);
            }

        }
        j++;
    }
    while(cptaretes<ordre-1);
    int sx1, sx2, sy1, sy2, x_max = 0;
    for(auto& a:T)
    {
        if(m_sommets.find(a->getS1())->second->getx() > x_max)
            x_max = m_sommets.find(a->getS1())->second->getx();
        if(m_sommets.find(a->getS2())->second->getx() > x_max)
            x_max = m_sommets.find(a->getS2())->second->getx();
    }
    x_max *= 2;
    for(auto& a:T)
    {
        sx1 = m_sommets.find(a->getS1())->second->getx();
        sy1 = m_sommets.find(a->getS1())->second->gety();
        sx2 = m_sommets.find(a->getS2())->second->getx();
        sy2 = m_sommets.find(a->getS2())->second->gety();

        //svgout.addLine(x_max + sx1,sy1,x_max + sx2,sy2,"red");
        svgout.addLine(sx1,sy1,sx2,sy2,"red");
        //svgout.addText(x_max+ 0.5*(sx1+sx2),0.5*(sy1+sy2),std::to_string(a->getpoids1()),"black");
    }
}

/*
std::vector<Aretes*> graphe_in;
 std::vector<Aretes*> graphe::bruteforce(std::vector<Aretes*> graphe_in)
{ std::vector<Aretes*> resultat;
for (auto g:graphe_in){
    std::vector<int> v_sommetnonconnexe;
    std::vector<int> v_sommetconnexe;
     for (auto a:m_aretes)
    {
    // v_sommetconnexe.push_back(a.second->getS1());
     v_sommetconnexe.push_back(a.second->getS2());
    }
       do
    {
            int cc1,cc2;
            ///attribuer � chaque sommet un num�ro de composante connexe
            cc1 = (m_sommets.find(m_aretes->getS1()))->second->getCC();
            cc2 = (m_sommets.find(m_aretes->getS2()))->second->getCC();

            if (cc1 != cc2)
            {
                std::cout<<m_aretes->getida()<<std::endl;
                v_sommetconnexe.push_back(m_aretes); ///on ajoute la donn�e � l'arbre
                ///cc[cc2];///tableau de connexit�
                (m_sommets.find(m_aretes->getS2()))->second->putCC(cc1);
                cptaretes++;
                for(auto element:m_sommets)
                {
                    if(element.second->getCC()==cc2)
                        element.second->putCC(cc1);
                }

        }
        j++;
    }while(cptaretes<ordre-1);
    for (auto b:m_sommets)
    { bool contenu = false;
         for(int i=0; i<v_sommetconnexe.size(); ++i)
        if (v_sommetconnexe[i] == b.second->getid())
        contenu = true;
    if(!contenu)
        v_sommetnonconnexe.push_back(b);
    }
    if(v_sommetnonconnexe.size()==0)
        {
            int ordre=m_sommets.size();
    if(m_aretes.size()== m_sommets.size()-1)
    {
     resultat.push_back(g);
    }
        }
return resultat;
}
int ordre;
for (int i=0;i< ordre;i++;)
v1.pushback
{if (ordre!=ordre-1)

};
}

*/
std::vector<std::vector<bool>> graphe::rendrebinaire()
{

    std::vector<std::vector<bool>>tab(pow(2,m_aretes.size()));
    int pb;
    int c;
    for(pb=0; pb<m_aretes.size(); pb++)
    {
        for(c=0; c<pow(2,m_aretes.size()); c++)
        {
            tab[c].push_back((c>>pb)&1);
        }
    }
    for(int i=0; i<pow(2,m_aretes.size()); i++)
    {
        for (int j=0; j<m_aretes.size(); j++)
        {
            std::cout<<tab[i][j]<<std::endl;
        }
        std::cout<<std::endl;

    }
    return tab;


}

void graphe::filtre1()
{
    std::vector<std::vector<bool>> m_tab;
    m_tab = rendrebinaire();
    int cpt = 0;
    int taille= m_aretes.size();
    int ordre= m_sommets.size();
    int i, j;
    int nbsolutions = pow(2, taille);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::vector<std::vector<bool>> tabfiltre1;
    for (i=0; i<nbsolutions; i++)
    {

        std::vector<bool> tab = m_tab[i];
        cpt = 0;
        for (j=0; j<taille; j++)
        {
            if (tab[j] == true)
            {
                cpt = cpt+1;

            }
        }

        if (cpt == (ordre-1))
        {
            tabfiltre1.push_back(tab);
        }
    }
    std::cout << std::endl;
    std::cout << "Filtrage des ordre-1 Aretes  " << tabfiltre1.size()  <<"  combinaison restantes"<< std::endl;
    for (i=0; i<tabfiltre1.size(); i++)
    {
        std::vector<bool> m_listeFiltrer = tabfiltre1[i];
        for (j=taille-1; j>=0; j--)
        {
            std::cout << m_listeFiltrer[j] ;
        }
        std::cout << std::endl;
    }
}


graphe::~graphe()
{
}
