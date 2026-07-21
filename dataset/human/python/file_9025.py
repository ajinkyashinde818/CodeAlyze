import sys
S = input()
S = S[::-1]
substring_list = ['maerd', 'remaerd', 'esare', 'resare']
i = 0
while i < len(S):
    ok = False
    for substring in substring_list:
        if S[i:i+len(substring)] == substring:
            i += len(substring)
            ok = True
            break
    if not ok:
        print('NO')
        sys.exit()
print('YES')
