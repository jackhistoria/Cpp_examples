#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

int randRange (int low, int high)
{
  return rand() % (high -low) + low;
}

string walze (int b, int c)
{
  int a = randRange(b, c);
  if ((a == 10) || (a == 20) || (a == 30)) {
    return "Jackpot";
  } else if((a == 1) || (a == 2) || (a == 3) ||
            (a == 11) || (a == 12) || (a == 13) ||
            (a == 21) || (a == 22) || (a == 23))
  {
    return "Sieben";
  } else {
    return "Melone";
  }
}

int main()
{
  int gewinn = 0;
  int eingeworfen = 0;
  int gesamt = 0;
  srand( time( NULL ) );
  for (int i = 0; i < 1000; ++i )
  {
    string walze1 = walze(1,11);
    string walze2 = walze(11,21);
    string walze3 = walze(21,31);
    cout << walze1 << ' ';
    cout << walze2 << ' ';
    cout << walze3 << '\n';

    if ((walze1 == "Jackpot") && (walze2 == "Jackpot") && (walze3 == "Jackpot")) {
      cout << "YOU WOOOOOOOOOOOOOOOOOOOOONNNNNNNNNNNNNNNNN!!! Katching 400€" << '\n';
      gewinn += 400;
    } else if ((walze1 == "Sieben") && (walze2 == "Sieben") && (walze3 == "Sieben")) {
      cout << "You done good!!! Katching 20€" << '\n';
      gewinn += 20;
    } else if ((walze1 == "Melone") && (walze2 == "Melone") && (walze3 == "Melone")) {
      cout << "You done ok!!! Katching! 2€" << '\n';
      gewinn += 2;
    }
    eingeworfen += 1;
    gesamt = gewinn - eingeworfen;

    std::cout << "Gewinn = " << gewinn << '\n';
    std::cout << "Eingeworfen = " << eingeworfen << '\n';
    std::cout << "Gesamt (Gewinn - Verlust) = " << gesamt<< "\n";
    std::cout << "____________________________________________________" << "\n\n";

  }
}

// A-10  B-10  C-10
//1mal JACKPOT, 3mal SIEBEN und 6mal MELONE
//2 Euro für 3mal "Melone", 20 Euro für 3mal "Sieben" und 400 Euro für 3mal "Jackpot".
//alle unterschiedlich = zusätzlicher Versuch
