import queue

divide = ["dream", "dreamer", "erase", "eraser"]

S = input()

BFS = queue.Queue()

can = False

BFS.put(0)

while not BFS.empty():
    t = BFS.get()
    if (t == len(S)):
        can = True
        break
    for s in divide:
        if s == S[t: t + len(s)]:
            BFS.put(t + len(s))

if can is True:
    print("YES")
else:
    print("NO")
