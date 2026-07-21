ops = input().strip()
x, y = map(int, input().split())

chunks = ops.split('T')
x -= len(chunks[0])
x_chunks, y_chunks = chunks[2::2], chunks[1::2]


def check(chunks, target):
    strides = [len(c) for c in chunks]
    adjusted_target = target + sum(strides)
    if adjusted_target < 0:
        return False
    dp = [False] * (adjusted_target + 1)
    dp[0] = True
    for stride in strides:
        newdp = dp[::]
        for i, v in enumerate(dp):
            if i + stride * 2 <= adjusted_target:
                newdp[i + stride * 2] |= dp[i]
        dp = newdp
    return dp[adjusted_target]


print("Yes" if check(x_chunks, x) and check(y_chunks, y) else "No")
