#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;


class GPA {
public:
	GPA(string,int, char);
	void setClassCount(int);
	int getClassCount();
	void setSemester(string);
	string getSemester();
	void setUnits(int, int);
	int getUnits();
	void setGrade(int, char);
	char getGrade();
	void setGPA(int, int);
	double getGPA();
	double getCumGPA();
	double getCumUnits();
	void setCGpa(double);
	//double getCGpa();
	
	



private:
	char grade;
	int units;
	int year;
	int count;
	string semester;
	int gradeArray[100];
	int x;
	int gradeNum;
	double gradePoints;
	double totalUnits;
	double Gpa;
	double cGpa;
};
