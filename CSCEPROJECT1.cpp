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
    bool valid = true;
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
            if (isalpha(userName.at(i)) || isspace(userName.at(i)))
            {
                valid = true;
                cout << "Welcome" << userName << endl;
            }
            else
            {
                valid = false;
                cout << "Your name can only have alphabets or spaces. Enter again";
            }
        }

    } while (valid != false);

    return 0;
}