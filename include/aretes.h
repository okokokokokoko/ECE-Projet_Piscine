#ifndef ARETES_H
#define ARETES_H
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

class Aretes
{
    public:
        Aretes(std::string ida,std::string S1,std::string S2,double poids1,double poids2);
        void afficherData() const;
        std::string getS1();
        std::string getS2();
        std::string getida();
        double getpoids1();
        double getpoids2();
        virtual ~Aretes();

    protected:

    private:

        /// Données spécifiques du sommet
        std::string m_ida; // Identifiant
        std::string m_s1;
        std::string m_s2;
        double m_p1;
        double m_p2;
};

#endif // ARETES_H
