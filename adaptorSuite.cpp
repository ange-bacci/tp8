        cout << "\nRecherche de la premiere personne d'age <= 40 : ";
 
        CVPers::const_iterator pos =
            find_if (vPers.begin (), vPers.end (),  // a completer
 
        if (vPers.end () == pos)
            cout << "Aucun element correspondant\n";
        else
            cout << *pos << '\n';
 
        cout << "\nRecherche de la premiere personne d'age<= 4 : ";
 
        pos = find_if (vPers.begin (), vPers.end (), // a completer
 
        if (vPers.end () == pos)
            cout << "Aucun element correspondant\n";
        else
            cout << *pos << '\n';