/**
 *
 * @file    IntegrTrapezes.cpp
 *
 * @authors D. Mathieu
 *
 * @date    06/11/2007
 *
 * @version V1.0
 *
 * @brief   Integration par la methodes des trapezes au moyen de
 *             pointeurs de fonctions
 
 *
 **/
#include <iostream>
#include <cmath>               // cos(), sin(), M_PI_2
#include "unary.hpp"
 
using namespace std;
 
namespace
{

    class UnaryCos : public Unary<double, double>
    {
    public:
        virtual double operator()(const double &d) const {
            return cos(d);
        }
    };

    class UnarySin : public Unary<double, double>
    {
    public:
        virtual double operator()(const double &d) const {
            return sin(d);
        }
    };

    double integrTrapezes (const Unary<double, double> &f, double a, double b, unsigned n)
    {
        double s     = (f (a) + f (b)) / 2.0;
        double delta = (b - a) / double (n);
 
        for ( ; --n; ) s += f (a += delta);
 
        return s * delta;
 
    } // integrTrapezes
 
    void testIntegrTrapezes (void)
    {
        cout << "IntegrTrapezes : \n\n";
 
        cout << "Methode des trapezes : \n";
 
        cout << "S (cos (x)) entre 0 et +Pi/2  avec   5 intervalles = "
             << integrTrapezes (UnaryCos(), 0, M_PI_2,   5) << '\n';
 
        cout << "S (cos (x)) entre 0 et +Pi/2  avec  10 intervalles = "
             << integrTrapezes (UnaryCos(), 0, M_PI_2,  10) << '\n';
 
        cout << "S (cos (x)) entre 0 et +Pi/2  avec  50 intervalles = "
             << integrTrapezes (UnaryCos(), 0, M_PI_2,  50) << '\n';
 
        cout << "S (cos (x)) entre 0 et +Pi/2  avec 100 intervalles = "
             << integrTrapezes (UnaryCos(), 0, M_PI_2, 100) << '\n';
 
        cout << '\n';
 
        cout << "S (sin (x)) entre -Pi/2 et 0  avec   5 intervalles = "
             << integrTrapezes (UnarySin(), -M_PI_2, 0,   5) << '\n';
 
        cout << "S (sin (x)) entre -Pi/2 et 0  avec  10 intervalles = "
             << integrTrapezes (UnarySin(), -M_PI_2, 0,  10) << '\n';
 
        cout << "S (sin (x)) entre -Pi/2 et 0  avec  50 intervalles = "
             << integrTrapezes (UnarySin(), -M_PI_2, 0,  50) << '\n';
 
        cout << "S (sin (x)) entre -Pi/2 et 0  avec 100 intervalles = "
             << integrTrapezes (UnarySin(), -M_PI_2, 0, 100) << '\n';
 
    } // TestIntegrTrapezes()
 
} // namespace anonyme
 
int main (void)
{
    testIntegrTrapezes ();
 
    return 0;
 
} // main()
