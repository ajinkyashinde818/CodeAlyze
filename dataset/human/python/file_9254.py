def reverse_str(s):
    return ''.join(list(s)[::-1])


words = list(map(reverse_str, 'dream dreamer erase eraser'.split()))
S = reverse_str(input())
ok = True
while S:
    for r in range(5, 8):
        tmp = S[:r]
        if tmp in words:
            # print(S, end=' => ')
            S = S[r:]
            # print(S)
            break
    else:
        ok = False
        break
print('YES' if ok else 'NO')
