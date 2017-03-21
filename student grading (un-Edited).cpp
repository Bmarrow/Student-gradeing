// Student Grading system

//int i is used as a local variable alot to keep track of stuff

#include <iostream> // Mandatory
#include <fstream> // File I/O
#include <string> // Mandatory for strings

void getInfo(); // Function getInfo
void findAvg(); // Function findAvg
void giveGrade(); // Function giveGrade
void output(); // Function output

using namespace std; //Standard Namespace

//Declarations
float avg = 0;
int ID[200];
string name[200];
float score[200];
string grade[200];
signed int pk=-1; //PK is the incrementer
ofstream file;
string filename;

//Main
int main(void)
{
    //START OF PROGRAM
    system("color 0a"); // Changes system text to green/0a
    system("cls"); // Clears the screen
    // Introduction
    //Make it look good
    cout << "-------------------------------------------" << endl;
    cout << "|Welcome to my Student grading organizer!!|" << endl;
    cout << "-------------------------------------------" << endl << endl;
    // Notifies where file will be saved
    cout << "This program will create a file called 'Grades.txt'" << endl; 
    cout << "in the ORIGINAL folder it was placed in." << endl;
    system("pause"); // Give time to read
    // Calls getInfo
 getInfo ();
    // Calls findAvg 
 findAvg ();
    // Calls giveGrades
 giveGrade();
    // Calls output
 output();
 
 // This is for after output.. Notification of saving
 cout << "Saving file 'Grades.Txt'" << endl;
 // Give Time to Read
 system("Pause");
 //END OF PROGRAM
 return 0;
}

void getInfo() //Used to Gather information
{
     string more = "y"; //While More = True.... Loop
     int i = 0; //To ensure Score is actually integer
     
     while (more=="y")
     
     {     
           pk++; //Incremente
           ID[pk] = pk + 1; //ID Count = PK..
           system("cls");
           cin.sync(); // Clear buffer for each loop
           
           cout << "What is the name of the student? "; //Get name
           getline( cin, name[pk] ); //Put into name[pk]
           
           
           cout << "What is the score of the student? "; //Get score
           
           //Ensure that score is actually an integer
           while (!(cin >> i))
           {
		   cin.clear();
		   cin.ignore(1000,'\n');
		   //If not an integer, repeat until so
		   cout << "What is the score of the student (integer value's only): ";
           }
           score[pk] = i; //If so.. Put score in here
           

           cout << "Would you like to add another student? ";
           cin >> more; //Ask if they'd like to add another student
           
           while (more != "y" && more != "n")
           //While more is not y & not n
           {
                 cout << "(y or n) only please: ";
                 cin >> more;
           }
           /*If it's n... it goes back to main.. to continue next function
             Otherwise it will go back to the beginning of this function*/
           }
}

void findAvg() //Used to calculate the average
{
for (int i=0; i<pk + 1; i++) /* As long as i is less than pk
                                score[1], score[2], and so on
                                will be added to avg*/
{
avg = avg + score[i];
}
avg = avg / (pk + 1); /*To find the average.. 
                      Take the total number of scores (currently in avg)
                      and divide it by pk + 1 because pk starts at -1*/

cout << "Average = " << avg << "%" << endl; /*Display avg and add %
                                              so it looks professional*/
system("pause");    //Give user time to see average
}

void giveGrade()
{ 
 
 /*Standards are as follows
  A student within 5 points of the average gets a B
  A student with more than 5 points above the average gets an A
  A student with more than 5 and within 15 points below the average gets a C
  A student with more than 15 points below the average gets a D 
 */
 
  for(int i = 0; i < pk + 1;i++) //While i is less than pk.. do this
  {
        if (score[i] >= avg + 5) //Standards for an A
        {            //Greater than or = to the average + 5
        grade[i] = "A";
        }
        else if  (score[i] <= avg + 4 && score[i] >= avg - 4)
        {                  //Less than or = to +4 & greater than or = to -4
             grade[i] = "B"; //Standards for a B
             }
             else if (score[i] <= avg -5 && score[i] >= avg - 14)
             {
                  grade[i] = "C"; //Standards for a C
                  }
                  else if (score[i] < avg - 15)
                  {
                      grade[i] = "D"; //If none of the above apply.. Give D
                      }
                                        
  }
}

void output()
{
     //ofstream file declared above
     //Open a file called Grades.txt
     //If non-existant it will be created
     file.open("Grades.txt");
     //Display average in text file
     file << "The Average is: " << avg << "%" << endl << endl;
     
     //Local Variable i is used again
     //while i is less than pk put the array into the textfile
     //For example
     /*
     ID[1] Produces 1
     name[1] Produces Name that was put first
     score[1] Produces score that was put in first
     grade[1] Produces first grade calculated
     << ends the line
     the "" are to make it look neater
     */
     for(int i = 0; i < pk + 1;i++)
     {
     file << ID[i] << ", " << name[i] << ", " << score[i] << "%, " << grade[i] << endl;
     cout << ID[i] << ", " << name[i] << ", " << score[i] << "%, " << grade[i] << endl;
     }
     //Save and close the file.. Go Back to main
     file.close();
}