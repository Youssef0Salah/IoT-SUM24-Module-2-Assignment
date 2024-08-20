#include <iostream>
#include <cmath>
#include <string>
using namespace std;


int countVowels(const char*ptr){
  int vowelCount=0;
    while (*ptr != '\0') {
        if (tolower(*ptr)=='a' || tolower(*ptr)=='e'|| tolower(*ptr)=='i'|| tolower(*ptr)=='o'|| tolower(*ptr)=='u') {
            vowelCount++;
        }
        ptr++; 
    }
    return vowelCount;
 };


int main() {
    cout << "Enter a word: ";
    string word;
    getline(cin, word);
    int numVowels = countVowels(word.c_str());
    cout << "The number of vowels in the string is: " << numVowels << endl;
  return 0;
}