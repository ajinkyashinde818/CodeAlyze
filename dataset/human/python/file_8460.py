import math

S =  list(map(int,input().split()))
K = S[0]
N = S[1]
P =  list(map(int,input().split()))
R = []
for i in range(len(P)):
    if i >= 1:
        X = P[i]-P[i-1]
        R.append(X)
        if i == N-1:
            X = K + P[0] - P[i]
            R.append(X)
B = max(R)
answer = K-B        
print(answer)
