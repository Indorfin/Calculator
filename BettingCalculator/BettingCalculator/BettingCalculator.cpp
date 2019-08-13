// BettingCalculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

double pickWeightOne = 3.25;
double pickWeightTwo = 1.8;
unsigned long long int tempOne = 0;
unsigned long long int tempTwo = 0;
int picks = 0;
double picksMultiplier = 0;
int oddsOne = 0;
int oddsTwo = 0;
int oddsThree = 0;
int oddsFour = 0;
int realOdds = 0;
unsigned long long int diffOne = 0;
unsigned long long int diffTwo = 0;
unsigned long long int diffThree = 0;
unsigned long long int diffFour = 0;
double diffWeightOne = 4;
double diffWeightTwo = 4;
unsigned long long scaleOne = 50000000;
unsigned long long scaleTwo = 15000000;
unsigned long long int betOne = 0;
unsigned long long int betTwo = 0;
unsigned long long int betThree = 0;
unsigned long long int totalBet = 0;
unsigned long long int betFour = 0;
unsigned long long int trueTotalBet = 0;
int thresholdOne = 50;
int thresholdTwo = 100;
int thresholdThree = 150;
int thresholdFour = 200;
int thresholdFive = 250;
int oneWeight = 2;
int twoWeight = 5;
int threeWeight = 10;
int fourWeight = 20;
int fiveWeight = 30;
string input;

// differential^differential weight * picks^picks weight

