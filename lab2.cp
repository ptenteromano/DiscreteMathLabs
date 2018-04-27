/* Phil Tenteromano
 * 11/6/2017
 * Discrete Structures II
 * Professor Zhang
 * Lab 2 - GCD, RSA */

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <assert.h>


using namespace std;

//using some functions from lab 1:
int modOp(int, int);
int modExp(int,int,int);
int modMult (int, int, int);
bool isPrime(int);

//lab 2 functions:
int gcd(int, int);
int extendedGcd(int, int, int&, int&);
int relativePrime(int);
int inverseMod(int, int);
bool FermatTest(int);
int Encode(int, long int, long int);
int Decode(int, long int, long int);


int main()
{

    int s;      //needed for linear combo
    int t;
    int input1, input2;         //input variables
    int test1, test2;           //test variable

    cout<<"Euclidean algorithm on 2899 and 446: ";
    cout<<extendedGcd(50,7, s , t)<<endl;
    cout<<"s: "<<s<<endl<<"t: "<<t<<endl;

    cout<<"Input your own two numbers: ";
    cin>>input1>>input2;
    cout<<"Euclidean algorithm on "<<input1<<" and "<<input2<<": ";
    cout<<extendedGcd(input1, input2, s , t)<<endl;
    cout<<"s: "<<s<<endl<<"t: "<<t<<endl<<endl;

    test1 = relativePrime(4862);
    cout<<"Finding a Relative prime with 4862: "<<test1<<endl;
    cout<<"Inverse modulo: ";
    test2=inverseMod(7,50);
    cout<<test2<<endl               //inverse mod of the relative prime
        <<test1<<" * "<<test2<<" mod 4862 = 1"<<endl<<endl;

    cout<<"Fermat's little theorem!"<<endl
        <<"Input an integer, testing for primality: ";
    cin>>input1;
    FermatTest(input1);

    //cout<<isPrime(103);
    //cout<<isPrime(41);

    cout<<endl<<"RSA Algorithm! "<<endl;
    const int p = 41; //rand() % 300 + 101;     //picking 2 primes
    //cout<<"P: "<<p<<endl;
    const int q = 103; //rand() % 300 + 101;     //p and q
    //cout<<"Q: "<<q<<endl;
    long int n = p*q;       //PQ     //PUBLIC KEY (e,n)
    long int e = relativePrime( (p-1)*(q-1) );   //getting a relative prime
    cout<<"e: "<<e<<endl;
    long int d = inverseMod( e, (p-1)*(q-1) );   //getting the inverse of e
    cout<<"d: "<<d<<endl;

    int M = 30;              //variables for RSA algorithm
    int M1;
    int C;

    cout<<"Encoding and decoding 30: "<<endl<<endl;

    C = Encode(M, e, n);        //encoding M into C using public key
    M1 = Decode(C, d, n);

    cout<<"Original: "<<M<<endl;
    cout<<"Cipher text: "<<C<<endl<<"M1 decode: "<<M1<<endl<<endl;
    assert(M == M1);

    int counter = 0;
    while(counter < 3) {
        do {
            cout<<"Input an integer between 1-100: ";
            cin>>M;
        }while( M > 100 || M < 1);

        C = Encode(M, e, n);        //encoding M into C using public key
        M1 = Decode(C, d, n);       //decoding C into M1 using private key
        cout<<"Original: "<<M<<endl;
        cout<<"Cipher text: "<<C<<endl<<"M1 decode: "<<M1<<endl;
        assert(M == M1);
        counter++;
    }

    cout<<endl;
    return 0;
}

//standard GCD
int gcd(int a, int b)
{
    if(a == 0 && b == 0) {
        cout<<"Error!\n";
        return 0;
    }
    if(b == 0)
        return a;
    else {
        int r = modOp(a,b);
        return gcd(b, r);
    }

}

//Euclidean GCD
int extendedGcd(int a, int b, int &s, int &t)
{
    if(a == 0 && b == 0) {
        s = 1;
        t = 0;
        cout<<"Error!\n";
        return 0;
    }
    if(b == 0){         //base case to return
        s = 1;
        t = 0;
        return a;
    }
    else {
        int q = a/b;
        int r = modOp(a,b);        //r=a-b*q
        int s1, t1;

        int d = extendedGcd(b, r, s1, t1);
        s=t1;
        t=s1-t1*q;

        /* cout<<"s: "<<s<<endl
            <<"t: "<<t<<endl
            <<"a: "<<a<<endl
            <<"b: "<<b<<endl; */
        return d;
    }
}

//find a relative prime < n
int relativePrime(int n)
{
    int x = n-2;                        //start from n-2

    do{
        x--;                            //decrement x
    }while(gcd(x,n) != 1);

    return x;
}

//find the inverse of a mod n
int inverseMod(int a, int n)
{
    int s, t;
    int d = extendedGcd (n, a, s ,t);

    if (d==1)
    {
        return  (modOp(t, n)); // t might be negative, use mod() to reduce to
	   // an integer between 0 and n-1
    }
    else
    {
        cout <<"a,n are not relative prime!\n";
        return -1;
    }
}

//Fermat's little theorem (properties of a prime)
bool FermatTest(int p)
{
    int a;
    srand (time(NULL));     //find a random number
    do {
        a = rand() % 1000 + 1;      //p cannot divide a
    } while (modOp(a,p) == 0);

    if (modExp(a, p-1, p) != 1) {       //check for a 1 result
        cout<<p<<" is not prime!\n";    //if result is 1, p is not prime
        return false;
    }
    else {                     //else, p might be prime
        cout<<p<<" might be prime! (a^p-1 mod p == 1)\n";
        return true;
    }
}

//create public key outside, use function to encode
int Encode(int m, long int e, long int PQ)
{
    //Use public key (E, N) to encode the message M
    return modExp(m, e, PQ);    //return cipher C


}

//use private key to decode
int Decode(int c, long int d, long int PQ)
{
    //Use private key (D, N) to decode the cipher C
    return modExp(c, d, PQ);    //return M1
}


//***
//functions imported from lab1:
int modOp(int n, int m)     //replacing C++ % operator
{
    unsigned int r = 0;     //nonnegative integer

    if(n < 0) {         //check if n iks negative
        int k = m;      //assign some integer k
        n *= -1;        //make n positive
        while(k < n)    //loop and PASS n
            k += m;     //break n up into groups of m
        r = k - n;      //subtract n from k

        return r;       //return the remainder
    }
    else
        return n%m;     //else, regular modulus
}

int modMult(int a, int b, int n)
{
    int x =  (modOp(a, n)) * (modOp(b, n));     //multiply two mods

    return modOp(x, n);         //mod the new int
}

int modExp(int a, int e, int n)
{
    assert(e>=0 && n>=1);

    if (e==0)           //if exponent reaches 0, return 1 (a^e = 1);
        return 1;

    else if (e%2==0) {    //if exponent even, split in half until e = 1
        int x = modExp(a, e/2, n); //store recursion into x

        return modMult(x,x,n);  //mod, multiply, and mod with itself
    }
    else        //if e is ODD, multiply a mod n with recursive function
                //and decrement exponent!
        return modMult(modOp(a,n), modExp(a,e-1,n), n);
}

bool isPrime(int p)     //checking primality
{
    if(p < 2)               //nothing less than 2!
        return false;

    for (int k=2; k < p; k++)   //2 is prime, will never loop
        if(p%k == 0) {           //check for some int that divides p
            return false;       //end if k divides p evenly
        }
    return true;       //return true if all tests passed
}
