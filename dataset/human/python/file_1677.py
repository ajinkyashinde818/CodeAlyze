import numpy as np

N,M = map(int,input().split())

fig = []
for i in range(N):
  fig.append(list(input()))
fig = np.array(fig)
fig=np.where(fig ==".", 0, fig)
fig=np.where(fig =="#", 1, fig)
fig=fig.astype("int32")

template = []
for i in range(M):
  template.append(list(input()))
template = np.array(template)
template=np.where(template ==".", 0, template)
template=np.where(template =="#", 1, template)
template=template.astype("int32")

F = False
for i in range(fig.shape[0]-template.shape[0]+1):
  for j in range(fig.shape[1]-template.shape[1]+1):
    F = F|np.allclose(fig[i:i+template.shape[0],j:j+template.shape[1]] , template)

print("Yes" if F else "No")
