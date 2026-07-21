import numpy as np
if __name__ == "__main__":
    K, S = list(map(int, input().split()))
    ans = 0
    for i in range(K+1):
        for j in range(i, K+1):
            k = S - (i+j)
            if j <= k and k <= K:
                l = len(set([i,j,k]))
                if l == 3:
                    ans += 6
                elif l == 2:
                    ans += 3
                else:
                    ans += 1
    print(ans)
