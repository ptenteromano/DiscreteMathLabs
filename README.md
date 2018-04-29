Discrete Structures Labs and Small Program Files

Written in C++ and Python3

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

BinaryAlg
  - An algorithm for converting a decimal number into binary representation
  - This binary representation is not 0/1. It is 1/2, meaning the number:
      212 in this bin form is         = 2*(2^2) + 1*(2^1) + 2*(2^0)
                                      = 2*4 + 1*2 + 2*1
                                      = 8+2+2 = 12
  - The algorithm scans right to left, filling in 1 values until val > input.
  - It then reverses, scanning left to right attempting to change the 1's to 2's
        if such a change keeps val < input. It at returns val = input.

SetBuild
  - This is a few lines of code used for a Theory of Computation hw question
  - I used it for finding equivalence classes for certain input sets

  
