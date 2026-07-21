from math import sqrt
N = int(input())
flg = False
g = 0
for i in range(1,int(sqrt(2*N))+1):
    if (2*N) % i == 0:
        if abs(i - (2*N//i)) == 1:
            flg = True
            g = (2*N//i)
            break

if not flg:
    print("No")
    exit(0)


print("Yes")
print(g)
e = 2*N//g
output = [[] for _ in range(g)]

k = 0
l = 1
for i in range(1,N+1):
    output[k].append(i)
    output[l].append(i)
    l += 1
    if l == g:
        k += 1
        l = k + 1

for i in range(g):
    print(e , end=" ")
    print(*output[i])
