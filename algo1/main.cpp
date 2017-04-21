#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include<vector>


//Masoud QashQaei 9150022

using namespace std;


int *multiply(int A[], int B[], int m, int n)
{
int *prod = new int[m+n-1];

// Initialize the porduct polynomial
for (int i = 0; i<m+n-1; i++)
	prod[i] = 0;

// Multiply two polynomials term by term

// Take ever term of first polynomial
for (int i=0; i<m; i++)
{
	// Multiply the current term of first polynomial
	// with every term of second polynomial.
	for (int j=0; j<n; j++)
		prod[i+j] += A[i]*B[j];
}

return prod;
}

// A utility function to print a polynomial
void printPoly(int poly[], int n)
{
	for (int i=0; i<n; i++)
	{
	cout << poly[i];
	if (i != 0)
		cout << "x^" << i ;
	if (i != n-1)
	cout << " + ";
	}
}

bool IsParenthesesOrDash(char c)
{
    switch(c)
    {
    case ',':
        return true;
    default:
        return false;
    }
}


// Driver program to test above functions
int main()
{
    ifstream file("poly.txt");
    string str,str0, str1;
    //int i=0;
    //int j=0;
   // string test;

    if(file.is_open()){

        getline(file,str);
        //int a= atoi(str.c_str());
        getline(file,str0);
        str0.erase(remove_if(str0.begin(), str0.end(), &IsParenthesesOrDash), str0.end());
        stringstream stream(str0);
        //cout<<(str0.length())<<endl;

        int A[(str0.length()/2)];
        vector<int> values;
            int n1;
            int r=0;
            while(stream >> n1){
                values.push_back(n1);
                A[r]=n1;
                r++;
                }


        getline(file,str1);
        str1.erase(remove_if(str1.begin(), str1.end(), &IsParenthesesOrDash), str1.end());
        stringstream stream1(str1);
        int B[(str1.length()/2)+1];
        vector<int> values1;
            int y;
            int t=0;
            while(stream1 >> y){
                values1.push_back(y);
                B[t]=y;
                t++;
                }



	int m = sizeof(A)/sizeof(A[0]);
	int n = sizeof(B)/sizeof(B[0]);

	cout << "First polynomial is \n";
	printPoly(A, m);
	cout << "\nSecond polynomial is \n";
	printPoly(B, n);

	int *prod = multiply(A, B, m, n);

	cout << "\nProduct polynomial is \n";
	printPoly(prod, m+n-1);
    }

	return 0;
}

