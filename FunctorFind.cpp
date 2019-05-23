#include <iostream>
#include <string>
#include <vector>
#include <finder.hpp>
#include <unary.hpp>

using namespace std;



namespace {

    class Pers {
        string myNom;
        unsigned myAge;

    public:
        Pers (const string & Nom, unsigned Age) : myNom (Nom), myAge (Age) {}

        const string & getNom (void) const noexcept { return myNom; }
        unsigned getAge (void) const noexcept { return myAge; }

    private:
        ostream & display (ostream & os) const {
            return os << getAge () << " - " << getNom ();
        } // display()

    public:
        friend ostream & operator << (ostream & os, const Pers & p) {
            return p.display (os);
        }

    }; // Pers

    class FindTrancheAge : public Unary<Pers, bool> {

        unsigned ageMin;
        unsigned ageMax;

    public:

        FindTrancheAge(const unsigned &ageMin, const unsigned &ageMax) : ageMin(ageMin), ageMax(ageMax) {}
        virtual bool operator() (const Pers &personne) const {
            return personne.getAge() >= this->ageMin && personne.getAge() <= this->ageMax;
        }
    };

    class FindNomMin : public Unary<Pers, bool> {
        string nomMin;

    public:
        FindNomMin(const string &nomMin) : nomMin(nomMin) {}
        virtual bool operator() (const Pers &personne) const {
            return nomMin < personne.getNom();
        }
    };

    template <class T, class R>
    typename vector<T>::iterator find_if(const typename vector<T>::iterator &begin, const typename vector<T>::iterator &end, const Unary<T, R> &finder) {
        typename vector<T>::iterator pos = begin;
        typename vector<T>::iterator last = end;

        for (; pos < last; ++pos) {
            if (finder(*pos)) {
                return pos;
            }
        }
        return end;
    }

    void functorFind (void)
    {
        cout << "FunctorFind&nbsp;: \n";

        typedef vector <Pers> CVPers;
        CVPers vPers;

        vPers.push_back ( Pers ("Charlotte", 21));
        vPers.push_back ( Pers ("Alfred",    12));
        vPers.push_back ( Pers ("Jean",      42));
        vPers.push_back ( Pers ("Noemie",    11));
        vPers.push_back ( Pers ("Berthe",    99));
        vPers.push_back ( Pers ("Agathe",    29));
        vPers.push_back ( Pers ("Sylvain",   42));
        vPers.push_back ( Pers ("Pierre",    75));

        for (const Pers & personne : vPers)
            cout << personne << '\n';

        CVPers::const_iterator pos;

        cout << "\nRecherche sur  43 <= age <= 75 : ";

        pos = find_if (vPers.begin (), vPers.end (), FindTrancheAge(43, 75));
        if (vPers.end () ==pos)
            cout << "Aucun element ne correspond a ce critere\n";
        else
            cout << *pos << '\n';

        cout << "\nRecherche sur  43 <= age <= 45 : ";

        pos = find_if (vPers.begin (), vPers.end (), FindTrancheAge(43, 45));
        if (vPers.end () == pos)
            cout << "Aucun element ne correspond a ce critere\n";
        else
            cout << *pos << '\n';

        cout << '\n';

        cout << "\nRecherche sur nom > Noemie : ";

        pos = find_if (vPers.begin (),  vPers.end (), FindNomMin("Noemie"));

        if (vPers.end () == pos)
            cout  << "Aucun element ne correspond a ce critere\n";
        else
            cout << *pos << '\n';

        cout  << "\nRecherche sur nom > alfred : ";

        pos = find_if (vPers.begin (),  vPers.end (), FindNomMin("alfred"));

        if (vPers.end () == pos)
            cout  << "Aucun element ne correspond a ce critere\n";
        else
            cout << *pos << '\n';

    } // functorFind()

}

int main() {

    functorFind();

    return 0;
}
