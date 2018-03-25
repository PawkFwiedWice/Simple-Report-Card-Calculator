//Tim
//Feb 19 2018
//Code takes series of grades determined by user
//Prompts user for Total possible points and points earned
//outputs Average

#include <iostream>
using namespace std;

int main()
{
   //init
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   const int numGradesThreshold = 0;//numGrade > 0
   const int pointThreshold     = 0;//totalGradePoints > 0

   //input variables
   int       numGrades;             //Number of grades to input
   int       counter;               //counting variable for loop
   double    exerciseGrade;         //points earned for each exercise
   double    exerciseTotalPoints;   //point value of each exercise

   //output variables
   double    totalPoints;           //total number of earned points
   double    totalGradePoints;      //total value of all exercises
   double    avgTotalPoints;        //(total points / totalGradePoints) * 100

   //inputs
   cout << "How many exercises to input?: ";
   cin  >> numGrades;
   
   //numGrades data validation
   do
   {
      if (numGrades < numGradesThreshold)
      {
         cout << "Input error! Please enter an integer (0-100): ";
         cin  >> numGrades;
      }
      else if (numGrades == numGradesThreshold)
      {
         cout << "You have no grades to enter. Goodbye!" << endl;
         break;
      }
   } while (numGrades <= numGradesThreshold);

   //processing
   for (counter=0; counter < numGrades; counter++)
   {
      cout << "Score received for exercise "        << counter + 1 << ": ";
      cin  >> exerciseGrade;
      cout << "Total points possible for exercise " << counter + 1 << ": ";
      cin  >> exerciseTotalPoints;

      //exerciseTotalPoints data validation
      if (exerciseTotalPoints <= pointThreshold)
      {
         do
         {
            cout << "Input Error! Possible points must be greater than zero.\n"
                 << "Please try again: ";
            cin  >> exerciseTotalPoints;
         } while (exerciseTotalPoints <= pointThreshold);
      }

      //append to totals
      totalPoints      += exerciseGrade;
      totalGradePoints += exerciseTotalPoints;
   }

   avgTotalPoints = (totalPoints / totalGradePoints) * 100;
   
   //outputs
   cout << "\nYour total is "    << (int)totalPoints << " out of "
        << (int)totalGradePoints << ", or "          << avgTotalPoints
        << "%." << endl;

   return 0;
}
