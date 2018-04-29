# Phil Tenteromano 3/14/2018 Theory hw problem
# converting decimal into binary
# except this binary is only 1 and 2
# ex: 32 = 11112
# ex: 9 = 121
import sys

def convertNum(num):
    digit = 0       # the exponent (2^0, 2^1,...,2^n)
    value = 0       # value of sequence
    binNum = 1      # either 1 or 2
    sequence = []   # the binary sequence

    while(True):
        temp = binNum * (2**digit) # temp is the single digit value
        if binNum == 2:     # the difference from 1 to 2 is 1/2 of 2
            temp /= 2

        newTotal = value + temp       # keep track of the total bin value

        # move up adding with 1's
        if binNum == 1:
            if newTotal <= num:
                sequence.append(binNum)
                value = newTotal
                digit += 1
            else:
                digit -= 1
                binNum = 2

        # move down adding with 2's
        elif binNum == 2:
            if newTotal <= num:
                sequence[digit] = binNum
                value = newTotal
                digit -= 1
            else:
                digit -= 1

        if value == num:    # check to return
            sequence.reverse()
            return sequence

# testing with whatever you want (cmd line arguments)
x = int(sys.argv[1])        # 23 is 2 1 1 1
                            # 51 is 2 1 2 1 1
binSeq = convertNum(x)

for z in binSeq:     # printing on one line
    print(z,end=' ')

print('\n')
