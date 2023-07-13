//pf final project first semester AUMC 2022
#include <iostream>
#include <Windows.h>
#include <iomanip>                              //for setw
#include <conio.h>                              //for getche()
using namespace std;


void dragon(float x, float y);                          //function for an obstacle
void witch(float x, float y);                           //function for an obstacle
void water(float x, float y);                           //function for an obstacle
float group(float x, float y, float temp);                  //function for winning
void dark(int cs, int aha, string name);            //function for limited steps
void plot(int cs, string name);                     //function for the plot

int main()
{

    string name;                                       //player's name

    cout << " Enter your Nombre: "; cin >> name;      system("CLS");

    char dir = 'a';
    float x = 0, y = 0, temp = 0;
        int cs = 500, aha = cs / 3;          //aha is used to store initial steps
    plot(cs, name);
    cout << "Type Enter to quit\n";
    cout << "\nPress direction key (w, s, d, a) " << endl;
    cout << "\nYour location is " << x << ", " << y << endl;
    
    while (dir != '\r')                         //until Enter is typed
    {
        
        dir = _getche();                  //get character echo
        system("CLS");                    //clearing screen
        plot(cs, name);                   //calling plot
        {
            if (dir == 'w')                        //go forward
                    y++;
            else if (dir == 's')                  //go down
                y--;
            else if (dir == 'd')                  //go right
                x++;  
            else if (dir == 'a')                  //go left
                x--;
            cs--;                                //minus one from steps
        }
        cout << "\nPress direction key (w, s, d, a) " << endl ;
        cout << "\nYour location is " << x << ", " << y << endl;
        //calling all obstacle and other functions
        dark(cs, aha, name);
        dragon(x, y);
        witch(x, y);
        water(x, y);
        temp = group(x, y, temp);
       
    }   //end while
    return 0;
}//end main


void plot(int cs, string name)
{
    cout << name << ", you have been seperated from your group. You only have your gps on you. Which only tells you your x and y co-ordinates. " << endl << " With a cave on your left, a deep forest on your right, and a stream behind you, 'the only way to move on, is to move forward' was your thought" << endl;

    cout << "Find your group before it gets dark." << endl << " You only have " << cs << " credit-steps to take in any direction. Use them wisely. " << endl;

}

void dragon(float x, float y)
{
    if ((11 / 5) * x - y <= -17)                                //wierd flex but, linear inequaltity
    {
        cout << endl << "beware the dragon in its cave!" << endl;
    }


    if ((22 / 10) * x - y <= -22)                               //linear inequality
    {
        cout << "\nYou were killed by the dragon\n";
        exit(0);
    }
}

void witch(float x, float y)
{
    if ((17 / 5) * x - y >= 17)                               //linear inequality
    {
        cout << endl << "beware the witch in forest!" << endl;

    }

    if ((22 / 10) * x - y >= 22)                               //linear inequality
    {
        cout << "\nYou were killed by the witch\n";
        exit(0);
    }
}

void water(float x, float y)
{
    if ((17 / 5) * x + y <= -17)                               //linear inequality
    {
        cout << endl << "tiny droplets of water are showering upon you; strong is the current of the stream!" << endl;
    }

    if ((22 / 10) * x + y <= -22)                               //linear inequality
    {
        cout << "\nyou sliped on a rock and fell into the water. You struggled against the flow but in vain. " << endl << " You drowned\n";
        exit(0);
    }
}


float group(float x, float y, float temp)
{
    float c = temp;
    float k = (x - 7) * (x - 7) + (y - 11) * (y - 11);
    
    if ((x - 7) * (x - 7) + (y - 11) * (y - 11) <= 10 * 10)                            //circular inequality
    {
            cout << endl << "you see smoke. Probably from campfire." << endl;
            if (k - c < 0) 
            {
                Sleep(100);
                cout << "you are getting warmer" << endl;
            }
       
            else if (k - c > 0)
            {
                Sleep(100);
                cout << " you are getting colder" << endl;
            }
    }
    
    if ((x - 7) * (x - 7) + (y - 11) * (y - 11) <= 2 * 2)                               //circular inequality
    {
        cout << "\nyou found your group\n";
        exit(0);
    }
    c = k;
    
    return c;
}

void dark(int cs, int aha , string name)
{
    if (cs <= aha)                                      //if steps left is less than aha
    {
        cout << "Hurry! You are running out of time." << endl;
    }


    if (cs == 0)                                    //if ran out of steps
    {
        cout << "You ran out of time! The sun set." << endl;
        cout << endl << "In the dark of the night, you were not even able to see what killed you." << endl << "You can only see your blood, formerly of your guts, shining in the moonlight...it looks almost black...its beautiful!" << endl;
        exit(0);
    }
}