int main()
{
	do
	{
		cout << endl << endl << "Enter the fighter's actual odds: ";
		cin >> realOdds;
		cout << endl << endl << "Enter their Good Bet odds: ";
		cin >> oddsThree;
		cout << endl << endl << "Enter their Safe Bet odds: ";
		cin >> oddsTwo;
		cout << endl << endl << "Enter the New Algorithm odds: ";
		cin >> oddsOne;
		cout << endl << endl << "Enter their True odds: ";
		cin >> oddsFour;

		cout << endl << endl << "Enter the number of picks: ";
		cin >> picks;

		// diffOne = pow((realOdds - oddsOne), diffWeightOne);
		// diffTwo = pow((realOdds - oddsTwo), diffWeightTwo);
		if (realOdds < oddsOne) diffOne = 0;
		else diffOne = realOdds - oddsOne;
		if (realOdds < oddsTwo) diffTwo = 0;
		else diffTwo = realOdds - oddsTwo;
		if (realOdds < oddsThree) diffThree = 0;
		else diffThree = realOdds - oddsThree;
		if (realOdds < oddsFour) diffFour = 0;
		else diffFour = realOdds - oddsFour;
		if (picks == 1) picksMultiplier = .0025; // was .05
		else if (picks == 2) picksMultiplier = .02; // was .15
		else if (picks == 3) picksMultiplier = .1; // was .3
		else if (picks == 4) picksMultiplier = .2; // was .4	
		else picksMultiplier = .3 + (picks * .05);
		//picksMultiplier = .4 + (picks * .05);

		

		if (diffOne < thresholdOne)
			betOne = diffOne;
		else if (diffOne < thresholdTwo)
			betOne = thresholdOne + ((diffOne - thresholdOne) * oneWeight);
		else if (diffOne < thresholdThree)
			betOne = thresholdOne + ((thresholdTwo - thresholdOne) * oneWeight) + ((diffOne - thresholdTwo) * twoWeight);
		else if (diffOne < thresholdFour)
			betOne = thresholdOne + ((thresholdTwo - thresholdOne) * oneWeight) + ((thresholdThree - thresholdTwo) * twoWeight) + ((diffOne - thresholdThree) * threeWeight);
		else if (diffOne < thresholdFive)
			betOne = thresholdOne + ((thresholdTwo - thresholdOne) * oneWeight) + ((thresholdThree - thresholdTwo) * twoWeight) + ((thresholdFour - thresholdThree) * threeWeight) + ((diffOne - thresholdFour) * fourWeight);
		else
			betOne = thresholdOne + ((thresholdTwo - thresholdOne) * oneWeight) + ((thresholdThree - thresholdTwo) * twoWeight) + ((thresholdFour - thresholdThree) * threeWeight) + ((thresholdFive - thresholdFour) * fourWeight) + ((diffOne - thresholdFive) * fiveWeight);

		if (diffTwo < thresholdOne)
			betTwo = diffTwo;
		else if (diffTwo < thresholdTwo)
			betTwo = thresholdOne + ((diffTwo - thresholdOne) * oneWeight);
		else if (diffTwo < thresholdThree)
			betTwo = thresholdOne + ((thresholdTwo - thresholdOne) * oneWeight) + ((diffTwo - thresholdTwo) * twoWeight);
		else if (diffTwo < thresholdFour)
			betTwo = thresholdOne + ((thresholdTwo - thresholdOne) * oneWeight) + ((thresholdThree - thresholdTwo) * twoWeight) + ((diffTwo - thresholdThree) * threeWeight);
		else if (diffTwo < thresholdFive)
			betTwo = thresholdOne + ((thresholdTwo - thresholdOne) * oneWeight) + ((thresholdThree - thresholdTwo) * twoWeight) + ((thresholdFour - thresholdThree) * threeWeight) + ((diffTwo - thresholdFour) * fourWeight);
		else
			betTwo = thresholdOne + ((thresholdTwo - thresholdOne) * oneWeight) + ((thresholdThree - thresholdTwo) * twoWeight) + ((thresholdFour - thresholdThree) * threeWeight) + ((thresholdFive - thresholdFour) * fourWeight) + ((diffTwo - thresholdFive) * fiveWeight);


		if (diffThree < thresholdOne)
			betThree = diffThree;
		else if (diffThree < thresholdTwo)
			betThree = thresholdOne + ((diffThree - thresholdOne) * oneWeight);
		else if (diffThree < thresholdThree)
			betThree = thresholdOne + ((thresholdTwo - thresholdOne) * oneWeight) + ((diffThree - thresholdTwo) * twoWeight);
		else if (diffThree < thresholdFour)
			betThree = thresholdOne + ((thresholdTwo - thresholdOne) * oneWeight) + ((thresholdThree - thresholdTwo) * twoWeight) + ((diffThree - thresholdThree) * threeWeight);
		else if (diffThree < thresholdFive)
			betThree = thresholdOne + ((thresholdTwo - thresholdOne) * oneWeight) + ((thresholdThree - thresholdTwo) * twoWeight) + ((thresholdFour - thresholdThree) * threeWeight) + ((diffThree - thresholdFour) * fourWeight);
		else
			betThree = thresholdOne + ((thresholdTwo - thresholdOne) * oneWeight) + ((thresholdThree - thresholdTwo) * twoWeight) + ((thresholdFour - thresholdThree) * threeWeight) + ((thresholdFive - thresholdFour) * fourWeight) + ((diffThree - thresholdFive) * fiveWeight);

		if (diffFour < thresholdOne)
			betFour = diffFour;
		else if (diffFour < thresholdTwo)
			betFour = thresholdOne + ((diffFour - thresholdOne) * oneWeight);
		else if (diffFour < thresholdThree)
			betFour = thresholdOne + ((thresholdTwo - thresholdOne) * oneWeight) + ((diffFour - thresholdTwo) * twoWeight);
		else if (diffFour < thresholdFour)
			betFour = thresholdOne + ((thresholdTwo - thresholdOne) * oneWeight) + ((thresholdThree - thresholdTwo) * twoWeight) + ((diffFour - thresholdThree) * threeWeight);
		else if (diffFour < thresholdFive)
			betFour = thresholdOne + ((thresholdTwo - thresholdOne) * oneWeight) + ((thresholdThree - thresholdTwo) * twoWeight) + ((thresholdFour - thresholdThree) * threeWeight) + ((diffFour - thresholdFour) * fourWeight);
		else
			betFour = thresholdOne + ((thresholdTwo - thresholdOne) * oneWeight) + ((thresholdThree - thresholdTwo) * twoWeight) + ((thresholdFour - thresholdThree) * threeWeight) + ((thresholdFive - thresholdFour) * fourWeight) + ((diffFour - thresholdFive) * fiveWeight);


		betTwo *= 2;

		betThree *= .3;


		totalBet = (betOne + betTwo + betThree) * picksMultiplier;
		trueTotalBet = (totalBet + betFour) * .7;

		cout << endl << endl << "Your bet: " << endl
			<< "\t$" << totalBet / 100 << "." << totalBet % 100 << endl
			<< "YOUR TRUE BET: $"<< trueTotalBet / 100 << "." << trueTotalBet % 100 << endl
			<< "(" << betOne << " + " << betTwo << " + " << betThree << " + " << betFour << ")" << endl << endl
			<< "Again? ";

		cin >> input;
	} while (input == "+");
    return 0;
}

