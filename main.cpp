#include <iostream>
#include <iomanip>
using namespace std;

//Function prototype
double netPay(double, double, string, int);

int main() {

  //Function calls
  cout << netPay(47, 505.75, "Osama", 1);
  cout << netPay(45, 55.25, "Melvin", 1);
  cout << netPay(15, 62.35, "Susan", 0);
  cout << netPay(41, 14.75, "Mika", 1);
  cout << netPay(25, 15.0, "Eldridge", 0);
  cout << netPay(55, 203.50, "Freedom", 1);
  cout << netPay(32.5, 100.25, "Tyson", 1);

  //Unit 5 Assignment Part2
  string phrase1 = "TCC-TR IS COOL";
  string phrase2 = "i will succeed at c++";
  locale loc;
  
  cout << "\n\nAssignment Part 2\n";
  for(int i = 0; i < phrase1.length(); i++)
    cout << tolower(phrase1[i], loc);
  cout << endl;
  for(int i = 0; i < phrase2[i]; i++)
    cout << toupper(phrase2[i], loc);
  cout << endl;
  
  return 0;
}

//Function Definition
double netPay(double hours, double hrlyRate, string name, int empType){
  double netPay = 0.0; //Weekly pay after taxes
  const double otHours = 40.0;
  double grossPay = 0.0; //Pay before taxes and deductions
  double fitRate; //Holds value of federal in tax percentage : 12% or 15%

  //Name
  cout << "\n\nEmployee Name: ";
  locale loc;
  for(int i = 0; i < name.length(); i++)
    cout << "\033[31m" << toupper(name[i], loc); 
  cout << "\033[0m" << endl;

  //Employment Type
  cout << "Employment type: ";
  if(empType == 0)
    cout << "Part-time\n";
  else
    cout << "Full-Time\n";

  //Handle Overtime Pay
  if(hours <= 40){
    grossPay += hours * hrlyRate; //if no overtime, calculate grossPay
  }
  else {
              //Base pay + hours of overtime * 2x pay
    grossPay += (otHours * hrlyRate) + ((hours - otHours) * (hrlyRate * 2));
  }

  //Calcualte netPay
  //Determine fitRate
  if (hrlyRate < 15.00)
    fitRate = 0.12;
  else
    fitRate = 0.15;
  //Part-time or Full-time caclculations
  if (empType == 0)
    netPay = grossPay - (grossPay * fitRate) - (grossPay * 0.062) - (grossPay * 0.0145);
  else  {
    grossPay = grossPay - 94; //Deductions before tax for Full-time employees
    netPay = grossPay - (grossPay * fitRate) + (grossPay * 0.062) + (grossPay * 0.0145);
    }

  cout << fixed << setprecision(2);
  cout << "Weely pay: $";
  return netPay;
}