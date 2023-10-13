// BASIC IDEA:

// Start traversing the provided string(str)
// Skip all the leading white spaces.eg: " -123456" -- > "-123456"
// Check for sign cases(+-).eg: "-123456".If + , then set the variable(boolean) isNegative to true and if it's -, set isNegative to false
// Iterate over the next remaining characters and keep adding them in result by converting the digits(in character form) to integer form.eg : "-123456" -- > -123456, until the non - digit character is found.
// NOTE: Logic is implemented in such a way that after performing above 3 steps, if it finds characters(English letters(lower - case and upper - case), digits(0 - 9), ' ', '+', '-', and '.') before the digit character, it will give output as 0(zero)eg : "abc-123456" -- > 0 and if it finds characters(English letters(lower - case and upper - case), digits(0 - 9), ' ', '+', '-', and '.') after the digit characters, it will return the number eg : "-123456abc" -- > -123456

#include <string>
#include <iostream>

using namespace std;

bool isDigit(char ch) {
  return ch >= '0' && ch <= '9';
}

int myAtoi(string str) {
  int len = str.length();

  if (len == 0) return 0;

  int index = 0;

  while (index < len && str[index] == ' ') {
    index++;
  }

  if (index == len) return 0;

  char ch;
  bool isNegative = (ch = str[index]) == '-';

  if (isNegative || ch == '+') index++;

  int result = 0;
  int maxLimit = INT_MAX / 10;

  while (index < len && isdigit(str[index])) {
    int digit = str[index] - '0';

    if (result > maxLimit || (result == maxLimit && digit > 7)) {
      return isNegative ? INT_MIN : INT_MAX;
    }

    result = (result * 10) + digit;

    ++index;
  }

  return isNegative ? -result : result;
}


int main() {
  // Test case 1: Positive number
  string str1 = "123";
  int result1 = myAtoi(str1);
  cout << "Result 1: " << result1 << endl;  // Expected output: 123

  // Test case 2: Negative number
  string str2 = "-456";
  int result2 = myAtoi(str2);
  cout << "Result 2: " << result2 << endl;  // Expected output: -456

  // Test case 3: Number with leading and trailing spaces
  string str3 = "   789   ";
  int result3 = myAtoi(str3);
  cout << "Result 3: " << result3 << endl;  // Expected output: 789

  // Test case 4: Number with leading plus sign
  string str4 = "+987";
  int result4 = myAtoi(str4);
  cout << "Result 4: " << result4 << endl;  // Expected output: 987

  // Test case 5: Number with leading minus sign and trailing characters
  string str5 = "-123abc";
  int result5 = myAtoi(str5);
  cout << "Result 5: " << result5 << endl;  // Expected output: -123

  return 0;
}
