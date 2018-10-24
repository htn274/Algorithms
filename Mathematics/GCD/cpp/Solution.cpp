#include <iostream>

using namespace std;

//@para: a, b is 2 integers, result to store root 
//@return: gcd(a, b)

long long extendEuclid(long long a, long long b, pair<long long, long long> &result){
    long long m, n, r, xm, xn;
    m = a; n = b;
    xm = 1; xn = 0; //m = xm * a + ym * b, n = xn * a + yn * b

    while (n != 0){
        long long q = m / n;
        r = m - q * n; // r = m % n
        long long xr = xm - q * xn;
        m = n; n = r; 
        xm = xn; xn = xr;
    }
    result = make_pair(xm, (m - a * xm)/b);
    return m; // m = GCD(a, b)
}

//@para: n1 * x + y * n2 = n, and x * c1 + y * c2 is the minimum
//@return: true if equation has root, otherwise false
bool diophaneSolve(long long n1, long long c1, long long n2, long long c2, long long n, pair<long long, long long>& ans){
    pair<long long, long long> res;
    long long d = extendEuclid(n1, n2, res);
    if (n % d != 0){
        return false;
    }
    long long coeff = n / d;
    long long x = 0, y = 0;
    x =  res.first * coeff; y = res.second * coeff;
    //Make sure x >= 0 and y >= 0
    long long p = n2 / d, q = n1/ d;
    //Make sure x >= 0
    long long k = -(x / p) + (x % p != 0);
    x += k * p;
    y -= k * q;
    //Make sure y >= 0
    if (y < 0){
        k = -(y / q) + (y % q != 0);
        x -= k * p;
        y += k * q;
    }
    if (x < 0 || y < 0){
        return false;
    }
    //Minimize x and maximize y
    k = x / p;
    x = x - k * p;
    y = y + k * q;
    long long x1 = x, y1 = y;
    //Maximize x and minimize y
    k = y / q;
    x = x + k * p;
    y = y - k* q;
    long long x2 = x, y2 = y;

    if (x1 * c1 + y1 * c2 <= x2 * c1 + y2 * c2){
        ans = make_pair(x1, y1);
    } else {
        ans  = make_pair(x2, y2);
    }
    return true;
}

int main(){
    long long n, c1, n1, c2, n2;

    while (true){
        cin >> n;
        if (n == 0){
            break;
        }

        cin >> c1 >> n1;
        cin >> c2 >> n2;

        //X * n1 + Y * n2 = n
        //X * c1 + Y * c2 is min
        pair<long long, long long> answer;
        bool haveSol = diophaneSolve(n1, c1, n2, c2, n, answer);
        if (!haveSol){
            cout << "failed" << endl;
            continue;
        }

        cout << answer.first << " " << answer.second << endl;
    }
    return 0;
}