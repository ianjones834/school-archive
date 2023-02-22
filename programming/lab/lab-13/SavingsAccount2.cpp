#include <iostream>
using namespace std;

class SavingsAccount
{
  private:
    int dollars,
        cents;
    void normalizeAmounts();

  public:
    void openAccount(int d, int c);
    void  deposit(int d, int c);
    void  withdrawal(int d, int c);
    void  printBalance();
};

int main()
{
  SavingsAccount bank1;

  int dollars,
      cents;

  char choice = 'y';

  cout << "Input the initial dollars: ";
  cin >> dollars;
  cout << endl;

  cout << "Input the initial cents: ";
  cin >> cents;
  cout << endl;
  
  bank1.openAccount(dollars, cents);
  
  cout << "Would you like to make a deposit? (Y or y for yes): ";
  cin >> choice;

  while(choice == 'y' || choice =='Y')
  {
    cout << "Input the dollars to be deposited: ";
    cin >> dollars;
    
    cout << "Input the cents to be deposited: ";
    cin >> cents;

    bank1.deposit(dollars, cents);

    cout << "Would you like to make a deposit? (Y or y for yes): ";
    cin >> choice;
  }

  cout << endl << "Would you like to make a withdrawal? " 
    << "(Y or y for yes): ";
  cin >> choice;

  while (choice == 'y' || choice == 'Y')
  {
    cout << "Input the dollars to be withdrawn: ";
    cin >> dollars;

    cout << "Input the cents to be withdrawn: ";
    cin >> cents;

    bank1.withdrawal(dollars, cents);

    cout << endl << "Would you like to make a withdrawal? " 
      << "(Y or y for yes): ";
    cin >> choice;
  }

  cout << endl;
  bank1.printBalance();

  return 0;
}

void SavingsAccount::normalizeAmounts()
{
  if (cents > 99)
  {
    dollars += cents / 100;
    cents = cents % 100;
  }
  else if (cents > -99 && cents < 0)
  {
    dollars -= 1;
    cents += 100;
  }
  else if(cents < -99)
  {
    dollars += cents / 100;
    cents = 100 - ((-1 * cents) % 100);
  }
}

void SavingsAccount::openAccount(int d, int c)
{
  cents = c;
  dollars = d;

  normalizeAmounts();
}

void SavingsAccount::deposit(int d, int c)
{
  cents += c;
  dollars += d;

  normalizeAmounts();
}

void SavingsAccount::withdrawal(int d, int c)
{
  cents -= c;
  dollars -= d;

  normalizeAmounts();
}

void SavingsAccount::printBalance()
{
  cout << "Dollars = " << dollars;
  cout << "  Cents = " << cents << endl;
}
