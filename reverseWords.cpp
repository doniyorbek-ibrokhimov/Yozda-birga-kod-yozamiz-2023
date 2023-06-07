#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<char> reverseWords(const vector<char> &arr) {
    stack<string> words;
    string word;
    bool isPushed = false;
    string freeSpaces;
    // your code goes here
    for (int i = 0; i < arr.size(); i++) {
        while (i < arr.size() and arr[i] == ' ') {
            if (!isPushed) {
                words.push(word);
                word = "";
                isPushed = true;
            }
            freeSpaces += ' ';
            i++;
        }
        isPushed = false;
        words.push(freeSpaces);
        freeSpaces = "";
        word += arr[i];

        if (i == arr.size() - 1) words.push(word);
    }

    vector<char> resultVector;

    while (words.size() != 0) {
        word = words.top();
        words.pop();
        for (int i = 0; i < word.size(); i++) {
            resultVector.push_back(word[i]);
        }
    }

    return resultVector;
}


int main() {

    vector<char> tempArr = {'p', 'e', 'r', 'f', 'e', 'c', 't', ' ',
                            'm', 'a', 'k', 'e', 's', ' ',
                            'p', 'r', 'a', 'c', 't', 'i', 'c', 'e'};
    
    vector<char> result = reverseWords(tempArr);
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}
