#include <fstream>
#include <iostream>
#include<windows.h>
#include<string>
using namespace std;

class Spravochnick
{
public:
    string Nazvanie, Name, Phone, Adress, Deyatel;
	Spravochnick() = default;
	Spravochnick(string naz, string n, string ph, string a, string d)
	{
        this->Nazvanie = naz;
        this->Name = n;
        this->Phone = ph;
        this->Adress = a;
        this->Deyatel = d;
	}

    void Init(int x, Spravochnick ob)
    {
        string path = "Text.txt";
        ofstream out;
        out.open(path, ofstream::app);

        // Если файл удалось открыть.
        if (out.is_open())
        {
            for (size_t i = 0; i < x; i++)
            {
                cout << "Nazv?";
                cin >> ob.Nazvanie;

                cout << "Name?";
                cin >> ob.Name;

                cout << "Number?";
                cin >> ob.Phone;

                cout << "Adress?";
                cin >> ob.Adress;

                cout << "Deyatelnost?";
                cin >> ob.Deyatel;
            }
            
            out.write((char*)&ob, sizeof(Spravochnick));
            out.close();
        }
        else
            cout << "Could not open the file" << endl;
    }
    void Print()
    {
        cout << "Nazvanie-" << Nazvanie << "\tName-" << Name << "\tNumber-" << Phone << "\tAdress-" << Adress << "\tDeyatelnost-" << Deyatel << endl;
    }
    void Clear()
    {
        ofstream out("Text.txt");
        if (out.is_open())
            cout << "";
        else
            cout << "Could not open the file" << endl;
    }
    void Search_Naz(string x, int y)
    {
        string path = "Text.txt";
        ifstream in;
        in.open(path);

        if (in.is_open())
        {
            Spravochnick pnt;

            while (in.read((char*)&pnt, sizeof(Spravochnick)))
            {
                if (y == 1)
                {
                    if (pnt.Nazvanie == x)
                        pnt.Print();
                }
                if (y == 2)
                {
                    if (pnt.Name == x)
                        pnt.Print();
                }
                if (y == 3)
                {
                    if (pnt.Phone == x)
                        pnt.Print();
                }
                if (y == 4)
                {
                    if (pnt.Deyatel == x)
                        pnt.Print();
                }
            }
            in.close();
        }
        else
            cout << "Could not open the file" << endl;
    }

};


int main()
{
    Spravochnick ob;
    //ob.Clear();

    while (true)
    {
        cout << "1. Write" << endl;
        cout << "2. Read" << endl;
        cout << "3. Clear file" << endl;
        cout << "4. Search Nazvanie" << endl;
        cout << "5. Search Name" << endl;
        cout << "6. Search Number" << endl;
        cout << "7. Search Deyatelnost" << endl;
        int choice = 0;
        cin >> choice;

        int x = 0;
        if (choice == 1)
        {
            x = 1;
            cout << "People?" << endl;
            cin >> x;
        }
        else
            x = 1;

        switch (choice)
        {
        case 1:
            ob.Init(x, ob);
        break;
        case 2:
        {
            string path = "Text.txt";
            ifstream in;
            in.open(path);

            if (in.is_open())
            {
                Spravochnick pnt;

                while (in.read((char*)&pnt, sizeof(Spravochnick)))
                    pnt.Print();

                in.close();
            }
            else
                cout << "Could not open the file" << endl;
        }
        break;
        case 3:
        {
            ob.Clear();
        }
        break;
        case 4:
        {
            string Naz;
            cout << "Nazvanie?";
            cin >> Naz;
            ob.Search_Naz(Naz, 1);
        }
        break;
        case 5:
        {
            string Naz;
            cout << "Name?";
            cin >> Naz;
            ob.Search_Naz(Naz, 2);
        }
        break;
        case 6:
        {
            string Naz;
            cout << "Number?";
            cin >> Naz;
            ob.Search_Naz(Naz, 3);
        }
        break;
        case 7:
        {
            string Naz;
            cout << "Deyatelnost?";
            cin >> Naz;
            ob.Search_Naz(Naz, 4);
        }
        break;
        default:
            cout << "Invalid action" << endl;
            break;
        }
    }
}