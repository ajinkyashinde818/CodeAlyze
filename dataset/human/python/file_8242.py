s = raw_input()
fx, fy = map(int, raw_input().split())

def possible(x, nums):
    x = abs(x)
    dp1 = [False] * (x + 1)
    dp2 = [False] * (x + 1)
    dp1[0] = True
    for y in nums:
        for i in range(len(dp2)):
            dp2[i] = False
            if i >= y:
                dp2[i] |= dp1[i - y]
            if i + y < len(dp2):
                dp2[i] |= dp1[i + y]
        dp1, dp2 = dp2, dp1
    return dp1[x]

def solve(s, fx, fy):
    try:
        first = s.index('T')
    except:
        return fy == 0 and fx == len(s)
    fx -= first
    s = s[first:]
    ts = []
    for i in range(len(s)):
        if s[i] == 'T':
            ts.append(i)
    ts.append(len(s))
    nums = map(lambda i: ts[i + 1] - ts[i] - 1, range(len(ts) - 1))
    x_nums = []
    y_nums = []
    for i in range(len(nums)):
        if i % 2 == 0:
            y_nums.append(nums[i])
        else:
            x_nums.append(nums[i])
    return possible(fx, x_nums) and possible(fy, y_nums)

print 'Yes' if solve(s, fx, fy) else 'No'
