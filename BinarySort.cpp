/**
 *
 * @file     FunctorSort.cpp
 *
 * @authors  M. Laporte, D. Mathieu
 *
 * @date     07/12/2011
 *
 * @version  V1.0
 *
 **/
#include <iostream>
#include <string>
#include <algorithm>            // sort()
#include <vector>
#include "comparator.hpp"
#include "binary.hpp"

using namespace std;

namespace
{

    class Pers
    {
        string   myNom;
        unsigned myAge;

      public :
        Pers (const string & Nom, unsigned Age)
            : myNom (Nom), myAge (Age) {}

        const string & getNom (void) const noexcept { return myNom; }
        unsigned       getAge (void) const noexcept { return myAge; }

    private :
        ostream & display (ostream & os)  const
        {
            return os << getAge () << " - " << getNom ();

        } // display()

      public :
        friend ostream & operator << (ostream & os, const Pers & p)
        {
            return p.display (os);

        }

    }; // Pers

    class TriParAgeAsc : public Binary<Pers, Pers, bool>
    {
      public:
        virtual bool operator () (const Pers & p1, const Pers & p2)const {
            return p1.getAge () <= p2.getAge ();
        } // operator ()

    }; // TriParAgeAsc

    class TriParNomDesc : public Binary<Pers, Pers, bool>
    {
      public:

        virtual bool operator () (const Pers & p1, const Pers & p2) const {
            return p1.getNom () >= p2.getNom ();
        } // operator ()

    }; // TriParNomDesc

    template <typename T>
    typename vector<T>::iterator partitionnement(const typename vector<T>::iterator &first, const typename vector<T>::iterator &last, const Binary<T, T, bool> &comp) {
        bool isUp = true;
        typename vector<T>::iterator pivot = first;
        typename vector<T>::iterator current = last;
        int incr = -1;

        while (pivot != current) {
            if ((!isUp && comp(*pivot, *current)) || (isUp && comp(*current, *pivot))) {
                swap(*pivot, *current);
                swap(pivot, current);

                isUp = !isUp;
                incr = -incr;
            }
            current += incr;
        }
        return pivot;
    }

    template <typename T>
    void quickSort(const typename vector<T>::iterator &begin, const typename vector<T>::iterator &end, const Binary<T, T, bool> &comp) {
        if (begin < end) {
            typename vector<T>::iterator pos = partitionnement(begin, end - 1, comp);

            quickSort(begin, pos, comp);
            quickSort(pos + 1, end, comp);
        }
    }

    void functorBinarySort (void)
    {
        cout << "FunctorSort : \n";

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

        cout << "\nTri par age croissant\n\n";

        quickSort (vPers.begin(), vPers.end(), TriParAgeAsc());

        for (const Pers & personne : vPers)
            cout << personne << '\n';

        cout << "\nTri par nom decroissant\n\n";

        quickSort (vPers.begin(), vPers.end(), TriParNomDesc());

        for (const Pers & personne : vPers)
            cout << personne << '\n';

    } // functorSort()
} // namespace


int main (void)
{
    functorBinarySort ();

    return 0;

} // main()
