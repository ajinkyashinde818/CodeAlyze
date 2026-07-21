from pprint import pprint
n,m = map(int, input().split())
a = list()
for i in range(n):
    a.append(input())
b = list()
for i in range(m):
    b.append(input())
a_len = len(a[0])
b_len = len(b[0])
for i in range(a_len-b_len+1):
    for j in range(n-m+1):
        check = True
        for k in range(m):
            if a[k+j][i:i+b_len] == b[k]:
                pass
            else:
                check = False
                break
        if check == True:
            print("Yes")
            exit()
print("No")
