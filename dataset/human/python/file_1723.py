n,m = map(int,input().split())
a = [input() for _ in range(n)]
b = [input() for _ in range(m)]


def inputlist():
  return [int(j) for j in input().split()]


 
for i in range(n-m+1):
    for j in range(n-m+1):
        a1 = [a[k][j:j+m] for k in range(i,i+m)]
        if a1 == b:
            print('Yes')
            exit()
 
print('No')
