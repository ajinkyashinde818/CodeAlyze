"""
AtCoder Beginner Contest 051
B - Sum of Three Integers
"""

if __name__ == "__main__":
    K, S = map(int, input().split())

    ans = 0
    A = [i for i in range(K+1)]
    for x in A:
        for y in A:
            if x + y > S or S - (x + y) > K:
                continue
            ans += 1

    print(ans)
