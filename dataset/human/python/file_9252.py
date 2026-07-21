import sys
S = input()
S = S[::-1]
N = len(S)
words = ['maerd', 'remaerd', 'esare', 'resare']
i = 0
while i != N:
    flag = 1
    for word in words:
        if S[i:i+len(word)] == word:
            flag = 0
            i += len(word)
    if flag:
        print('NO')
        sys.exit()
print('YES')
