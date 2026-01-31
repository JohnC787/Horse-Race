#include <iostream>
#include <random>

using namespace std;

// Function declarations
void advance(int horseNum, int* horses);
void printLane(int horseNum, int* horses);
bool isWinner(int horseNum, int* horses);

const int NUM_HORSES = 5;
const int TRACK_LENGTH = 15;

int main()
{
    // Random number setup
    random_device rd;
    uniform_int_distribution<int> dist(0, 1);

    // Array that stores each horse's position
    int horses[NUM_HORSES] = {0, 0, 0, 0, 0};

    bool raceOver = false;

    cout << "Press ENTER to advance the race!\n";

    while (!raceOver)
    {
        cin.get();  // Wait for Enter key

        for (int i = 0; i < NUM_HORSES; i++)
        {
            int coin = dist(rd);

            if (coin == 1)
            {
                advance(i, horses);
            }

            printLane(i, horses);

            if (isWinner(i, horses))
            {
                raceOver = true;
            }
        }

        cout << endl;
    }

    cout << "Race finished!\n";

    return 0;
}
void advance(int horseNum, int* horses)
{
    horses[horseNum]++;
}
void printLane(int horseNum, int* horses)
{
    cout << horseNum << ": ";

    for (int i = 0; i < TRACK_LENGTH; i++)
    {
        if (i == horses[horseNum])
        {
            cout << "H";
        }
        else
        {
            cout << ".";
        }
    }

    cout << endl;
}
bool isWinner(int horseNum, int* horses)
{
    if (horses[horseNum] >= TRACK_LENGTH)
    {
        cout << "Horse " << horseNum << " wins!\n";
        return true;
    }

    return false;
}
