#include <iostream>
#include<ctime>
#include <cmath>
#include<cstdlib>
#include<stdio.h>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

vector<int> randomGenerator()
{
    vector<int>generated;
    srand(time(NULL));
    int x1,x2,x3,x4;
    x1 = rand()%10;

    do
    {
        x2 = rand()%10;
    }
    while(x2 == x1);

    do
    {
        x3 = rand()%10;
    }
    while(x3==x1 || x3==x2);

    do
    {
        x4= rand()%10;
    }
    while(x4==x1 || x4==x2 ||x4==x3);

    generated.push_back(x1);
    generated.push_back(x2);
    generated.push_back(x3);
    generated.push_back(x4);

    return generated;
}

int main()
{
    vector<int>a = randomGenerator();//call from the function.
    vector<int>b; //user vector
    int userInput;
    int count =0;
    int minutes;
    int seconds;
    int a1,a2,a3,a4;

    auto start = steady_clock::now();
    srand(time(NULL));
    while(true){
        count++;
        b.clear();// to clear the vector after each round.
       int cow = 0;
       int bull = 0;

    cout<<"Enter a 4 digit number(unique digits): ";
    cin>>userInput;
    a1= userInput/1000;
    a2 = (userInput-a1*1000)/100;
    a3 = (userInput-a1*1000-a2*100)/10;
    a4 = (userInput-a1*1000-a2*100-a3*10);
    b.push_back(a1);
    b.push_back(a2);
    b.push_back(a3);
    b.push_back(a4);

    for(int i=0;i<4;i++){
        if(b[i]==a[i])
            bull++;
        else{
            for(int j=0;j<4;j++)
            {
                if(b[i]==a[j])
                    cow++;
            }
        }//end of else statement.
    }//end of for loop.

    cout<<"Bulls = "<<bull<<" and cows = "<<cow<<endl;

        if(bull==4){
            auto end = steady_clock::now() ;
            int timeSpendsec = duration_cast<seconds>(end-start).count();
            minutes = timeSpendsec/60;
            seconds = timeSpendsec%60;
            cout<<"You guessed it in "<<count<<" tries, taking "<<minutes<<" minutes and "<<seconds<<" seconds"<<endl;
            break;
        }//end of if statement.
    }//end of while loop.

    return 0;
}


