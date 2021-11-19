#include<iostream>
#include<ctime>
#include<algorithm>
#include<random>

using namespace std;

int random_gen(int a, int b)
{
    random_device rd;//Will be used to obtain a seed for the random number engine
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(a, b);
    return dist(mt);
}

int main()
{
    int number, guess;
    int tries = 1;
    int low = 1, high = 100;
    cout << "Determine a number between 1 and 100 : ";
    cin >> number;

    guess = random_gen(low, high);
    while(guess != number)
    {

        if (tries > 4) {
            cout << "YOU LOST! You ran out of guesses" << endl;
            break;
        }

        if(number == guess)
        {
            cout << "Congratulations...You guessed the number in " << tries << " attempts." << endl;           
        }
        else if(guess > number)
        {
            cout << "The number is less than " << guess << endl;
            high = guess - 1;
        }
        else{
            cout << "The number is higher than " << guess << endl;
            low = guess + 1;
        }
        tries++;
        guess = random_gen(low, high);
    }

    return 0;
}