#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>
#include <iomanip>
#include <unistd.h>
using namespace std;
const int SIZEE = 4;

enum menuChoice // menu choice for the user to choose from
{
    Match = 1,
    Display = 2,
    Giveup = 3,
    Exit = 4
};

string getName()
{
    bool choice;
    string playerName = " ";
    do
    {

        choice = true;

        cout << "Enter your name: ";
        getline(cin, playerName);

        for (int i = 0; i < playerName.size(); ++i)
        {
            if (!(isalpha(playerName.at(i)) || isspace(playerName.at(i)))) // checks each string and make sure there is only alphabet letters or spaces
            {
                choice = false; // if its false break out of the loop
                break;
            }
        }

        if (!(choice)) // if false we will output the message
        {
            cout << "Your name can only have alphabets or spaces. Enter again." << endl; // if its false you must keep on entering until its true
        }

    } while (!choice);

    bool word = true; // check every first word that the user enters
    for (int i = 0; i < playerName.size(); ++i)
    {
        if (isalpha(playerName.at(i)))
        {
            if (word)
            {
                playerName.at(i) = toupper(playerName.at(i)); // makes sure the first letter of each word will be capitalized
                word = false;
            }
            else
            {
                playerName.at(i) = tolower(playerName.at(i)); // the rest of the remaining letters will be lowercase
            }
        }
        else
        {
            word = true;
        }
    }

    return playerName;
}

int genRandomIndex()
{

    int randomIndex = rand() % SIZEE; // return random generated index of the 2d array
    return randomIndex;
}

void shuffle(int array[SIZEE][SIZEE])
{
    for (int i = 0; i < 15; i++)
    {
        // obtaining the indicies of the first card
        int row1 = genRandomIndex();
        int col1 = genRandomIndex();
        int row2 = genRandomIndex();
        int col2 = genRandomIndex();
        // makes sure were going to get tow different indicies
        while (row1 == row2 && col1 == col2)
        {
            row2 = genRandomIndex();
            col2 = genRandomIndex();
        }
        int temp = array[row1][col1];
        array[row1][col1] = array[row2][col2];
        array[row2][col2] = temp;
    }
}

