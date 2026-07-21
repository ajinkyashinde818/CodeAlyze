import sys
S = sys.stdin.readline().rstrip()
L = []
R = []
rev = 0
for _ in range(int(sys.stdin.readline().rstrip())):
    A = sys.stdin.readline().rstrip().split()
    if A[0] == "1":
        rev ^= 1
    else:
        if (int(A[1]) ^ rev) & 1:
            L.append(A[2])
        else:
            R.append(A[2])

if rev:
    print("".join(R[::-1]) + S[::-1] + "".join(L))
else:
    print("".join(L[::-1]) + S + "".join(R))
