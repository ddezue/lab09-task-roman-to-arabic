/*************************
 * Автор: Бакланова Ляна *
 *************************/

#include <iostream>
#include <string>
using namespace std;

int getRomanDigitValue(char romanDigit) {
  if (romanDigit == 'I') {
    return 1;
  } if (romanDigit == 'V') {
    return 5;
  } if (romanDigit == 'X') {
    return 10;
  } if (romanDigit == 'L') {
    return 50;
  } if (romanDigit == 'C') {
    return 100;
  } if (romanDigit == 'D') {
    return 500;
  } if (romanDigit == 'M') {
    return 1000;
  }
  return 0;
}

int convertToArabic(string romanNumber) {
  int result;
  int previousValue;
  int currentPosition;
  char currentDigit;
  int currentValue;
  
  result = 0;
  previousValue = 0;
  
  for (currentPosition = romanNumber.length() - 1; currentPosition >= 0; --currentPosition) {
    currentDigit = romanNumber[currentPosition];
    currentValue = getRomanDigitValue(currentDigit);
    
    if (currentValue < previousValue) {
      result = result - currentValue;
    } else {
      result = result + currentValue;
    }
    
    previousValue = currentValue;
  }
  
  return result;
}

int main() {
  string inputRoman;
  int arabicResult;
  string answer;

  do { 
    cout << "Enter Roman number: ";
    cin >> inputRoman;
      
    arabicResult = convertToArabic(inputRoman);
    cout << "Arabic number: " << arabicResult << endl;
      
    cout << "Continue? (Y/N)";
    cin >> answer; 
  } while (answer == "Y");
  
    cout << "GG" << endl;
    return 0;
}
