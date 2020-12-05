#include <iostream>

using namespace std;

int main()
{
    cout << "Welcome to Camel!" << endl;
    cout << "You have stolen a camel to make your way across the great Mobi desert." << endl;
    cout << "The natives want their camel back and are chasing you down! Survive your desert trek and out run the natives." << endl << endl;

    bool done = false;
    bool traveled = false;

    int milesTraveled = 0;
    int nativesMilesTraveled = -20;
    int thirst = 3;
    int camelTiredness = 0;
    int remainingDrinks = 3;


    do
    {
        traveled = false;

        cout << "A. Drink from your canteen." << endl;
        cout << "B. Ahead moderate speed." << endl;
        cout << "C. Ahead full speed." << endl;
        cout << "D. Stop and rest." << endl;
        cout << "E. Status check." << endl;
        cout << "Q. Quit." << endl;
        cout << "Your choice? ";

        char choice = ' ';
        cin >> choice;

        cout << endl << endl; // user enters his choice

        // Call toupper() function to be sure that is input an upper case leter.
        // Douing that we make input case insensitive.
        // In <if> condition we check with upper case.
        choice = toupper(choice);

        if (choice == 'Q')
        {
            done = true;
        }
        else if (choice == 'E')
        {
            cout << "Miles traveled: " << milesTraveled << endl;
            cout << "Drinks in canteen: " << remainingDrinks << endl;

            int distance = 0;
            if (nativesMilesTraveled < 0)
            {
                distance = milesTraveled + nativesMilesTraveled;
            }
            else {
                distance = milesTraveled - nativesMilesTraveled;
            }

            cout << "The natives are " << distance << " miles behind you." << endl;
        }
        else if (choice == 'D')
        {
            camelTiredness = 0;

            cout << "Camel is happy!" << endl;

            nativesMilesTraveled += 7 + (rand() % 7); // Add random number from 7 to 14 natives.
        }
        else if (choice == 'C')
        {
            int miles = 10 + (rand() % 10); // Get random number from 10 to 20.
            milesTraveled += miles;
            traveled = true;

            cout << "You traveled " << miles << " miles." << endl;

            thirst++;
            camelTiredness += 1 + (rand() % 3); // Add random number from 1 to 3 to camel tiredness.
            nativesMilesTraveled += 7 + (rand() % 7); // Add random number from 7 to 14 to natives.
        } 
        else if (choice == 'B')
        {
            int miles = 5 + (rand() % 8); // Get random number from 5 to 12.
            milesTraveled += miles;
            traveled = true;

            cout << "You traveled " << miles << " miles." << endl;

            thirst++;
            camelTiredness++;
            nativesMilesTraveled += 7 + (rand() % 7); // Add random number from 7 to 14 to natives.
        }
        else if (choice == 'A')
        {
            if (remainingDrinks <= 0)
            {
                perror("ERROR: No drinks available.\n");
            }
            else
            {
                remainingDrinks--;
                cout << "Remaining drinks: " << remainingDrinks << endl;
                thirst = 0;
            }
        }

        // Variable <done> can be changed, so we will check its value.
        if (!done) {

            int distance = 0;

            if (nativesMilesTraveled < 0)
            {
                distance = milesTraveled + nativesMilesTraveled;
            }
            else {
                distance = milesTraveled - nativesMilesTraveled;
            }

            if (abs(distance) <= 0 || milesTraveled <= nativesMilesTraveled)
            {
                cout << "Natives caught the player. Game over!" << endl;
                done = true;
            }
            else if (abs(distance) < 15)
            {
                cout << "The natives are getting close!" << endl;
            }
        }

        // Variable <done> can be changed, so we will check its value.
        if (!done)
        {
            // Check player Trstiness
            if (thirst > 4 && thirst < 7)
            {
                cout << "You are thirsty." << endl;
            }
            else if (thirst > 6) {
                cout << "You are dead." << endl;
                done = true;
            }
        }

        // Variable <done> can be changed, so we will check its value and
        // Check camel tiredness.
        if (!done)
        {
            if (camelTiredness > 5 && camelTiredness < 9)
            {
                cout << "Your camel is getting tired." << endl;
            }
            else if (camelTiredness > 8)
            {
                cout << "Your camel is dead." << endl;
                done = true;
            }
        }

        // Variable <done> can be changed, so we will check its value and
        // check that traveled distance is 200 or more miles
        if (!done && milesTraveled >= 200)
        {
            cout << "Nice, You won!" << endl;
            done = true;
        }

        // Variable <done> can be changed, so we will check its value and value of traveled.
        if (!done && traveled)
        {
            int oasis = 5; // It can be any number from 1 to 20
            int hit = 1 + (rand() % 20);

            if (oasis == hit)
            {
                cout << "Supprise, we found oasis!" << endl;

                remainingDrinks = 3;
                thirst = 3;
                camelTiredness = 0;
            }
        }

        cout << endl;

    } while (!done);

    return 1;
}