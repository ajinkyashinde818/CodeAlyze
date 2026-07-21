import sys
n, m = map(int, input().split())
    
array1 = [list(input()) for _ in range(n)]
array2 = [list(input()) for _ in range(m)]
    
for i in range(n-m+1):
    for j in range(n-m+1):
        for k in range(m):
            if array1[i+k][j:j+m] != array2[k][:]:
                break
        else:
            print("Yes")
            sys.exit()
print("No")
