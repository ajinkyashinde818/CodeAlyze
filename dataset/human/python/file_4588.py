import sys
import math
readline = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 8)
INF = float('inf')
MOD = 10 ** 9 + 7

def prime_factorize(n):
  arr = []
  temp = n
  for i in range(2, int(-(-n**0.5//1))+1):
    if temp%i==0:
        cnt=0
        while temp%i==0:
          cnt+=1
          temp //= i
        arr.append([i, cnt])
  if temp!=1:
    arr.append([temp, 1])
  if arr==[]:
    arr.append([n, 1])
  return arr

def main():
    N = int(readline())
    if N==0 or N==1:
        print('0')
        sys.exit()
    sosu = prime_factorize(N)
    L = len(sosu)
    count = 0
    for i in range(L):
        _, a = sosu[i]
        count += math.floor((math.sqrt(1+8*a)-1)/2)
    print(count)

if __name__ == '__main__':
    main()
