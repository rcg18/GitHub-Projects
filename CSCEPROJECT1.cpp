#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    int i;
    int points = 100;
    string userName;
    bool choice;
    enum Operation
    {
        Add = 1,
        SUBTRACT = 2,
        DISPLAY = 3,
        GIVEUP = 4,
        EXIT = 5
    };

    enum Operation operation;

    do
    {

        choice = true;

        cout << "Enter your name: ";
        getline(cin, userName);

        for (i = 0; i < userName.size(); ++i)
        {
            if (!(isalpha(userName.at(i)) || isspace(userName.at(i))))
            {
                choice = false;
                break;
            }
        }

        if (choice)
        {
            cout << "Welcome " << userName << endl;
        }
        else
        {
            cout << "Your name can only have alphabets or spaces. Enter again." << endl;
        }

    } while (!choice);

    return 0;
}
