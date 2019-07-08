#4 out of 11 test cases failed.
#!/bin/python3

import math
import os
import random
import re
import sys

def no_of_steps(i, memo):
    if i < 0:
        return 0
    if i <= 2:
        return i
    if i == 3:
        return 4
    if memo[i - 1] == 0:
        memo[i - 1] = no_of_steps(i - 3, memo) + no_of_steps(i - 2, memo) + no_of_steps(i - 1, memo)
    return memo[i - 1]

# Complete the stepPerms function below.
def stepPerms(n):
    memo = [0] * n
    return no_of_steps(n, memo) % ((10 ** 9) + 7)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = int(input())

    for s_itr in range(s):
        n = int(input())

        res = stepPerms(n)

        fptr.write(str(res) + '\n')

    fptr.close()
