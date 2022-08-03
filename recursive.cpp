#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
} /*One line Factorial*/

int fibonacci(int n, int ini, int fin)
{ /*fibonacci*/
    if (n == 0)
        return -1;
    cout << ini << " ";

    fibonacci(n - 1, fin, ini + fin);
}

int gcd(int a, int b)
{ /*Greatest Common Divisor*/
    if (!(a > b))
        return -1;

    else
    {
        int r = a % b;
        if (r == 0)
            return b;
        else
            return gcd(b, r);
    }
}

int exponent(int a, int n)
{
    if (n == 0)
        return 1;
    return a * exponent(a, n - 1);
} /*a^x in one line*/

void towerohanoi(int disks, string source, string help, string end)
{ /*Tower of Hanoi*/

    if (disks == 1)
    {
        cout << "Disk" << disks << "transferred from rod " << source << " to " << end << endl;
        return;
    }
    towerohanoi(disks - 1, source, end, help);
    cout << "Disk" << disks << "transferred from rod " << source << " to " << end << endl;
    towerohanoi(disks - 1, help, source, end);
}

int binarysearch(int ar[], int elem, int ini, int len)
{ // Binary search using recursion

    int mid = (ini + (len - 1)) / 2;
    if (elem == ar[mid])
        return mid;

    if (elem > ar[mid])
        return binarysearch(ar, elem, mid + 1, len);

    if (elem < ar[mid])
        return binarysearch(ar, elem, ini, mid);
}

/*Add nCr and nPr here and resend the code in group*/

int main()
{
    cout << "Factorial : " << factorial(5) << endl;
    cout << "GCD : " << gcd(159, 27) << endl;
    cout << "exponent: " << exponent(2, 4) << endl;
    cout << "Fibonacci";
    fibonacci(3, 0, 1);
    cout << "\nTower of Hanoi ";
    towerohanoi(3, "A", "B", "C");
    int a[] = {1, 2, 3, 4, 5};
    cout << "\nElement 5 in {1,2,3,4,5} at index : " << binarysearch(a, 5, 0, 5);
}
