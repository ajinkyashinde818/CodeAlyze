def f(S):
    source_str = 'abcdefghijklmnopqrstuvwxyz'
    a = [0] * len(source_str)
    for i in range(len(a)):
        a[i] = S.count(source_str[i])
    
    n = 1
    for i in range(len(a)):
        n *= (a[i] + 1)


    return n

def g(S):
    fs = f(S)
    N = int(1e9) + 7
    return (fs + N - 1) % N




N = int(input())
S = input()

print(g(S))
