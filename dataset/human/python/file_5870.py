def read():
    return [int(e) for e in input().split(" ")]

N = int(input())
Data = [read() for _ in range(3)]
m = 0
b = -2

for e_A in Data[0]:
    m += Data[1][e_A - 1]
    if(e_A == b + 1):
        m += Data[2][b - 1]
    b = e_A

print(m)
