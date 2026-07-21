def is_valid():
    x_removed_S = S.replace("x", "")
    M = len(x_removed_S)
    for i in range(M // 2):
        if x_removed_S[i] != x_removed_S[M - i - 1]:
            return False
    return True


S = input()
N = len(S)
if is_valid():
    ans = 0
    left, right = 0, N - 1
    while left < right:
        if S[left] == S[right]:
            left += 1
            right -= 1
            continue
        elif S[left] == "x":
            ans += 1
            left += 1
        else:
            ans += 1
            right -= 1
    print(ans)
else:
    print(-1)
