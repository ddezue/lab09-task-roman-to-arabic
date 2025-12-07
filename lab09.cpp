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
  int position;
  int count;
  int nextPosition;
  
  // Check 1: no zero
  if (romanNumber == "0") {
    cout << "Error: Roman numeral cannot be zero" << endl;
    return 0;
  }
  
  // Check 2: I, X, C, M cannot repeat more than 3 times
  position = 0;
  while (position < romanNumber.length()) {
    if (romanNumber[position] == 'I' || romanNumber[position] == 'X' || romanNumber[position] == 'C' || romanNumber[position] == 'M') {
      count = 1;
      nextPosition = position + 1;

      while (nextPosition < romanNumber.length() && romanNumber[nextPosition] == romanNumber[position]) {
        count = count + 1;
        nextPosition = nextPosition + 1;
      }
      
      if (count > 3) {
        cout << "Error: Roman digit repeats too many times" << endl;
        return 0;
      }
    }
    position = position + 1;
  }
  
  // Check 3: V, L, D cannot repeat
  position = 0;
  while (position < romanNumber.length() - 1) {
    if (romanNumber[position] == 'V' || romanNumber[position] == 'L' || romanNumber[position] == 'D') {
      if (romanNumber[position + 1] == romanNumber[position]) {
        cout << "Error: Roman digit cannot repeat" << endl;
        return 0;
      }
    }
    position = position + 1;
  }
  
  result = 0;
  previousValue = 0;
  currentPosition = romanNumber.length() - 1;
  
  while (currentPosition >= 0) {
    currentDigit = romanNumber[currentPosition];
    currentValue = getRomanDigitValue(currentDigit);
    
    if (currentValue < previousValue) {
      result = result - currentValue;
    } else {
      result = result + currentValue;
    }
    
    previousValue = currentValue;
    currentPosition = currentPosition - 1;
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
    
    if (arabicResult != 0) {
      cout << "Arabic number: " << arabicResult << endl;
    }
      
    cout << "Continue? (Y/N)";
    cin >> answer; 
  } while (answer == "Y");
  
  cout << "GG" << endl;
  return 0;
}
