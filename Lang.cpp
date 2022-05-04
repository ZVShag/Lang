#include <iostream>
#include <fstream>
#include <vector>
#include<Windows.h>
#include<thread>
using namespace std;
/*Создать структуру англо-русский словарь. Запись в файл добавление слов, поиск перевода.
{

     eng: cat;
     rus: кошка;
    }
}
*/

struct Lang
{
    string eng;
    string rus;
    Lang(string s, string r) : eng(s), rus(r)
    {}
};
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<Lang> lang = {};
    Lang man("cat", "кошка");
    lang.push_back(man);
    while (true)
    {
        cout << "If you want add: press 1 " << endl;
        cout << "If you want find: press 2 " << endl;
        cout << "If you want stop: press 3 " << endl;

        int c;
        cin >> c;
        vector<Lang> new_lang;
        string rus;
        string eng;
        ifstream in("lang.txt");
        if (in.is_open())
        {
            while (in >> eng >> rus)
            {
                new_lang.push_back(Lang(eng, rus));
            }
        }
        in.close();
        for (int i = 0; i < new_lang.size(); i++)
            cout << new_lang[i].rus << endl;
        if (c == 3)
            break;
        if (c == 1)
        {
            cout << endl << "Input eng: " << endl;
            cin >> man.eng;
            cout << endl << "Input rus: " << endl;
            cin >> man.rus;

            bool b = true;
            for (int i = 0; i < lang.size() - 1; i++)
            {
                if (lang[i].eng == man.eng)
                {
                    b = false;
                    cout << "Такое слово уже есть в словаре!!!! ";
                    break;
                }
            }
            if (b)
            {
                lang.push_back(man);
                ofstream out("lang.txt",ios::app);
                try
                {
                    out  <<  "eng: " << man.eng << endl << "rus: " << man.rus  ;
                    

                    out.close();
                }
                catch (...)
                {
                    cout << "404";
                }
            }
        }
        if (c == 2)
        {
            cout << "Введите слово для поиска: ";
            string search;
            cin >> search;
            for (int i = 0; i < new_lang.size(); i++)
            {
                if (new_lang[i].eng == search)
                {
                    cout << "Перевод:";
                    cout << new_lang[i].rus << endl;
                    break;
                }

                if (new_lang[i].rus == search)
                {
                    cout << "Перевод:";
                    cout << new_lang[i].eng << endl;
                    break;
                }
            }


        }
        
        
        return 0;
    }

}

void find(vector<Lang>* vect,string voc)
{
    

    
}
