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
 
using namespace std;
 
namespace
{
    template <typename T>
    class ILessThanGen
    {
      public :
        virtual ~ILessThanGen (void) {}
        virtual bool operator () (const T &, const T &) const = 0;
 
    }; // ILessThanGen
 
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
 
    class TriParAgeAsc : public ILessThanGen <Pers>
    {
      public :
        virtual ~TriParAgeAsc (void) noexcept {}
 
        virtual bool operator () (const Pers & p1, const Pers & p2)
                        const noexcept
        {
            return p1.getAge () <= p2.getAge ();
 
        } // operator ()
 
    }; // TriParAgeAsc
 
    class TriParNomDesc : public ILessThanGen <Pers>
    {
      public :
        virtual ~TriParNomDesc (void) noexcept {}
 
        virtual bool operator () (const Pers & p1, const Pers & p2)
                        const noexcept
        {
            return p1.getNom () >= p2.getNom ();
 
        } // operator ()
 
    }; // TriParNomDesc
 
    void functorSort (void)
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
 
        sort (vPers.begin (), vPers.end (), TriParAgeAsc ());
 
        for (const Pers & personne : vPers)
            cout << personne << '\n';
 
        cout << "\nTri par nom decroissant\n\n";
 
        sort (vPers.begin (), vPers.end (), TriParNomDesc ());
 
        for (const Pers & personne : vPers)
            cout << personne << '\n';
 
    } // functorSort()
 
} // namespace
 
int main (void)
{
    functorSort ();
 
    return 0;
 
} // main()