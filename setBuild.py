

import itertools

A = [-4, -3, -2, -1, 0, 1, 2, 3, 4]
R = []
count = 0
modvar = 4

for i in itertools.product(A,A):
    R.append(i)
    #print i

print ("Using % ",modvar," !!")

for pair in R:
    x,y = pair
    if ( ((x*x) - (y*y)) % modvar == 0):
        print (pair)
        count += 1

print (count)
