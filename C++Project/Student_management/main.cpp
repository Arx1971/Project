/** Adnan H Rahin
    Computer Science Dept,
    LaGuardia Community College, CUNY.
**/

#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <map>
#include <list>
#include <cstddef>
#include <cstdlib>
#include <cctype>
#include <iostream>
using namespace std;

#define INF_MAX 	2147483647
#define INF_MIN 	-2147483648
#define pb push_back
#define all(x) x.begin(),x.end()
#define distSqr(x1,y1,x2,y2) (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)
#define dist(x1,y1,x2,y2) sqrt(distSqr(x1,y1,x2,y2))
#define Set(x,v) memset(x,v,sizeof x)
#define For(i,s,e) for(i=s;i<=e;i++)
#define lb lower_bound
#define ub upper_bound
#define gcd(a,b) __gcd(a,b)
#define pi acos(-1)
#define mp make_pair
#define pos first
#define val second
#define error 1e-12
#define mod 1000000007
#define nl printf("\n")

typedef long long ll;

int N = 1000;

using namespace std;


class student_management
{

public:
    float marks;
    string name;
    student_management()
    {
    }
    student_management(string name,float marks)
    {
        this->name = name;
        this->marks = marks;
    }

    void output();
    char getgrade(float);

};

void student_management :: output()
{


    cout << name << "\t\t\t" << marks << "\t\t\t\t"<< getgrade(marks) << endl;
}

void massge(){
    cout << "NAME\t\t\tTotal Marks\t\t\tGrade" << endl;
    cout << "____\t\t\t___________\t\t\t_____" << endl;
}

char student_management :: getgrade(float sum)
{

    if(sum >=90)
        return 'A';
    else if(sum >=80 && sum <90)
        return 'B';
    else if(sum >=70 && sum <80)
        return 'C';
    else if(sum >=60 && sum <70)
        return 'D';
    else
        return 'F';

}

struct student
{

    string name;
    string coursenumber;
    float quiz1;
    float quiz2;
    float midterm;
    float finalexam;
    float project;
    float homework1;
    float homework2;
    float homework3;
    float homework4;
    float total;

};

int main()
{
    int n;
    student male[N];
    student_management pupil;
    cout << "Please Enter The Number of Student: ";
    cin >> n;

    float total[N],quiztotal[N],homework[N],mid_total[N],final_total[N],project_total[N];

    for(int i=0; i<n; i++)
    {
        cout << "Enter The Student Name: " ;
        cin >> male[i].name;
        cout << "Enter The Course Number:";
        cin >> male[i].coursenumber;
        cout << "Enter the Marks of Quiz 1:";
        cin >> male[i].quiz1;
        cout << "Enter the Marks of Quiz 2:";
        cin >> male[i].quiz2;
        cout << "Enter The Homework 1 Points: ";
        cin >> male[i].homework1;
        cout << "Enter The Homework 2 Points: ";
        cin >> male[i].homework2;
        cout << "Enter The Homework 3 Points: ";
        cin >> male[i].homework3;
        cout << "Enter The Homework 3 Points: ";
        cin >> male[i].homework4;
        cout << "Enter The Project Marks: ";
        cin >> male[i].project;
        cout << "Enter The MidTerm Exam Marks: ";
        cin >> male[i].midterm;
        cout << "Enter The Final Exam Marks: ";
        cin >> male[i].finalexam;
        cout << endl << endl;
    }

    for(int i=0; i<n ; i++)
    {

        float quiz = ((male[i].quiz1+male[i].quiz2)/2)*0.10;
        float homework = ((male[i].homework1+male[i].homework2+male[i].homework3+male[i].homework4)/4)*0.20;
        float pro = male[i].project*0.15;
        float fin = male[i].finalexam*0.30;
        float mid = male[i].midterm*0.25;

        male[i].total =  quiz+homework+pro+fin+mid;

    }
    massge();

    for(int i=0; i<n-1; i++){

        for(int j=0; j<n-1; j++){
            if(male[i].total>male[i+1].total){
                student temp;
                temp = male[i];
                male[i] = male[i+1];
                male[i+1] = temp;
            }
        }
    }

    for(int i=n-1; i>=0; i--)
    {

        pupil = student_management(male[i].name,male[i].total);

        pupil.output();
    }

    return 0;
}
