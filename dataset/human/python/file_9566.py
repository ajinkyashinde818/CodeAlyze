import collections
n, k = map(int, input().split())
dat = list(map(int, input().split()))
maze = []
initmaze=[]
recurmaze=[]
used = [-1] * (n + 10)
cur = 0
cnt = 0
while True:
    if used[cur] != -1:
        break
    used[cur] = cnt
    maze.append(cur)
    cur = dat[cur] - 1
    cnt += 1

recurpoint = used[cur]
#print("return to ",recurpoint)
initmaze = maze[:recurpoint]
recurmaze = maze[recurpoint:]

#print(maze)
#print(initmaze)
#print(recurmaze)

l = len(maze)
li = len(initmaze)
lr = len(recurmaze)
if k < li:
    print(initmaze[k] + 1)
else:
    k -= li
    print(recurmaze[k%lr] + 1)
