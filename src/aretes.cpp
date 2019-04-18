#include <iostream>
#include "aretes.h"

Aretes::Aretes(int ida,int S1,int S2,double poids1,double poids2):m_ida{ida},m_s1{S1},m_s2{S2},m_p1{poids1},m_p2{poids2}
{

}
int Aretes::getS1()
{return m_s1;
}
int Aretes::getS2()
{return m_s2;
}

void Aretes::afficherData() const
 {
     std::cout<<"    "<<m_ida<<" "<<m_s1<<"  "<<m_s2<<"  "<<m_p1<<"  "<<m_p2<<std::endl;
 }
double Aretes::getpoids1()
{return m_p1;
}
double Aretes::getpoids2()
{return m_p2;
}

int Aretes::getida()
{return m_ida;
}


Aretes::~Aretes()
{
    //dtor
}
