//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Name: Eddie G. Pineda											        //
//Date: 10/21/2022												//								   //
//Program Statement: Create a program that uses a dynamic array to store as many names and test    		//
//					 scores as inputted by the user. Sort the array, calculate the average,	//
//					 and then display the sorted array and average to the user.		//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct nameScore //Struct used for the name-score pairs
{
	string studentName; //Name
	double testScore; //Score
};

/////////////////////////// User defined functions ///////////////////////////////////////////////////////////////
double averageScore(nameScore* arr,int arrNum); //Calculates and returns the average of the input array
void sortArr(nameScore* arr, int arrNum); //Sorts the input array with a selection sort algorithm

int main() {
/////////////////////////// Setting Variables ////////////////////////////////////////////////////////////////////
	int listNum; //int variable created to store number of user-defined test scores
	cout << "Enter the number of scores: "; //Asks user to enter the number of test scores
	cin >> listNum; //Stores number of test scores
	nameScore* listArr = new nameScore[listNum]; //Allocates memory and creates listArr to store the test scores
	double scoreAvg = 0; //Stores the average of the array

/////////////////////////// Inputs of the program  ///////////////////////////////////////////////////////////////
	for (int i = 0; i < listNum; i++) { //For loop designed to store all user-defined test scores
		cout << i+1 << ". Enter the student name: ";
		cin.ignore(); //Ignores until first user input line
		getline(cin, (listArr + i)->studentName); //Getline stores the name in the struct array
		cout  << "Enter the test score: ";
		cin >> (listArr + i)->testScore; //Stores the score in the struct array
		while ((listArr + i)->testScore < 0) //While loop checks if the recently added score is negative
		{
			cout  << "The test score cannot be negative. Please re-enter the score: ";
			cin >> (listArr + i)->testScore; //Stores the score input
		}
	}
	
/////////////////////////// Outputs of the program  //////////////////////////////////////////////////////////////
	cout << endl << "Sorted List:" << endl;
	sortArr(listArr, listNum); //Uses the sortArr function to sort the array
	for (int i = 0; i < listNum; i++) { //For loop designed to store all user-defined test scores
		cout << i+1 << ". " << (listArr + i)->studentName << ": " << (listArr + i)->testScore << endl; //Prints the sorted name-score pairs in ascending order
	}
	scoreAvg = averageScore(listArr, listNum); //Calls averageScore function to calculate and store the average of the array
	cout << setprecision(4) << "Average Score: " << endl << scoreAvg << endl; //Prints the average score
	
	delete[] listArr; //Deletes the dynamically allocated array listArr
	listArr = 0;
	return 0;
}

/////////////////////////// Function definitions  ////////////////////////////////////////////////////////////////
double averageScore(nameScore* arr, int arrNum) { //Calculates and returns the average of the input array
	double arrTotal = 0; //Temporary double used to store the sum of all elements within the array

	for (int j = 0; j < arrNum; j++) //For loop used to parse through every element in the array
	{
		arrTotal += (arr + j)->testScore; //Current element in the array is added to arrTotal
	}

	return (arrTotal/arrNum); //Returns the total sum divided by the number of elements in the array
}

void sortArr(nameScore* arr, int arrNum) { //Sorts the input array using a selection sort algorithm
	nameScore* tempVal = new nameScore; //Temporary variable used to swap values
	int minIndex; //Variable to store the index of the smaller number
	for (int i = 0; i < arrNum; i++) { //For loop parses through every value in the array
		minIndex = i; //Sets minimum index to i
		*tempVal = arr[i]; //Sets the temporary variable equal to the current smallest index value
		for (int j = i + 1; j < arrNum; j++) { //For loop parses through the remaining values

			if ((arr + j)->testScore < tempVal->testScore) //If statement compares the min index in the first for loop and the current index in the second for loop
			{
				minIndex = j; //Set the new minIndex to current index in the second for loop
				*tempVal = arr[j]; //Set the temporary variable to the new smaller value
			}
		}

		arr[minIndex] = arr[i]; //Swap the values for the current index and the smaller index
		arr[i] = *tempVal; //Swap the values for the current index with the temporary value
	}
}

