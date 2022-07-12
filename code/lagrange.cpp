#include <bits/stdc++.h>
using namespace std;
int n = 6;//(n+1) datapoints
/*
                                        CLL113 ASSIGNMENT-6
LAGRANGE POLYNOMIAL to interpolate the population of India at any given year within the range of 1960 to 2020.

*/

//function to obtain value of P(x)
long double Px(int i, long double *X, long double x)
{
    long double value = 1;
    for (int j = 0; j < n + 1; j++)
    {
        if (j != i)
        {
            value = value * ((long double)(x - X[j]) / (X[i] - X[j]));
        }
    }

    return value;
}

int main()
{
    ifstream in("dataset.txt");
    ofstream out("output.txt");
    long double X[n + 1];
    long double Y[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        in>>X[i];
        in>>Y[i];
    }

    long double x;
    in >> x; 

    long double fx = 0;
    for (int i = 0; i < n + 1; i++)
    {
        fx += (Y[i] * Px(i, X, x));
    }
    cout << endl
         << "Year " << x <<fixed<<setprecision(9)<< ": Estimated Population = " << fx <<" Billions"<< endl;

    return 0;
}