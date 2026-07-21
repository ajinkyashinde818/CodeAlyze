K, N = [int(x) for x in input().split(' ')]
A = [int(x) for x in input().split(' ')]

def pairwise_distance(a, b, K):
  return b - a 
  
memo = {frozenset({i, i+1}): pairwise_distance(A[i], A[i+1], K) 
        for i in range(0, len(A) - 1)}

last_pair_distance = K - pairwise_distance(A[0], A[len(A) - 1], K)
if last_pair_distance > K / 2:
  memo[frozenset({0, len(A) - 1})] = K - last_pair_distance
else:
  memo[frozenset({0, len(A) - 1})] = last_pair_distance

min_dist = K - max(memo.values())
print(min_dist)
