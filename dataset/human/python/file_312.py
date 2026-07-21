N = int(input())
A = list(map(int, input().split()))
counter = 0
m = []
def abab(l):
    for i in range(len(l)):
        m.append(abs(l[i]))
    return m

for i in range(N):
    if A[i] < 0:
        counter += 1
      
if counter % 2 == 1:
    m = abab(A)
    idx = m.index(min(m))
    m[idx] *= -1
    print(sum(m))
else:
    print(sum(abab(A)))
