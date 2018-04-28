Discrete Structures Labs

Written with C++

Lab 1:
  - Contains mod, prime, factorization functions

  - A new Modulus Operator which returns a non-neg Integer value
      If n is negative for n mod m, then it returns the non-neg value, k, such
      that m * (some Integer q) + k = n (where n is negative).
      This is a good representation of debt: if I owe somebody $8 but only carry
      5 dollar bills, I will pay my debt in full. And get $2 change back.
      ex: -8 mod 5 = 2
      (the native C++ modulus would return -3 in this case. I'd still owe!)

  - My first ever primality algorithm - very poor running time

  - A factorization algorithm - not terrible, but we all know factorization is
      a very difficult NP problem so, lets try not to input anything too crazy

  - Modulus operations using mod rules to vastly decrease running time
    - Mod addition ((n mod m) + (p mod m)) mod m
    - Mod subtraction ((n mod m) - (p mod m)) mod m
    - Mod Multiplication ((n mod m) * (p mod m)) mod m
    - Recursive Mod exponentiation - very important for RSA

  - Mod Table function which outputs an n by n matrix
    - the values at any position x,y outputs (x*y) mod n

Lab 2:
  - Focus on RSA 
  - Contains GCD, extendedGCD, Relative Prime,
    InverseMod, Fermat's Little theorem functions
  - Most have a part to play in the RSA functions for public/private key
    - Encode
    - Decode
