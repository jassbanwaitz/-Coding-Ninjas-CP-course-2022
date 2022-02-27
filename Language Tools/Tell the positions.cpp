/*
In a class there are ‘n’ number of students. They have three different subjects: Data Structures, Algorithm Design & Analysis and Operating Systems. Marks for each subject of all the students are provided to you. You have to tell the position of each student in the class. Print the names of each student according to their position in class. Tie is broken on the basis of their roll numbers. Between two students having same marks, the one with less roll number will have higher rank. The input is provided in order of roll number.
Input Format:
First line will have a single integer ‘n’, denoting the number of students in the class.
Next ‘n’ lines each will have one string denoting the name of student and three space separated integers m1, m2, m3 denoting the marks in three subjects.
Output Format:
Print ‘n’ lines having two values: First, the position of student in the class and second his name.
Constraints:
1 <= n <= 10^5
0 <= m1, m2, m3 <= 100
Sample Input:
3
Mohit 94 85 97
Shubham 93 91 94
Rishabh 95 81 99
Sample Output:
1 Shubham
2 Mohit
3 Rishabh
*/

#include <bits/stdc++.h>

using namespace std;

class student{
	public:
		string name;
		int marks;
		int roll;
};

bool mycompare(student a, student b){

	if (a.marks!=b.marks)
	{
		return (a.marks>b.marks);
	}else{
		return(a.roll<b.roll);
	}
	
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	int n;
	cin>>n;
	vector<student> stud;			
	for (int i = 0; i < n; ++i)
	{
		string temp_name;
		int sub1;
		int sub2;
		int sub3;
		cin>>temp_name>>sub1>>sub2>>sub3;

		int sum = sub1+sub2+sub3;

		student temp_sub;

		temp_sub.name = temp_name;
		temp_sub.marks = sum;
		temp_sub. roll = i+1;

		stud.push_back(temp_sub);
	}
	sort(stud.begin(), stud.end(), mycompare);

	for (int i = 0; i < n; ++i)
	{
		cout << i+1<<" "<<stud.at(i).name<<'\n';
		
	}
	return 0 ; 
}
