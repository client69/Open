__username__ = 'aishitdua'
# Hackerrank problem url: https://www.hackerrank.com/challenges/larrys-array/problem
import math
import os
import random
import re
import sys
import copy
def larrysArray(realList):
    """
    Input: List unsorted
    Output: If list can be sorted using only rotation of 3 consecutive elements
    """
    sortedList = copy.copy(realList)
    sortedList.sort()
    listLen = len(sortedList)
    for i in range(listLen - 2):
        if realList[i] == sortedList[i]:
            continue
        myInd = realList.index(sortedList[i])
        while myInd > i:
            if myInd == listLen - 1:
                temp = realList[myInd - 2]
                realList[myInd - 2] = realList[myInd - 1]
                realList[myInd - 1] = realList[myInd]
                realList[myInd] = temp
            else:
                temp = realList[myInd - 1]
                realList[myInd - 1] = realList[myInd]
                realList[myInd] = realList[myInd + 1]
                realList[myInd + 1] = temp
            myInd -= 1
    if realList[listLen - 1] == sortedList[listLen - 1]:
        #print("YES")
        return "YES"
    else:
        #print("NO")
        return "NO"
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        n = int(input())

        A = list(map(int, input().rstrip().split()))

        result = larrysArray(A)

        fptr.write(result + '\n')

    fptr.close()
