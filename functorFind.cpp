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
 
        pos = find_if (vPers.begin (), vPers.end (), // a completer
        if (vPers.end () ==pos)
            cout << "Aucun element ne correspond a ce critere\n";
        else
            cout << *pos << '\n';
 
        cout << "\nRecherche sur  43 <= age <= 45 : ";
 
        pos = find_if (vPers.begin (), vPers.end (), // a completer
        if (vPers.end () == pos)
            cout << "Aucun element ne correspond a ce critere\n";
        else
            cout << *pos << '\n';
 
        cout << '\n';
 
    } // functorFind()