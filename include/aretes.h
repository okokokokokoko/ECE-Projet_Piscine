#ifndef ARETES_H
#define ARETES_H
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

class Aretes
{
    public:
        Aretes(int ida,int S1,int S2,double poids1,double poids2);
        void afficherData() const;
        int getS1();
        int getS2();
        int getida();
        double getpoids1();
        double getpoids2();
        virtual ~Aretes();

    protected:

    private:

        /// Données spécifiques du sommet
        int m_ida; // Identifiant
        int m_s1;
        int m_s2;
        double m_p1;
        double m_p2;
};

#endif // ARETES_H
