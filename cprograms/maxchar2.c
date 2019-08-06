#include<stdio.h>
int main()
{
int maxCount = 0;
int maxChar = 0;
// i = A to Z
for (int i = 0; i <= 26; ++i)
{
  // if freq of this char is greater than the previous max freq
  if (frequency[i] > maxCount)
  {
      // store the value of the max freq
      maxCount = frequency[i];

      // store the char that had the max freq
      maxChar = i;
  }
}

// character codes are zero-based alphabet.
// Add ASCII value of 'A' to turn back into a char code.
return maxChar + 'A';
}
