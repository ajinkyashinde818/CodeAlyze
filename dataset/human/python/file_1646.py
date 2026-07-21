import numpy as np

N, M = map(int, input().split())
n_img = []
m_img = []

for _ in range(N):
    n_img.append([0 if e == '#' else 1 for e in list(input())])
for _ in range(M):
    m_img.append([0 if e == '#' else 1 for e in list(input())])

n_img = np.array(n_img)
m_img = np.array(m_img)


def areSameM(m1, m2):
    s = np.sum(np.sum(abs(m1 - m2)))
    return s == 0


flag = False

for i in range(N - M):
    for j in range(N - M):
        if areSameM(n_img[i:i + M, j:j + M], m_img):
            flag = True
            break
    if flag:
        break

if N == M:
    flag = areSameM(n_img, m_img)

print('Yes' if flag else 'No')
