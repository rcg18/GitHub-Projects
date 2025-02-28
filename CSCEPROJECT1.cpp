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
    bool choice = true;
    string userName;
    enum Operation
    {
        Add = 1,
        SUBTRACT = 2,
        DISPLAY = 3,
        GIVEUP = 4,
        EXIT = 5
    };

    enum Operation operation;

    cout << "Enter your name: ";
    getline(cin, userName);

    do
    {

        for (i = 0; i < userName.size(); ++i)
        {
            if (!(isalpha(userName.at(i)) || isspace(userName.at(i))))
            {
                choice = false;
                break;
            }

            if (choice)
            {
                cout << "Welcome " << userName << "." << endl;
            }
            else
            {
                cout << "Wrong choice. Please enter again." << endl;
            }
        }

    } while (choice != false);

    return 0;
}