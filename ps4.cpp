#include <iostream> // cin cout
#include <iomanip> // setw setprecision
#include <math.h> // sqrt pow ...
#include <cmath>
#include <string> // string class

using namespace std;

//Define functions that do the math of their var names and return the value
double manDist (double x1, double x2, double y1, double y2);
double eudDist (double x1, double x2, double y1, double y2);
double slope (double x1, double x2, double y1, double y2);



int main(int argc, char const *argv[3]){
//Define Variables
  int iterationCnt;
  bool doeucdist;
  string distance, iterationstring;
  double x1, x2, y1, y2;
  double hix1, hix2, hiy1, hiy2; // for output
  double lox1, lox2, loy1, loy2; // for output
  double hislope = 0;
  double lowslope = 1000;
  double distancecalc, slopecalc;
  double hidistancecalc, lodistancecalc; // for output

  cout << argc << endl; // out puts number of command line argumetns
  if (argc != 1 && argc != 3)
  {
    //Errors if cmd argmuents arents 1 or 3
    cout << "Error: Incorrect amount of command line arguments,";
    return 0;
  }

// arg 1
//Takes input '-e' '-E' '-m' '-M' only to define distance for the program to use
  //cin >> distance;
  cout << argv[1];
  distance = argv[1];
  if (cin.fail() || (distance != "-e" && distance != "-E" && distance != "-m" && distance != "-M"))
  {
    cout << "Error: Not a valid option,";
    return 0;
  }

  if (distance == "-e" || distance == "-E")
  {
    cout << "Euclidean Distance\n";
    doeucdist = true;
  } else
  {
    cout << "Manhattan Distance\n";
    doeucdist = false;
  }



// arg 2
// takes a number to use that many distances to calculate
  //cin >> iterationstring;
  iterationstring = argv[2];
  iterationCnt = stoi(iterationstring);
  if (iterationCnt > 5 || iterationCnt < 2)
  {
    cout << "Error: Iteration count not in range 2-5,";
    return 0;
  }

  for (int i = 1; i <= iterationCnt; i++)
  {
    cout << endl
         << "Enter a x1 value:\n**";
    while (!(cin >> x1) || x1 >= 100 || x1 <= 0)
    {
      cout << "Error: invalid input" << endl;
      cout << "Enter a x1:\n**";
      cin.clear();
      cin.ignore(300, '\n');
    }

    cout << "Enter a y1 value:\n**";
    while (!(cin >> y1) || y1 >= 100 || y1 <= 0)
    {
      cout << "Error: invalid input" << endl;
      cout << "Enter a y1 value:\n**";
      cin.clear();
      cin.ignore(300, '\n');
    }

    cout << endl
         << "Enter a x2 value:\n**";
    while (!(cin >> x2) || x2 >= 100 || x2 <= 0)
    {
      cout << "Error: invalid input" << endl;
      cout << "Enter a x2 value:\n**";
      cin.clear();
      cin.ignore(300, '\n');
    }

    cout << "Enter a y2 value:\n**";
    while (!(cin >> y2) || y2 >= 100 || y2 <= 0)
    {
      cout << "Error: invalid input" << endl;
      cout << "Enter a y2 value:\n**";
      cin.clear();
      cin.ignore(300, '\n');
    }

    if(!doeucdist)
    {
      distancecalc = manDist(x1, x2, y1, y2);
    } else
    {
      distancecalc = eudDist(x1, x2, y1, y2);
    }

    slopecalc = slope(x1, x2, y1, y2);

    if(slopecalc > hislope)
    {
      hislope = slopecalc;
      hidistancecalc = distancecalc;
      hix1 = x1;
      hix2 = x2;
      hiy1 = y1;
      hiy2 = y2;
    }

    if (slopecalc < lowslope)
    {
      lowslope = slopecalc;
      lodistancecalc = distancecalc;
      lox1 = x1;
      lox2 = x2;
      loy1 = y1;
      loy2 = y2;
    }

    cout << endl << endl << endl;
    cout << "CALCULATION " << i << endl;
    if(!doeucdist)
    {
      cout << fixed
           << setw(10) << left << "manDist" << "slope" << endl;
      cout << fixed
           << setw(10) << left << distancecalc << slopecalc << endl;
    } else
    {
      cout << fixed
           << setw(10) << left << "eucDist" << "slope" << endl;
      cout << fixed
           << setw(10) << left << distancecalc << slopecalc << endl;
    }

  }

  if(!doeucdist)
  {
    cout << fixed
         << setw(16) << left << "Highest Slope"
         << setw(5) << left << "x1" << "y1" << "x2" << "y2" << "manDist" << endl;
    cout << fixed
         << setw(16) << left << hislope;
    cout << setw(5) << left << (int) hix1 << (int) hiy1 << (int) hix2 << (int) hiy2
         << setw(7) << setprecision(4) << hidistancecalc << endl << endl;

    cout << fixed
         << setw(16) << left << "Lowest Slope";
    cout << "x1   y1   x2   y2   manDist" << endl;
    cout << fixed
         << setw(16) << left << lowslope
         << setw(5) << left << lox1 << loy1 << lox2 << loy2 << lodistancecalc << endl << endl;
  } else
  {
    cout << fixed
         << setw(16) << left << "Highest Slope";
    cout << "x1   y1   x2   y2   eucDist" << endl;
    cout << fixed
         << setw(16) << left << hislope;
    cout << setw(5) << left << fixed << setprecision(3)
         << (int) hix1 << setw(5) << (int) hiy1 << setw(5) << (int) hix2 << setw(5) << (int) hiy2
         << setw(7) << setprecision(4) << hidistancecalc << endl << endl;

    cout << fixed
         << setw(16) << left << "Lowest Slope"
         << setw(5) << left << "x1" << "y1" << "x2" << "y2" << "eucDist" << endl;
    cout << fixed
         << setw(16) << left << lowslope
         << setw(5) << fixed << setprecision(3) << (int) lox1 << (int) loy1 << (int) lox2 << (int) loy2
         << setw(7) << setprecision(4) << lodistancecalc << endl << endl;
  }

  return 0;
}

//Calculates Slope
double slope (double x1, double x2, double y1, double y2)
{
  double slope = (y2 - y1) / (x2 - x1);
  return slope;
}

//Calculates Manhattan Distance
double manDist (double x1, double x2, double y1, double y2)
{
  double manhattan = abs((x2-x1)) + abs((y2 -y1));
  return manhattan;
}

//Calculates Euclidean Distance
double eudDist (double x1, double x2, double y1, double y2)
{
  double firstSquared = pow(x2-x1, 2);
  double secondSquared = pow(y2-y1, 2);
  double euclidean = sqrt(firstSquared + secondSquared);
  return euclidean;
}
