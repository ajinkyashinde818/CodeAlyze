import string


S = list(input())
T = list(input())

L = list(string.ascii_lowercase)

S = [L.index(s) for s in S]
T = [L.index(t) for t in T]

S.sort()
T.sort()
T.reverse()

while True:
    if len(S) == 0:
        if len(T) > 0:
            print('Yes')
            break
        else:
            print('No')
            break
    if len(T) == 0:
        print('No')
        break
    s = S[0]
    t = T[0]
    if s < t:
        print('Yes')
        break
    elif s == t:
        del S[0]
        del T[0]
    else:
        print('No')
        break
