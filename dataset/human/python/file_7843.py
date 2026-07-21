N, K, S = list(map(int, input().split()))

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

for i in range(2, 10**6):
    if gcd(S, i) == 1:
        break

ans = []
ans.extend([S for _ in range(K)])
ans.extend([i for _ in range(N-K)])

ans_str = ""
for j in range(len(ans)):
    ans_str += str(ans[j])
    ans_str += " "
ans_str = ans_str[:len(ans_str) - 1]
print(ans_str)
