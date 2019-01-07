#include<iostream>
#include<string>
#include"GPA.h"
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<sstream>
#include<fstream>
#include<iomanip>
using namespace std;

extern bool checker = false;
ofstream gpaReport("GPA Report.txt");

GPA::GPA(string S, int U, char G) {		//Constructor. Initializes values of 
	semester = S;						//semester, units, and grade.
	units = U;
	grade = G;
}
void GPA::setClassCount(int C) {
	do {
	
		cout << "How many classes did you take this semester?: ";
		cin >> C;

		checker = cin.fail();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (checker == true || (C < 1) || (C > 10));
		count = C;
		gpaReport << "Classes taken : " << count << "\n";
}

void GPA::setSemester(string S) {
	do {
		cout << "Semester: ";
		//getline(cin, S);
		cin >> S;


		checker = cin.fail();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}while (checker == true);
	semester = S;
	gpaReport << "Semester(No spaces) : " << semester << "\n";
}

void GPA::setUnits(int C, int U) {
	do {
		cout << "Units for class " << C + 1 << ": ";
		cin >> U;
		checker = cin.fail();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}while (checker == true || (U < 1) || (U > 9));
	units = U;
}

void GPA::setGrade(int C,char G) {
	stringstream ss;
	string s;
	do {
		cout << "Grade: ";
		cin >> G;
		ss << G;
		ss >> s;
	} while (isdigit(G));
	grade = toupper(G);
	gpaReport << units << " unit class:  " << grade << "\n";

	if (toupper(grade) == 'A') {
		gradeNum = 4;
	}
	if (toupper(grade) == 'B') {
		gradeNum = 3;
	}
	if (toupper(grade) == 'C') {
		gradeNum = 2;
	}
	if (toupper(grade) == 'D') {
		gradeNum = 1;
	}
	if (toupper(grade) == 'F') {
		gradeNum = 0;
	}

	gradeArray[x];
	x++;
	if (x == units) {
		x = 0;
	}
}
void GPA::setGPA(int G, int U) {
	gradePoints = (G);
	totalUnits = (U);
	Gpa = (gradePoints / totalUnits);
	gpaReport << "Semester GPA : " << fixed << showpoint << setprecision(2) << Gpa << "\n" << endl;
}
void GPA::setCGpa(double C) {
	cGpa = C;
	gpaReport << "Cumulative GPA : " << fixed << showpoint << setprecision(2) << cGpa << "\n";
	if (cGpa >= 3.5) {
		gpaReport << endl;
		gpaReport << "Good job on achieving a 3.5 or higher!" << endl;
	}
	else if (cGpa < 3.5){
		gpaReport << endl;
		gpaReport << "Better luck next time on achieving higher than a 3.5!" << endl;
	}
}
char GPA::getGrade() {
	return gradeNum;
}
double GPA::getGPA() {
	return Gpa;
}
int GPA::getClassCount() {
	return count;
}
int GPA::getUnits() {
	return units;
}
string GPA::getSemester() {
	return semester;
}
double GPA::getCumGPA() {
	return gradePoints;
}
double GPA::getCumUnits() {
	return totalUnits;
}
