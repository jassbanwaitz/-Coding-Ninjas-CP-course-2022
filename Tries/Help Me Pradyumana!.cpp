/*
Pradyumn is tired of using auto - correct feature in his smartphone. He needs to correct his auto - correct more times than the auto - correct corrects him. Pradyumn is thinking to make his own app for mobile which will restrict auto - correct feature, instead it will provide auto - completion. Whenever Pradyumn types factorial, auto - correct changes it to fact. Pradyumn's App will show options such as fact, factorial, factory. Now, he can chose from any of these options. As Pradyumn is busy with his front - end work of his App. He asks you to help him. He said "You will be given set of words(words may repeat too but counted as one only). Now, as user starts the app, he will make queries(in lowercase letters only). So, you have to print all the words of dictionary which have the prefix same as given by user as input. And if no such words are available, add this word to your dictionary." As you know, Pradyumn want this app to be as smart as him :P So, implement a program for him such that he can release it on Fun Store.
Input Format:
Single integer N which denotes the size of words which are input as dictionary
N lines of input, where each line is a string of consisting lowercase letter
Single integer Q which denotes the number of queries.
Q number of lines describing the query string on each line given by user
Constraints:
1 ≤ N ≤ 30000
sum(len(string[i])) ≤ 2∗10^5
1 ≤ Q ≤ 10^3
Output Format:
If auto - completions exists, output all of them in lexicographical order else output "No suggestions" without quotes
Sample Input 1:
3
fact
factorial
factory
2
fact
pradyumn
Sample Output 1:
fact
factorial
factory
No suggestions
*/

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long int ll;

class trieNode{
    public:
        trieNode* store[26];
        bool isEndOfTrie;
        trieNode(){
            for(int i=0 ; i<26 ; i++) store[i] = NULL;
            isEndOfTrie = false;
        }
};

void insert(trieNode* root, string s) {
    trieNode* current = root;
    for(int i = 0 ; i < s.length() ; i++) {
        int idx = s[i] - 'a';
        if(current->store[idx] == NULL) {
            current->store[idx] = new trieNode();
        }
        current = current->store[idx];
    }
    current->isEndOfTrie = true;
}

void display(trieNode* head , string s) {
    if(head->isEndOfTrie) {
        cout  << s << endl;
    }
    for(int i=0 ; i<26 ; i++){
        if(head->store[i]){
            s.push_back(i + 'a');
            display(head->store[i], s);
            s.pop_back();
        }
    }
}

void query(trieNode* head , string s){
    trieNode* curr_node = head;
    for(int i=0 ; i<s.size() ; i++) {
        int index = s[i]-'a';
        if(curr_node->store[index]) {
            curr_node = curr_node->store[index];
        }
        else {
            cout << "No suggestions" << endl;
            insert(head,s);
            return;
        }
    }
    display(curr_node, s);
}

int main(int argc, char const *argv[])
{
    int n,q;
    string s;
    trieNode* head = new trieNode();
    cin >> n;
    while(n--){
        cin >> s;
        insert(head,s);
    }
    cin >> q;
    while(q--){
        cin >> s;
        query(head,s);
    }
    return 0;
}
