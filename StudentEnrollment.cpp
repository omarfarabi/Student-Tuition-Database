#include <iostream>
#include <fstream>
#include<string>
using namespace std;


void addStudent(string filename, int *studentCount, int *inStateFees, int *outStateFees){
cout<<endl<<" * Add Students Details";
getchar();
ofstream file(filename.c_str(), ios::app);
char name[50];
cout<<endl<<"\n Enter Name of Student : ";
gets(name);

file<<endl<<name;

int state=-1;
cout<<endl<<"\n Press 1 for Local or 2 for Foreign : ";
cin>>state;

if(state==1)
file<<" | In-State";
else if(state==2)
file<<" | Out-Of-State";
else
file<<" | NA";

int tutionFees;
cout<<endl<<"Enter Tuition Fees : ";
cin>>tutionFees;

char choice;
cout<<endl<<"Enter 'y' To Select The Hostel Package : ";
cin>>choice;

int healthPlan = 0;

if(choice=='Y' || choice=='y'){
char plan;
cout<<endl<<" # Select The Hostel Package #";
cout<<endl<<"W -> $40";
cout<<endl<<"X -> $160";
cout<<endl<<"Y -> $120";
cout<<endl<<"Z -> $200";

cout<<endl<<"Select any alphabet ( W, X, Y, Z ) : ";
cin>>plan;

switch(plan){
case 'W':
case 'w': healthPlan = 40;   break;
case 'X':
case 'x': healthPlan = 160; break;
case 'Y':
case 'y': healthPlan =  120; break;
case 'Z':
case 'z' : healthPlan =  200; break;
default: cout<<endl<<"Invalid Choice..";
}

if(healthPlan!=0)
file<<" | Health Plan : "<<plan;
else
file<<" | Health Plan : None"<<plan;

file<<" | "<<tutionFees;

if(state==1){
*inStateFees = *inStateFees + tutionFees + healthPlan;
}
else if(state==2){
*outStateFees = *outStateFees + tutionFees + healthPlan;
}

}
*studentCount = *studentCount + 1;
file.close();
}


void generateReport(const string filename, const int *studentCount, const int *inStateFees, const int *outStateFees){
if(*studentCount==0){
cout<<endl<<"Error: There should be atleast one record to generate the report.";
}
else{
ofstream file(filename.c_str(), ios::app);
file<<endl<<"Total Tuition Paid for all Local Students : "<<*inStateFees;
file<<endl<<"Total Tuition Paid for all Foreign Students : "<<*outStateFees;
file.close();
cout<<endl<<"Success: "<<filename<<" generated ";
}

}


int main(int argc, char** argv) {

int choice = 0;
string fileName = "tuition_report.txt";
int studentCount =0;
int inStateFees = 0;
int outStateFees =0;


ofstream file(fileName.c_str(), ios::out);
file.close();

while(choice!=-1){
cout<<endl<<"### Student Tuition ###"<<endl;
cout<<endl<<"1 Add Student Details";
cout<<endl<<"2 Generate Report";
cout<<endl<<"3 Exit";
cout<<"\n\n Enter your choice : ";
cin>>choice;

switch(choice){
case 1: addStudent(fileName, &studentCount, &inStateFees, &outStateFees);
	break;
case 2: generateReport(fileName, &studentCount, &inStateFees, &outStateFees);
	break;
case -1: cout<<endl<<"Thank You For Using This System!!";
	break;
default: cout<<endl<<"Invalid Choice.."; getchar();

}

}

return 0;
}
