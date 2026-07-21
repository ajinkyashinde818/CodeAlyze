import numpy as np
d, g = map(int, input().split())
p = []
c = []
for _ in range(d):
    _p, _c = map(int, input().split())
    p.append(_p)
    c.append(_c)

s = np.arange(1, d + 1) * 100
p = np.array(p)

ans_list = []

bool_list = [False] * d

state_list = []

def dfs(i, n, bool_list):
    bool_list = bool_list.copy()
    if i == n:
        state_list.append(bool_list)
    else:
        dfs(i + 1, n, bool_list)
        bool_list[i] = True
        dfs(i + 1, n, bool_list)

dfs(0, d, bool_list)

for state in state_list:
    if np.dot(s * p, state) + np.dot(c, state) >= g:
        ans_list.append(np.dot(p, state))
    else:
        score = max(s * np.array([not i for i in state]))
        for j in range(1, p[score//100 - 1] + 1):
            if np.dot(s * p, state) + np.dot(c, state) + score * j >= g:
                ans_list.append(np.dot(p, state) + j)

print(min(ans_list))
