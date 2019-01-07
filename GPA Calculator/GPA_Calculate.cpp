/*
  Author: Robin Nguyen
  Date Posted: 1/7/2019
  Purpose: To compute the gpa of the user. This program utilizes arrays
  and object oriented concepts to execute this operation.
*/
#include<iostream>
#include<string>
#include"GPA.h"
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<fstream>
using namespace std;

int main() {
	int count = 0;
	int temp = 0;
	int tempUnit = 0;
	int gradeArray[100];
	int unitArray[100];
	double gpaArray[100];
	double cumGpa[100];
	double cumUnits[100];
	int gradePoint = 0;
	int unit = 0;
	double gpaCumulative = 0;
	double cumU = 0;
	double cumGP = 0;
	int semesterCount = 0;
	int x = 0;
	int z = 0;
	bool checker = false;
	string semesterArray[100];
	string semester;
	GPA g("Spring", 5, 'A');
	ofstream gpaReport("GPA Report.txt");	//Outstream.

	if (gpaReport.is_open()) {
		cout << "File is open." << endl;
	}
	else {
		cout << "Uh oh, file is not open." << endl;
	}
	cout << "For how many semesters would you like to compute" << endl;
	cout << "your GPA for?" << endl;
	do {
		cout << "Semester count: ";
		cin >> semesterCount;

		checker = cin.fail();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (checker == true);
	cout << "------------------------------------------------";
	cout << endl;
	
	for (int k = 0; k < semesterCount; k++) {
		g.setSemester("");
		g.setClassCount(0);
		for (int i = 0; i < g.getClassCount(); i++) {
			g.setUnits(i, 0);			//Sets Units for class.	
			unitArray[i] = g.getUnits();
			g.setGrade(i, 'A');			//Sets grade for class.
			gradeArray[i] = ((g.getUnits())*(g.getGrade()));//stores values of (unit*grade) points into array.
		}

		temp = 0;		//reinitializes temp to 0 for next semester.
		tempUnit = 0;	//reinitializes tempUnit to 0 for next semester.

		for (int j = 0; j < g.getClassCount(); j++) {
			temp = temp + gradeArray[j];
			tempUnit = tempUnit + unitArray[j];
		}
		g.setGPA(temp, tempUnit);
		cumGpa[z] = g.getCumGPA();
		cumUnits[z] = g.getCumUnits();
		z++;	//increment z for cumulative GPA and cumulative Units array.
		semesterArray[x] = g.getSemester(); //Stores semesters into an array.
		gpaArray[x] = g.getGPA();			//Stores GPA into an array.
		//gpaReport << semesterArray[x] << ":\n";
		//gpaReport << "GPA: " << fixed << showpoint << setprecision(2) << gpaArray[x] << endl;
		x++; //increment x for GPA array.
	}
	for (int h = 0; h < z; h++) {
		cumGP += cumGpa[h];
		cumU += cumUnits[h];
	}
	gpaCumulative = (cumGP / cumU);
	g.setCGpa(gpaCumulative);
	gpaReport.close();
	
	
	system("pause");
	return 0;
}
