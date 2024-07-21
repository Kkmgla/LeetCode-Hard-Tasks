#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        vector<string>output;
        bool isEnd = 0;
        int i = 0;

        while (!isEnd)
        {
            int j = 0;
            int conterOfWords = 0;
            int counterOfLengths = 0;
            int counterOfSpaces = 0;
            int availibleAreaForSpaces;
            string str = "";
            

            while (1)
            {
                counterOfLengths += words[i].size() + 1;

                if (i + 1 >= words.size())
                {
                    isEnd = 1;
                    break;
                }
                if (counterOfLengths + (words[i + 1]).size() <= maxWidth)
                {
                    i++;
                    conterOfWords++;
                }
                else break;
            }
            
            counterOfSpaces = conterOfWords;
            counterOfLengths = counterOfLengths - conterOfWords - 1;
            availibleAreaForSpaces = maxWidth - counterOfLengths;
            int counterOfSpacesOnStart = counterOfSpaces;
            int iOnStart = i;

            for (j; j < counterOfSpacesOnStart; j++)
            {
                string spaces = "";

                if (isEnd)
                {
                    str = ' ' + words[iOnStart] + str;
                    availibleAreaForSpaces--;
                }
                else
                {
                    if (availibleAreaForSpaces / counterOfSpaces == 1 && counterOfSpaces == 1)
                    {
                        spaces.assign(availibleAreaForSpaces, ' ');
                    }
                    else
                    {
                        spaces.assign(availibleAreaForSpaces / counterOfSpaces, ' ');
                    }
                    str = spaces + words[iOnStart] + str;

                    availibleAreaForSpaces = availibleAreaForSpaces - (availibleAreaForSpaces / counterOfSpaces);
                }
                iOnStart--;
                counterOfSpaces--;
            }

            i++;

            if (availibleAreaForSpaces != 0)
            {
                string spaces = "";
                spaces.assign(availibleAreaForSpaces, ' ');
                str = words[iOnStart] + str + spaces;
            }
            else
            {
                str = words[iOnStart] + str;
            }
            output.push_back(str);
        }
        return output;
    }
};

int main()
{
    Solution s;
    int mW = 16;
    vector<string>input = { "What","must","be","acknowledgment","shall","be" };
    vector<string>output = s.fullJustify(input, mW);
    for (auto it : output) {
        cout << it << endl;
    }
}
//This is an 
//This....is....an
//This...is..an..I
// 7 5 3
//example..of.text
//3 1
//red....white....blue...black...pink...nose
//17 14 11 8 4 0
//42 17