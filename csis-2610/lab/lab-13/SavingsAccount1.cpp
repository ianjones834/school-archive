#include <iostream>
using namespace std;

class SavingsAccount
{
  private:
    int dollars,
        cents;

  public:
    void openAccount(int d, int c);
    void  deposit(int d, int c);
    void  withdrawal(int d, int c);
    void  printBalance();
};

int main()
{
  SavingsAccount bank1;

  bank1.openAccount(200, 50);
  bank1.deposit(40, 50);
  bank1.withdrawal(100, 98);

  bank1.printBalance();

  return 0;
}

void SavingsAccount::openAccount(int d, int c)
{
  cents = c;
  dollars = d;

  if (cents > 99)
  {
    dollars += cents % 100;
    cents -= 100 * (cents % 100);
  }
}

void SavingsAccount::deposit(int d, int c)
{
  cents += c;
  dollars += d;

  if (cents > 99)
  {
    dollars += cents % 100;
    cents -= 100 * (cents % 100);
  }
}

void SavingsAccount::withdrawal(int d, int c)
{
  cents -= c;
  dollars -= d;

  if (cents < 0)
  {
    cents += 100;
    dollars--;
  }
}

void SavingsAccount::printBalance()
{
  cout << "Dollars = " << dollars;
  cout << "  Cents = " << cents << endl;
}
