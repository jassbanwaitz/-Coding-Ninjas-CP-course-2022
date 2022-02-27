/*
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
The numbers and their corresponding codes are given below:
0: ""
1: ""
2: "abc"
3: "def"
4: "ghi"
5: "jkl"
6: "mno"
7: "pqrs"
8: "tuv"
9: "wxyz"
Return empty string for numbers 0 and 1.
Note:
1. The order of strings are not important.
2. The input number will have digits between: [2, 9].
Input Format :
First line of input will contain T number of test cases.
Each input consists of a single line containing an integer n.
Output Format :
For each test case, print all possible strings in different lines.
Constraints :
1 <= T <= 100
1 <= n <= 10^6
Sample Input:
1
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/

#include <bits/stdc++.h>
using namespace std;
vector<string> keypadHelper(int num, vector<string> &options)
{
    if(num <= 1)
    {
        vector<string> output;
        output.push_back("");
        return output;
    }
    int lastDigit = num % 10;
    int smallNumber = num / 10;
    vector<string> smallOutput;
    vector<string> output;
    
    smallOutput = keypadHelper(smallNumber, options);
    string op = options[lastDigit];
    for(int i=0;i<op.length();i++)
    {
        for(int j=0;j<int(smallOutput.size()); j++)
        {
            output.push_back(smallOutput[j] + op[i]);
        }
    }
    return output;
}

vector<string> keypad(int num)
{
    vector<string> options = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> output;
    output = keypadHelper(num, options);
    return output;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> output = keypad(n);
        for(int i=0;i<int(output.size());i++)
        {
            cout<<output[i]<<endl;
        }
    }
}
