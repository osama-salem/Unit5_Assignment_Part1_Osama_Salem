#include <iostream>
#include <iomanip>
using namespace std;

double netPay(double, double, string, int);

int main() {

  //cout << netPay(0.0, 0.0, "Osama", 0);
  
  return 0;
}

//Function Definition
double netPay(double hours, double hrlyRate, string name, int empType){
  double netPay = 0.0;

  //Name
  locale loc;
  for(int i = 0; i < name.length(); i++)
    cout << "\033[31m" << toupper(name[i], loc); 
  cout << "\033[0m";

  //Employment Type
  if(empType == 0)
    cout << "\nPart-time\n";
  else
    cout << "\nFull-Time\n";
  
  return netPay;
}