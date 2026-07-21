n, m = map(int, input().split())


def is_ok(A, B):
    for i in range(n - m + 1):
        for j in range(n - m + 1):
            C = []
            for k in range(i, i + m):
                line = ""
                for l in range(j, j + m):
                    line += A[k][l]
                C.append(line)
            # print(C)
            if C == B: return True
    return False


A = []
B = []
for i in range(n):
    A.append(input())

for i in range(m):
    B.append(input())
# print(A)
# print(B)
if is_ok(A, B):
    print("Yes")
else:
    print("No")
