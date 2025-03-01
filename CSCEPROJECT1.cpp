#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>
using namespace std;

/*

Computer Science and Engineering
CSCE 1030 - Computer Science I
Ryan Griffin  rcg0149 RyanGriffin3@my.unt.edu

*/

int main()
{
    int i;
    int rand1;
    int rand2;
    int points = 100;
    string userName;
    bool choice;
    srand(time(0)); // declaring the seed for the random number generator
    // declaring the enum operation
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
            if (!(isalpha(userName.at(i)) || isspace(userName.at(i)))) // checks each string and make sure there is only alphabet letters or spaces
            {
                choice = false; // if its false break out of the loop
                break;
            }
        }

        if (choice) // if true we will output the message
        {
            cout << "Welcome " << userName << endl;
        }
        else
        {
            cout << "Your name can only have alphabets or spaces. Enter again." << endl; // if its false you must keep on entering until its true
        }

    } while (!choice);

    do
    {
        rand1 = rand() % (150 - 100 + 1) + 100; // generating the random numbers for both variables
        rand2 = rand() % (150 - 100 + 1) + 100;

        // if true meaning rand1 >= rand2 the two random numbers will not be generated and must be regenerated until we get rand1 being less than rand2
        if (rand1 >= rand2)
        {
            cout << "rand1: " << rand1 << " is greater than or equal to " << rand2 << " Getting new numbers" << endl;
        }

    } while (rand1 >= rand2);

    cout << "Your two random numbers have been generated " << endl;
    cout << "rand1: " << rand1 << endl;
    cout << "rand2: " << rand2 << endl;

    return 0;
}
