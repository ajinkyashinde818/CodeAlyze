import sys
l = sys.stdin.readline().strip()
N, K = map(int, l.split())
l = sys.stdin.readline().strip()
A = [0] + list(map(int, l.split())) 
visited = [-1] * (len(A)+1)

remain = K
crt = 1
entrance = -1
while remain > 0:
    remain -= 1
    # check visited
    if visited[crt] == -1:
        visited[crt] = K - remain
        crt = A[crt]
    else:
        entrance = crt
        crt = A[crt]
        break
#print(entrance, remain)

if entrance == -1:
    print(crt)
else:
    loop = (K-remain) - visited[entrance] 
 
    later = remain % loop
    for i in range(later):
        crt = A[crt]
    print(crt)
