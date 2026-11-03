#include <iostream>
#include <iomanip>
//#include "PassFailActivity.h"
#include "PassFailExam.h"

using namespace std;

// Function prototype
void displayGrade(const GradedActivity&);   // Pass by reference
void displayGrade(const GradedActivity*);   // Pass by pointer

void displayMenu();

int main()
{

    // Create test objects
    PassFailActivity test(70);
    GradedActivity test1(88.0);
    PassFailExam test2(100, 25, 70.0);

    // Constant for the size of an array.
    const int NUM_TESTS = 4;

    // tests is an array of GradedActivity pointers.
    // Each element of tests is initialized with the
    // address of a dynamically allocated object.
    GradedActivity* tests[NUM_TESTS] =
    { new GradedActivity(88.0),
      new PassFailExam(100, 25, 70.0),
      new GradedActivity(67.0),
      new PassFailExam(50, 12, 60.0)
    };

    int choice;

    displayMenu();
    cin >> choice;

    switch (choice){
        case 1:
            // Use the PassFailActivity object (test). Minimum passing score is 70.
            // Set the score to 72. 
            test.setScore(72);

            // Display the object's grade data. The letter grade
            // should be 'P'. What will be displayed?
            displayGrade(test);
            break;
        case 2:
            // Display the GradedActivity object (test1). The score is 88.
            // then, display  the PassFailExam object (test2). 
            // There are 100 questions, the student missed 25 of them, 
            // and the minimum passing score is 70.

            cout << "Test 1:\n";
            displayGrade(test1);    // GradedActivity object
            cout << "\nTest 2:\n";
            displayGrade(test2);    // PassFailExam object
            break;
        case 3:
            // Display the GradedActivity object (test1). The score is 88.
            // then, display  the PassFailExam object (test2). 
            // There are 100 questions, the student missed 25 of them, 
            // and the minimum passing score is 70.

            cout << "Test 1:\n";
            displayGrade(&test1);  // Address of the GradedActivity object
            cout << "\nTest 2:\n";
            displayGrade(&test2);  // Address of the PassFailExam object
            break;
		case 4:
			// Display the grade data for each element in the tests array.
			for (int count = 0; count < NUM_TESTS; count++)
			{
				cout << "Test #" << (count + 1) << ":\n";
				displayGrade(tests[count]);
				cout << endl;
			}
			break;
    }
  
    return 0;
}

//***************************************************************
// The displayGrade function displays a GradedActivity object's *
// numeric score and letter grade.                              *
//***************************************************************

void displayGrade(const GradedActivity& activity)
{
    cout << setprecision(1) << fixed;
    cout << "The activity's numeric score is "
        << activity.getScore() << endl;
    cout << "The activity's letter grade is "
        << activity.getLetterGrade() << endl;
}

//***************************************************************
// The displayGrade function displays a GradedActivity object's *
// numeric score and letter grade. This version of the function *
// uses a GradedActivity pointer as its parameter.              *
//***************************************************************

void displayGrade(const GradedActivity *activity)
{
   cout << setprecision(1) << fixed;
   cout << "The activity's numeric score is "
        << activity->getScore() << endl;
   cout << "The activity's letter grade is "
        << activity->getLetterGrade() << endl;
}

void displayMenu()
{
	cout << "Menu:\n";
	cout << "1. Display Grade\n";
    cout << "2. Display graded activity grade and pass/fail grade (by reference)\n";
	cout << "3. Display graded activity grade and pass/fail grade (by pointer)\n";
    cout << "4. Display the grade data for each element in the tests array.\n";
	cout << "Enter your choice: ";
}