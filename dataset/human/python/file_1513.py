n, m = [int(i) for i in input().split()]

def init_img(n):
    return [[0 if j == "#" else 1 for j in input()] for i in range(n)]

img = init_img(n)

tmp_img = init_img(m)

flg = False

for i in range(n):
    if flg:
        break

    if i+m > n:
        break

    for j in range(n):
        count = 0
        if j+m > n:
            break
        
        for k in range(m):
            if img[i+k][j:j+m] == tmp_img[k]:
                count += 1

        if count == m:
            flg = True

if flg:
    print("Yes")
else:
    print("No")
