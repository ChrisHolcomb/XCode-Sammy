#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
   int x = 0; // current position; x
   int y = 0; // current position; y
   int d = 0; // current direction; 0=RIGHT, 1=DOWN, 2=LEFT, 3=UP
   int c = 0; // counter
   int s = 1; // chain size
   int matrixSize=0, inputReadCount=0;

   string inputString;

   // get our input string
   getline(cin, inputString);
   // convert string to a charactor array
   vector<char> inputMessage(inputString.begin(), inputString.end());
   // get our matrix square size
   // TODO: come back and make sure this is an odd square
   matrixSize = ceil(sqrt(inputMessage.size()));
   // set our messageArray
   char messageArray[matrixSize][matrixSize];

   // fill our message array
   for (int i=0; i < matrixSize; i++) {
      for (int j=0; j < matrixSize; j++) {
         if (inputReadCount < inputMessage.size()) {
            messageArray[i][j] = inputMessage[inputReadCount];
         } else {
            messageArray[i][j] = '*';
         }
         inputReadCount++;
      }
   }

   x = ((int)floor(matrixSize/2.0));
   y = ((int)floor(matrixSize/2.0));

   for (int k=1; k<=(matrixSize-1); k++)
   {
      for (int j=0; j<(k<(matrixSize-1)?2:3); j++)
      {
         for (int i=0; i<s; i++)
         {
            cout << messageArray[x][y];
            c++;
            
            switch (d)
            {
               case 0: y = y + 1; break;
               case 1: x = x + 1; break;
               case 2: y = y - 1; break;
               case 3: x = x - 1; break;
            }
         }
         d = (d+1)%4;
      }
      s = s + 1;
   }
   cout << "\n";

   return 0;
}
