        cout << "\nRecherche sur nom > Noemie&nbsp;: ";
 
        pos = find_if (vPers.begin (),  vPers.end (), // a completer
 
        if (vPers.end () == pos)
            cout  << "Aucun element ne correspond a ce critere\n";
        else
            cout << *pos << '\n';
 
        cout  << "\nRecherche sur nom > alfred&nbsp;: ";
 
        pos = find_if (vPers.begin (),  vPers.end (), // a completer
 
        if (vPers.end () == pos)
            cout  << "Aucun element ne correspond a ce critere\n";
        else
            cout << *pos << '\n';