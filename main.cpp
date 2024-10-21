/*
KidBasket App v0.01
Began 10.21.24 7 AM Finished 12:47 PM
Programmer:Marlon J Peters
An app that will take in student names and store them in a file for later retrieval or removal
Useful for teachers but can be adjusted for any name storage use and can be easily adjusted within code
*/

#include <iostream> //standard library for input output
#include <fstream>  //for creating and reading from files
using namespace std;  //keeps me from having to constantly type std::

/*Function for appending a student to the file
this function needs to be above the others because it is called
last in order.  As such it MUST be first listed.  Notice the functions have been
placed outside of the main function.
*/
void AddAStudent()
	{
		ofstream StudRec;
		StudRec.open("STUDENTS.txt", ios::app);//ios::app added so the compiler knows this is an addition and not an overwrite
		char AnswerAppend;
		string StudentNameAppend;
		cout << "Student Name:";
		cin.ignore();//clears the cin cache...had trouble getting these functions to compile without this
		getline(cin, StudentNameAppend);
		StudRec << "Student Name:" << StudentNameAppend << "\n";
		cout << "Would you like to add another name?  Press Y and Enter if you do.  Otherwise press any other key and Enter to close program." << endl;
	AnswerAppend = getchar();
	//condition to ask the user to proceed or quit
	if(AnswerAppend == 'Y' || AnswerAppend == 'y')
	{
		AddAStudent();
	}
	else
	{
		cout << "Thank you for using this program!  You may now exit the program!";
	}
	}
	
//Initial function to get the initial student's name

void GetStudentName()
	{
	ofstream StudRec;
	StudRec.open("STUDENTS.txt",ios::app); //ios::app added so the compiler knows this is an addition and not an overwrite
	string StudentName;//string to collect name from input
	char Answer;
	cout << "Please Enter a student's name:";
	cin.ignore();//clears the cin cache...had trouble getting these functions to compile without this
	getline(cin, StudentName);//adds input to the string 'StudentName'
	StudRec << "Student Name:" << StudentName << "\n";//writes the input information to the STUDENTS.txt file
	//condition to ask the user to proceed or quit
	cout << "Would you like to add another name?  Press Y and Enter if you do.  Otherwise press any other key and Enter to close program." << endl;
	Answer = getchar();
	if(Answer == 'Y' || Answer == 'y')
	{
		AddAStudent();
	}
	else
	{
		cout << "Thank you for using this program!  You may now exit the program!";
	}
	
	}
	
	



void IntroFunction()
	{
	char SkipToMainFunction;
	SkipToMainFunction = getchar();//asks for input of Y or y...see below function
	switch (SkipToMainFunction)
		{
		case 'y':
		GetStudentName();
		break;
		case 'Y':
		GetStudentName();
		break;
		default:
		cout << "You did not press Y!";
		IntroFunction();
		}
		
	}



int main(){
	ofstream StudRec;
	StudRec.open("STUDENTS.txt");//open slash create the text file
	//Splash Screen harking back to the old days of DOS
const char *SplashScreen = R"""(

*******************************************
*                                         *
*                                         *
*                                         *
*                                         *
*                KidBasket                *
*                  V0.01                  *
*                Programmer:              *
*             Marlon J Peters             *
*         Press Y and then Enter          *
*               to continue               *
*                                         *
*                                         *
*                                         *
*                                         *
*                                         *
*                                         *
*                                         *
*                                         *
*******************************************
)""";


	 
	 
 

//output splash screen and start program!								 
cout << SplashScreen << endl;






IntroFunction();


	

StudRec.close();
return 0;

}