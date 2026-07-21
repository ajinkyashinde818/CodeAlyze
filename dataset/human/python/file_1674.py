import numpy as np
n, m = map(int, input().split())

img = np.array([list(input()) for i in range(n)])
w = img.shape[-1]
template = np.array([list(input()) for i in range(m)])
tw = template.shape[-1]

for y in range(n - m + 1):
    for x in range(w - tw + 1):
        if np.all(img[y:y + m, x:x + tw] == template):
            print("Yes")
            exit()
print("No")
