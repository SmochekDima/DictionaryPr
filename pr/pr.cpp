#include <iostream>
#include <map>
#include <list>
#include <string>
using namespace std;

class Dictionary
{
private:
    map<string, list<string>> dic;
public:
    void AddWord() {
        string word;
        cout << "Enter word: ";
        getline(cin, word);

        if (dic.find(word) != dic.end())
        {
            cout << "Word already exists!" << endl;
            return;
        }
        list<string> translates;
        string translate;
        do
        {
            cout << "Enter translate (empty to stop): ";
            getline(cin, translate);

            if (!translate.empty())
            {
                translates.push_back(translate);
            }

        } while (!translate.empty());
        dic.insert(make_pair(word, translates));

        cout << "Word added!" << endl;
    }
    void FindWord() {
        string word;

        cout << "Enter word: ";
        getline(cin, word);

        map<string, list<string>>::iterator it = dic.find(word);

        if (it == dic.end())
        {
            cout << "Word not found!" << endl;
        }
        else
        {
            cout << "Translations: " << endl;

            for (string translate : it->second)
            {
                cout << translate << endl;
            }
        }
    }
    void AddTranslate() {
        string word;

        cout << "Enter word: ";
        getline(cin, word);

        map<string, list<string>>::iterator it = dic.find(word);

        if (it == dic.end())
        {
            cout << "Word not found!" << endl;
            return;
        }

        string translate;

        cout << "Enter translate: ";
        getline(cin, translate);

        it->second.push_back(translate);

        cout << "Translate added!" << endl;
    }
    void RemoveWord() {
        string word;

        cout << "Enter word: ";
        getline(cin, word);

        map<string, list<string>>::iterator it = dic.find(word);

        if (it == dic.end())
        {
            cout << "Word not found!" << endl;
            return;
        }
        dic.erase(it);

        cout << "Word removed!" << endl;
    }
    void ShowAll()
    {
        if (dic.empty())
        {
            cout << "Dictionary is empty!" << endl;
            return;
        }

        for (map<string, list<string>>::iterator it = dic.begin(); it != dic.end(); it++)
        {
            cout << it->first << ": ";

            for (string translate : it->second)
            {
                cout << translate << " ";
            }

            cout << endl;
        }
    }
};

int main()
{
    Dictionary dic;

    int choice;

    do
    {
        cout << "\n--- DICTIONARY ---" << endl;
        cout << "1. Add word" << endl;
        cout << "2. Find word" << endl;
        cout << "3. Add translate" << endl;
        cout << "4. Remove word" << endl;
        cout << "5. Show all" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            dic.AddWord();
            break;
        case 2:
            dic.FindWord();
            break;
        case 3:
            dic.AddTranslate();
            break;
        case 4:
            dic.RemoveWord();
            break;
        case 5:
            dic.ShowAll();
            break;
        case 0:
            cout << "Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

}

