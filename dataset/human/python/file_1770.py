def solve(n, m, NUM):
    for i in range(len(m)):
        if n[NUM + i] is not m[i]:
            return -1
    return 1


N, M = [int(i) for i in input().split()]
n_pic = [input() for i in range(N)]
m_pic = [input() for i in range(M)]
num = 0
if M is 1:
    for n in n_pic:
        if -1 is not n.find(m_pic[0]):
            print('Yes')
            exit()
    print('No')
    exit()

for n in range(N - M + 1):
    for n_len in range(N - M + 1):
        while -1 is not solve(n_pic[n + num], m_pic[num], n_len):
            num += 1
            if num is M:
                print('Yes')
                exit()
        num = 0
print('No')
