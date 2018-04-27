/* Phil Tenteromano
 * 10/26/2017
 * Discrete Structures II
 * Professor Zhang
 * Lab 1 - Primes and Mods */

#include <iostream>
#include <sys/time.h>       //used to track time
#include <iomanip>          //used for modular table

using namespace std;

int modOp(int, int);        //prototypes
bool isPrime(int);
void primeFactor(int);
int modAdd (int, int, int);
int modSub (int, int, int);
int modMult (int, int, int);
void modMultTable(int);         //extra credit
int modExp(int, int, int);

int main()
{
    int input;          //input used throughout program
    int found = 0;      //used to print out first x prime numbers
    int num = 2;        //number to check for primality
    double elapsed;     //elapsed time
    struct timeval begin,end;   //used to find time

    cout<<"Testing original c++ Modulus operator:"<<endl
        <<"-12 mod 5 = "<<-12%5<<endl<<endl;
    cout<<"New Modulus where remainder > 0, some examples:\n"
        <<"-12 mod 5 = "<<modOp(-12,5)<<endl
        <<"-36 mod 7 = "<<modOp(-36, 7)<<endl
        <<"-36 mod 5 = "<<modOp(-36, 5)<<endl
        <<"-58 mod 3 = "<<modOp(-58, 3)<<endl<<endl;

    cout<<"How many primes do you want to find? (reasonable amount):\n";
    cin>>input;

    gettimeofday (&begin,NULL);  //start clock

    while (found < input) {
         if(isPrime(num)) {             //loop, increment when prime
            cout<<num<<" is Prime!!\n";     //is found
            found++;
         }
         num++;
    }

    gettimeofday (&end,NULL);  //end clock
    elapsed = (end.tv_sec-begin.tv_sec)+        //calculate ELAPSED
		((end.tv_usec-begin.tv_usec)/1000000.0);
    cout<<"Finding "<<input<<" primes took "<<elapsed<<" seconds!!\n";

    for(int j=0; j<5; j++) {
    cout<<endl<<"Let's input some numbers to get their prime factors:\n";
        cin>>input;
        primeFactor(input);
    }

    cout<<"Check if a number is prime:\n";
    cin>>input;
    if(isPrime(input))
        cout<<input<<" is Prime!\n"<<endl;
    else
        cout<<"Not Prime :(\n"<<endl;

    char nextpart;          //slowing down output for user readability
    cout<<"Type any key to continue: "; cin>>nextpart;

    cout<<"Trying Modulus addition function...\n"
        <<"5 mod 3 = "<<modOp(5, 3)<<endl
        <<"8 mod 3 = "<<modOp(8, 3)<<endl
        <<"Using modAdd to input 5+8 mod 3 = "
        <<modAdd(5, 8, 3)<<endl<<"(2+2) mod 3 = 1\n"<<endl;

    cout<<"Trying Modulus subtraction function...\n"
        <<"40 mod 7 = "<<modOp(40, 7)<<endl
        <<"15 mod 7 = "<<modOp(15, 7)<<endl
        <<"Using modSub to input 40-15 mod 7 = "
        <<modSub(40, 15, 7)<<endl<<"(5-1) mod 7 = 4\n"<<endl;

    cout<<"Trying Modulus multiplication function...\n"
        <<"20 mod 8 = "<<modOp(20, 8)<<endl
        <<"30 mod 8 = "<<modOp(30, 8)<<endl
        <<"Using modMulti to input 20*30 mod 8 = "
        <<modMult(20, 30, 8)<<endl<<"(4*6) mod 8 = 0\n"<<endl;

    modMultTable(6);        //mod table with a constant (6)

    cout<<"Type any number to see that number's Mod multi table!\n";
    cin>>input;             //ask user to do any mod table
    modMultTable(input);

    cout<<"Final test, Modulus exponent function!!...\n"
        <<"5^4 mod 3 = "<<modExp(5,4,3)<<endl
        <<"5^4 = 625, mod 3 = 1"<<endl
        <<"Another one:\n"
        <<"2^6 mod 5 = "<<modExp(2,6,5)<<endl
        <<"2^6 = 64, mod 5 = 4"<<endl<<endl;

    int a, b;       //input variables
    cout<<"Now you try! input 3 integers > 0:\n";
    cin>>a; cin>>b; cin>>input;

    cout<<a<<"^"<<b<<" mod "<<input<<" = "<<modExp(a, b, input)
        <<endl<<endl;

    cout<<"Very cool!\n";

    return 0;           //end main
}

//function implementations
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

void primeFactor(int n)    //prime factorization
{
    if(isPrime(n))         //if n is prime, we found prime factor
        cout<<n;
    else {
        int i = 2;         //start with the first prime

        while ( i < n ) {       //i can't be a factor of n if i < n
            while( n%i == 0 ) { //nest while loop, divide n
                n = n/i;            //shrink n down to smaller int
                cout<<i;            //i is a prime factor
                if(n != 1)
                    cout<<" * ";
            }

            if ( isPrime(n) ){      //if n is prime, we're finished
                cout<<n;
                break;
            }
            else if( n/i != 0 )
                do{               //else, move onto the next i prime
                    i++;            //loop until i is prime
                }while( !isPrime(i) );  //then do again
        }   //while
    }   //else
    cout<<endl;
}

int modAdd(int a, int b, int n)
{
    int x =  modOp(a, n) + modOp(b, n);     //add two mods together

    return modOp(x, n);         //mod the new int
}

int modSub(int a, int b, int n)
{
    int x = modOp(a, n) - modOp(b, n);    //subtract two mods

    return modOp(x, n);         //mod the new int
}

int modMult(int a, int b, int n)
{
    int x =  (modOp(a, n)) * (modOp(b, n));     //multiply two mods

    return modOp(x, n);         //mod the new int
}

void modMultTable(int n)        //multiplication table
{
    int table[n][n];    //n size (1 for table headings)

    for(int h=0; h<n; h++) {
        table[0][h] = h;         //assign incremental headings
        table[h][0] = h;         //for first row and first column
    }

    for(int r=1; r<n; r++)      //start at 1, headings assigned
        for(int c=1; c<n; c++)
            table[r][c] = modMult(r, c, n); //assign value to table

    cout<<"Displaying the modular multiplication table for "<<n
        <<"!!\n";

    for(int r=0; r<n; r++) {        //start at 0, display table
        for(int c=0; c<n; c++) {
            if(r==0 && c==0) {
                cout.width(5); cout<<' ';
                continue;             //skip [0][0], but add gap
            }
            cout<<setw(5)<<left<<table[r][c];
        }                 //using iomanip for multi-digit integers
        cout<<endl;                   //newline for new row
    }
    cout<<endl;
}

int modExp(int a, int e, int n)
{
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

