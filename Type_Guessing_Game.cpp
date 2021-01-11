#include <iostream>
#include<ctime>
#include<cstdlib>
#include<stdio.h>
#include<string>
#include <cctype>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main()
{
    int temp=0;
    int userScore = 2000;
    int penalty = 0;
    string userInput;
    string generated;

    srand(time(NULL));

    while(true){
        if(userScore >= 5000){
            break;
        }
        else if(userScore<=0){
            cout<<"Bye..."<<endl;
            break;
        }

    cout<<"Your current points "<<userScore<<",just type -> ";
    auto start = steady_clock::now() ;
    for (int i=0;i<5;i++){
        temp = rand()%10;

        if(temp <=3){
            generated= 'A'+ rand()%26;
            cout<<generated;
        }
        else if(temp>3&&temp<=7)
        {
            generated= 'a'+ rand()%26;
            cout<<generated;

        }
        else if(temp==8)
        {
            generated = '0' +random()%10;
            cout<<"[0-9]";
        }
        else
        {
         generated = '!' ;
            cout<<"[%-!]";
        }
    }//end of for loop
    cout<<endl;

    cin>>userInput;
    auto end = steady_clock::now() ;

    double timeSpend = duration_cast<milliseconds>(end-start).count();
    if(timeSpend<=10000&&userInput.length()!=generated.length()){
        cout<<timeSpend<<" milliseconds, you made it within the interval of 10000...";
        userScore= userScore+500;
        cout<<userScore<<endl;
    }
    else{
        cout<<timeSpend<<" milliseconds, you *failed* it within the interval of 10000..."<<endl;
        userScore =userScore -(timeSpend-10000);
    }

    if(!generated.compare(userInput)){
        userScore += 500;
        cout<<userScore;
    }
    else
    {
        if(userInput.length()==generated.length()){
            for(int i=0;i<userInput.length();i++)
            {
                penalty=abs(generated.at(i)-userInput.at(i));
                userScore= userScore - abs(generated.at(i)-userInput.at(i));
            }
            cout<<"String offset is "<<penalty<<", your total penalty is "<<penalty<<endl;
      }
        else if(userInput.length()<generated.length()){
            for(int i=userInput.length();i<generated.length();i++){
                penalty=abs(generated.at(i)-' ');
                userScore = userScore- abs(generated.at(i)-' ');
            }
            cout<<"String offset is "<<penalty<<", your total penalty is "<<penalty<<endl;
        }
        else{
            for(int i= generated.length();i<userInput.length();i++){
                penalty=abs(userInput.at(i)- ' ');
                userScore = userScore - abs(userInput.at(i)- ' ');
            }
            cout<<"String offset is "<<penalty<<", your total penalty is "<<penalty<<endl;
        }
    }
        for(int i=0;i<userInput.at(i);i++){
            for(int i=0;i<generated.at(i);i++){
            if(isdigit(userInput.at(i)))
        {
            if(isdigit(userInput.at(i))){
                cout<< "Your "<< i+1 << " character is correct\n.";

            }
            else
                cout<< "Your "<< i+1 << " character is wrong\n.";
        }

        else if (generated.at(i) =='!')
        {
            if((userInput.at(i)>=32 && userInput.at(i)<=47) || (userInput.at(i)>=58 && userInput.at(i)<=64)){
                cout<< "Your "<< i+1 << " character is correct\n.";

            }
            else
                cout<< "Your "<< i+1 << " character is wrong\n.";
        }

        else{
            if(generated.at(i)==userInput.at(i)){
                cout<< "Your "<< i+1 << " character is correct\n.";

            }
            else
                cout<< "Your "<< i+1 << " character is wrong\n.";
        }

        }
        }
    }
    return 0;
}




