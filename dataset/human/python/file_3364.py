import sys
import math
import copy
import numpy as np




def MinPrime(N, Prime):
    Max = math.ceil(math.sqrt(N))
    Min = Prime+1
    if(N%2 ==0):
        return 2


    Dev = 2
    if(Min%2==0):
        Min += 1
    for Num in range(Min, Max+1, Dev):
        if(N%Num == 0):
            return Num
    return N

def estimatePow(N, Prime):

    Pow = 0
    N_bef = N
    while(N%Prime==0):
        Pow+= 1
        N //= Prime
    # print(N_bef, N, Pow, Prime)
    return [Pow, N]

def estimateTimes(Pow):
    Times = math.floor(math.sqrt(Pow))
    Sum = (1+Times) * Times /2


    while(True):
        Sum *= (Times+2)/Times
        if(Pow < Sum):
            return Times
        Times += 1
    return Times
def calcOperateionTimes(N):
    Prime = 1
    Times = 0
    #Primes = seachPrimeNum(N)
    while(N > 1):
        # Prime = MinPrime(N, Prime)
        Prime= MinPrime(N, Prime)
        Pow_N = estimatePow(N, Prime)
        N = Pow_N[1]
        Times += estimateTimes(Pow_N[0])
    return Times

if(__name__ == "__main__"):

    N = int( input().strip() )



    Times = calcOperateionTimes(N)
    print(Times)
