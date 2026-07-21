def resolve():
  K, N = [int(i) for i in input().split()]
  A = tuple(int(i) for i in input().split())
  
  distance = [A[i+1] - A[i] for i in range(len(A)-1)]
  distance.append(K - A[-1] + A[0])
  print(K - max(distance))
resolve()
