/*
 * https://open.kattis.com/problems/modulararithmetic
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

// Extended Euclid: Solving Linear Diophantine Equation
// ax + by = c has no integral solutions if gcd(a, b) | c is not true
// calculate x0, y0 by this algorithm
// then: x = x0 + (b/gcd(a, b))n, y = y0 − (a/gcd(a, b))n
long long int x, y, d; // d = gcd(a, b)
void extendedEuclid(long long int a, long long int b) {
    if (b == 0){ // base case
        x = 1;
        y = 0; 
        d = a;
        return;
    }
    extendedEuclid(b, a % b); // similar as the original gcd
    long long int x1 = y;
    long long int y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}


// work to find x in: a.x ≡ 1 mod m
int modularInverse(long long int a, long long int m){
    extendedEuclid(a, m);
    if (d != 1) {
        return -1; // No Solution.
    }
    else {
        return (x % m + m) % m;
    }    
}

int modDivide(long long int a, long long int b, long long int m) 
{ 
    a = a % m; 
    long long int inv = modularInverse(b, m); 
    if (inv == -1)
       return -1; // No Solution!
    else
       return (inv * a) % m; 
} 

long long int n, t, a, b;
char ch;
int main()
{
    while(cin >> n >> t && n && t){
        while(t--){
            cin >> a >> ch >> b;
            if(ch == '+'){
                cout << ((a%n)+(b%n))%n << endl;
            }
            else if(ch == '-'){
                cout << (a-b+n)%n << endl;
            }
            else if(ch == '*'){
                cout << ((a%n) * (b%n))%n << endl;
            }
            else{
                cout << modDivide(a, b, n) << endl;
            }
        }
    }
    return 0;
}

