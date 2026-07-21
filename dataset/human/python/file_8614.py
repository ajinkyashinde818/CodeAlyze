def main():
  K, N = map(int, input().split())
  A = [int(a) for a in input().split()]
  maxK=0
  for i in range(1,N):
    maxK = max(maxK, A[i]-A[i-1])
  maxK = max(maxK, K+A[0]-A[N-1])
  print(K-maxK)

if __name__=='__main__':
  main()
