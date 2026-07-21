def judge(h, w):
    for i in range(b_h):
        for j in range(b_w):
            b_element = B[i][j]
            a_element = A[i+h][w+j]
            if a_element != b_element:
                return False
    return True

N, M = map(int, input().split())
A = [list(input()) for _ in range(N)]
B = [list(input()) for _ in range(M)]

a_h, a_w = N, len(A[0])
b_h, b_w = M, len(B[0])
max_h, max_w = a_h - b_h, a_w - b_w
ans = "No"
# 二重ループで左上のスタート地点を全探索する
for i in range(a_h):
    for j in range(a_w):
        if j > max_w or i > max_h:
            continue
        if judge(i, j):
            ans = "Yes"

print(ans)
