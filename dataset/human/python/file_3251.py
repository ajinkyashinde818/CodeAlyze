def factorization(n):
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
  import collections
  N = int(input())
  if N == 1:
    print(0)
  else:
    K = factorization(N)
    Count = 0
    for i in range(len(K)):
      A = K[i][0]
      B = K[i][1]
      C = 1
      D = 2
      while B >= C:
        C += D
        D += 1
        Count += 1
    print(Count)
main()