void initialize(int arragement[SIZEE][SIZEE], int status[SIZEE][SIZEE])
{
    int card = 1;
    int count = 0;
    for (int i = 0; i < SIZEE; i++)
    {
        for (int j = 0; j < SIZEE; j++)
        {
            arragement[i][j] = card;
            count++;
            // makes sure that the number must occur two times before it can increment
            if (count % 2 == 0)
            {
                card++;
            }
            status[i][j] = 0; // make sure all the cards are facedown
        }
    }
    shuffle(arragement); // shuffles the cards
}
void showCards(int arragement[SIZEE][SIZEE], int status[SIZEE][SIZEE], bool showReal = false)
{
    cout << "    "; // labels for the rows section
    for (int j = 0; j < SIZEE; j++)
    {
        cout << setw(4) << j; // labels for the column section
    }
    cout << "\n     -------------------------\n";

    for (int i = 0; i < SIZEE; i++)
    {
        cout << " " << i << " |"; // labels for the rows section
        for (int j = 0; j < SIZEE; j++)
        {
            if (showReal || status[i][j] == 1) // if the parameter is true its going to show all the cards in the 2d coordinate
            {
                cout << setw(4) << arragement[i][j];
            }
            else
            {
                cout << setw(4) << "*"; // if the parameter is false its going to show only the face cards and show "*" for the cards that are not faced down
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool allFaceUp(int status[SIZEE][SIZEE])
{
    for (int i = 0; i < SIZEE; i++)
    {
        for (int j = 0; j < SIZEE; j++)
        {
            if (status[i][j] == 0) // this is checking all the elemts of the array if its 0 meaning they are face down return false  else return true
            {
                return false;
            }
            else if (status[i][j] == 1) // this is checking all the elemts of the array if its 1 meaning they are face up return true
            {
                return true;
            }
        }
    }
    return true;
}

bool checkInputs(int row, int col, const int status[SIZEE][SIZEE])
{
    // Check if the coordinates are within bounds
    if (row < 0 || row >= SIZEE || col < 0 || col >= SIZEE)
    {
        return false;
    }
    // Check if the card is already face up (assuming 1 means face up)
    if (status[row][col] == 1)
    {
        return false;
    }
    return true;
}

void match(int arragement[SIZEE][SIZEE], int status[SIZEE][SIZEE], int &variablepoints)
{
    showCards(arragement, status);
    int row1, col1, row2, col2;

    cout << "Enter coordinate for first card "; // ask user for the first coordinates
    cin >> row1 >> col1;

    if (!checkInputs(row1, col1, status))
    {
        cout << "as card is already faced up" << endl;
        return;
    }

    // getting what the second coordinates will be for the second card
    cout << "Enter coordinate for second card: ";
    cin >> row2 >> col2;

    if (!checkInputs(row2, col2, status)) // lets us know if a card has already been faced up
    {
        cout << "as card is already faced up" << endl;
        return;
    }

    if (row1 == row2 && col1 == col2) // makes sure that both the coordinates are not the same
    {
        cout << "the coordinate values of the two cards should be different" << endl;
        return;
    }

    // shows us the cards that were picked by the user
    status[row1][col1] = 1;
    status[row2][col2] = 1;
    showCards(arragement, status); // were extracting the data for the cards picked

    // checking if the two card values match
    if (arragement[row1][col1] == arragement[row2][col2])
    {
        variablepoints += 5;
        status[row1][col1] = 1;
        status[row2][col2] = 1;
    }
    else
    {

        cout << "Cards do not match at locations: (" << row1 << ", " << col1 << ") and (" << row2 << ", " << col2 << ")" << endl;
        variablepoints -= 1;
        status[row1][col1] = 0;
        status[row2][col2] = 0;
    }
    cout << "(screen clear)" << endl;
    cout << "Your updated points are: " << variablepoints << endl;
}
void display(int arrangement[SIZEE][SIZEE], int status[SIZEE][SIZEE], int &variablepoints)
{

    if (variablepoints < 10) // if the user has less than 10 points they won't be able to display a pair of cards
    {
        cout << "You do not have enough points to display a pair of cards." << endl;
        return;
    }
    // where we are going to store the coordinates of all the pairs
    int row1 = -1;
    int col1 = -1;
    int row2 = -1;
    int col2 = -1;
    // visiting each element/ card of the 2d array
    // checking the cards if its face up as well
    for (int i = 0; i < SIZEE; i++)
    {
        for (int j = 0; j < SIZEE; j++)
        {
            if (status[i][j] == 0) // this is telling us the card is faced down, if the card is faced down we are going to skip it
            {
                row1 = i; // getting us the coordinates of the first card
                col1 = j;
                break;
            }
        }
        // helps find the first card that has been hidden
        if (row1 != -1)
        {
            break;
        }
    }
    // where we figure out where the other matching cards are going to be at as well as their indicies
    if (row1 != -1)
    {
        for (int i = 0; i < SIZEE; i++) // helps us find the indicies of the first card as well as the second card
        {
            for (int j = 0; j < SIZEE; j++)
            {
                if (status[i][j] == 0 && arrangement[i][j] == arrangement[row1][col1] && !(i == row1 && j == col1))
                {
                    row2 = i;
                    col2 = j;
                    break;
                }
            }
            // we are going to break out of the loop if we have found a match
            if (row2 != -1)
            {
                break;
            }
        }
    }
    // if the answer is not negative 1 which would be invalid we are going to set the first and second both face up
    if (row1 != -1 && row2 != -1)
    {
        status[row1][col1] = 1; // use the coordinates of the two cards to set the status up
        status[row2][col2] = 1;
        variablepoints -= 10; // where we deduct the 10 points
    }
    // this will show us what the new board is going to look like
    showCards(arrangement, status);
    cout << "\nYour updated points are: " << variablepoints << endl;
}

int main()
{

    int arrangement[SIZEE][SIZEE];
    int status[SIZEE][SIZEE];
    int points = 50; // points both the players are going to start with

    srand(time(0));

    initialize(arrangement, status);
    showCards(arrangement, status);
    string caption = "+-------------------------------------------------------+\n"
                     "|\tComputer Science and Engineering\t\t|\n"
                     "|\tCSCE 1030 - Computer Science I\t\t\t|\n"
                     "|\tGael Mendez  gjm0124 gaelmendez@my.unt.edu\t|\n"
                     "|\tRyan Griffin rcg0149 ryangriffin3@my.unt.edu\t|\n"
                     "|\tAlexander King amk0368 alexanderking3@my.unt.edu\t|\n"
                     "--------------------------------------------------------+\n";

    cout << caption << endl;
    string name = getName();
    cout << "Welcome " << name << endl;

    bool playagain = true;
    while (playagain)
    {
        int choice; // tell what the player is going to choose
        cout << "1. Match" << endl;
        cout << "2. Display" << endl;
        cout << "3. Giveup" << endl;
        cout << "4. Exit" << endl;
        cout << "What do you want to do: ";
        cin >> choice;

        menuChoice playerChoice = static_cast<menuChoice>(choice); // this is to convert what the choice value is into an enum value
        switch (playerChoice)
        {
        case Match:
            match(arrangement, status, points);

            if (allFaceUp(status)) // this checks if all the face cards are up
            {
                cout << "The player has won the game";
                cout << "Your final points are: " << points;
                cout << "Do you want to play again? (y/n): ";
                char playagain;
                cin >> playagain;
                if (playagain == 'y' || playagain == 'Y')
                {
                    initialize(arrangement, status);
                    points = 50; // we are resetting the user points if they want to play a new game
                }
                else
                {
                    playagain = false;
                }
            }
            break;
        case Display:
            display(arrangement, status, points);

            break;

        case Giveup:
            showCards(arrangement, status, true); // show all card if they giveup
            cout << "(screen clear)" << endl;
            cout << "Do you want to play again? (y/n): ";
            cin >> playagain;
            cout << "Your final points are: " << points << endl;
            cout << "Goodbye, Test " << name << "." << endl;
            char giveupoption;
            cin >> giveupoption;
            if (giveupoption == 'y' || giveupoption == 'Y')
            {
                cout << "Location of cards were:" << endl;
                initialize(arrangement, status);
                points = 50;
            }
            else
            {
                playagain = false;
            }
            break;

        case Exit:
            cout << "Your final points are: " << points << endl;
            cout << "Goodbye " << name << "." << endl;
            ;

            playagain = false;
            break;

        default:
            cout << "Invalid choice. Enter again." << endl;

            continue;
        }

        if (points < 0)
        { // if points are less than zero you won't be able to continue with the game
            cout << "You do not have enough points to display a pair of cards.";
            playagain = false;
        }
    }

    return 0;
}