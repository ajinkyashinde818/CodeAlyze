def solve(S):
    str_list = ["dream", "dreamer", "erase", "eraser"]
    n = 0
    while n < len(S):
        for s in str_list:
            if n:
                if S[:-n].endswith(s):
                    n += len(s)
                    break
            else:
                if S.endswith(s):
                    n += len(s)
                    break
        else:
            return False
    return True


S = input()
if solve(S):
    print("YES")
else:
    print("NO")
