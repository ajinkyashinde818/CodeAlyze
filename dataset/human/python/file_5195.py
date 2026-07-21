n,m = map(int,input().split())

pre = [0 for i in range(n+1)]
post = [0 for i in range(n+1)]
for _ in range(m):
    a,b = map(int,input().split())
    if a == 1:
        pre[b] = 1
    if b == n:
        post[a] = 1

for pr, po in zip(pre, post):
    if pr == 1 and po == 1:
        print("POSSIBLE")
        import sys
        sys.exit()

print("IMPOSSIBLE")
