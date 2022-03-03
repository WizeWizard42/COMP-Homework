/*
*   Write a program that finds word differences between two sentences.
*   The input begins with an integer indicating the number of words in each sentence.
*   The next input line is the first sentence and the following input line is the second sentence.
*   Assume that the two sentences have the same number of words and no more than 20 words each.
*   The program displays word pairs that differ between the two sentences. One pair is displayed per line.
*   Add a function named ReadSentences to read the input sentences into two string vectors. 
*/
#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std; // Required for assignment's test harness

void ReadSentences(vector<string>& sentence1Words, vector<string>& sentence2Words, int wordCount);

int main() {
    vector<string> firstSentence(20);
    vector<string> secondSentence(20);
    int wordCount;
   
    cin >> wordCount;
    
    ReadSentences(firstSentence, secondSentence, wordCount);
   
    for (int i = 0; i < wordCount; i++)
    {
        if (firstSentence.at(i) != secondSentence.at(i))
        {
            cout << firstSentence.at(i) << " " << secondSentence.at(i) << endl;
        }
    }

    return 0;
}

void ReadSentences(vector<string>& sentence1Words, vector<string>& sentence2Words, int wordCount)
{
    for (int i = 0; i < wordCount; i++)
    {
        cin >> sentence1Words.at(i);
    }
    for (int i = 0; i < wordCount; i++)
    {
        cin >> sentence2Words.at(i);
    }
    return;
}
