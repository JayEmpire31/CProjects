#include <iostream>
#include<ctime>
#include<cstdlib>
#include<stdio.h>
using namespace std;

int main()
{
	int dice1, dice2, dice3,dicesum; //The three dices
	int turn = 1;  // 1 is for user's turn, 0 means computer's turn;
	int round = 1;//for each round
	int userScore=0;  // The total sum of player's score. User begins with zero.
	int computerScore=0;// The total sum of computer's score. Computer begins with zero.
	char banking ='a';//Character holder

	srand(time(NULL));//To generate a random number.
while(true){
	if(userScore >= 150&&userScore>computerScore)
	     {//If the user meets the score of 150 or above keep on computing.
			 cout<<"User won."<<endl;
		     break;
		 }

	if(computerScore>=150&&userScore<computerScore)
		 {
			 cout<<"Computer won."<<endl;
			break;
		 }

	if((userScore>= 150&&computerScore>= 150)&&(userScore==computerScore)){
		cout<<"Tie."<<endl;
		break;
	}

	while(userScore<150 || turn==1){
		dice1= rand()%6+1;//First dice
		dice2= rand()%6+1;//Second dice
		dice3= rand()%6+1;//Third dice
		dicesum=dice1+dice2+dice3;

		cout<<"Rolled "<<dice1<<", "<<dice2<<", "<<dice3<<endl;

		if(dice1!=1 && dice2!=1 && dice3!=1){//If the three dice does not equal to 1, continue.
			cout<<"Sum = "<<dicesum<<endl;
					cout<<"Bank(y/n)? ";
					cin>>banking;
               if(banking=='y'){
					userScore= userScore + dicesum;
					cout<<"Computer's turn"<<endl;
					break;
               }

               else{//If the character is not yes, go through here
				while(!((banking=='y')||(banking=='n'))) {//Other characters will not be accepted(Will repeat bank(y/n)?. Note that the char n will bank again.
				    cout<<"Bank(y/n)?  ";
				    cin>>banking;
				}//end of while loop.
               }//end of else.
		}//end of first if loop.

		else if(dice1==1&&dice2==1&&dice3==1){
				cout<<"Lose all accumulated points and lose turn"<<endl;
				cout<<"Computer's turn"<<endl;
				userScore=0;
				turn = 0;
				break;
			}//end of else if loop.

		else if((dice1==1&&dice2==1)||(dice2==1&&dice3==1)||(dice1==1&&dice3==1)){
			userScore/=2;
		    cout<<"Two ones, lose half of holdings, and lose turn"<<endl;
		    cout<<"Computer's turn"<<endl;
		    turn = 0;
		    break;
		} //end of else if loop.

		else if(dice1==1||dice2==1||dice3==1){
			cout<<"Single one,lose turn"<<endl;
			cout<<endl;
			cout<<"Computer's turn"<<endl;
			turn = 0;
			break;
		}//end of if else loop
	}//end of user loop


	while(computerScore<150 || turn==0){
		  dice1= rand()%6+1;//First dice
	      dice2= rand()%6+1;//Second dice
		  dice3= rand()%6+1;//Third dice
		  dicesum=dice1+dice2+dice3;

		  cout<<"Rolled "<<dice1<<", "<<dice2<<", "<<dice3<<endl;

				if(dice1!=1 && dice2!=1 && dice3!=1){
					if(dicesum>=10){//If the sum is greater than or equal to 10, the computer will accept
					cout<<"Sum = "<<dicesum<<" bank"<<endl;
					computerScore= computerScore + dicesum;
					turn = 1;
					break;
					}

					else{//If the sum is less than or equal to 10, the computer will not accept.
                       cout<<"Sum = "<<dicesum<<" no bank"<<endl;
					}//End of nested for loop
					}//End of if loop

				else if(dice1==1&&dice2==1&&dice3==1) {
				 cout<<"Lose all accumulated points and lose turn"<<endl;
				 userScore=0;
				 turn = 1;
				 break;
							}//end of if else loop.

				else if((dice1==1&&dice2==1)||(dice2==1&&dice3==1)||(dice1==1&&dice3==1)){
					computerScore/=2;
				    cout<<"Two ones, lose half of holdings, and lose turn"<<endl;
				    turn = 1;
				    break;
				}//End of if else loop.

				else if(dice1==1||dice2==1||dice3==1){
					cout<<"Single one,lose turn"<<endl;
					turn = 1;
					break;
				}//end of if else loop.

	}//end of computer while loop
	cout<<"After round "<<round<<" human has "<<userScore<<" and computer has "<<computerScore<<endl;
	round++;
	cout<<endl;
}//End of while(true) loop.
	return 0;
}
