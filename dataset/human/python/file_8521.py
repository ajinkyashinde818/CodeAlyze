from sys import stdin
input = stdin.readline


def main():
  K, N = list(map(int, input().split()))
  A = list(map(int, input().split()))

  SR = []
  for i in range(N-1):
    SR.append(A[i+1]-A[i])
  SR.append(K-A[N-1]+A[0])

  SL = [A[0]+K-A[N-1]]
  for i in range(N-1, 0, -1):
    SL.append(A[i]-A[i-1])

  print(min(sum(SR)-max(SR), sum(SL)-max(SL)))


if(__name__ == '__main__'):
  main()
