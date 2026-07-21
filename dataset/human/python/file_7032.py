import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline
s = readline().rstrip()
q = int(readline())
queries = [[i for i in readline().split()] for _ in range(q)]

t = ''

for query in queries:
    if query[0] == '1':
        s,t = t,s
    else:
        if query[1] == '1':
            t += query[2]
        else:
            s += query[2]
            
print(t[::-1]+s)
