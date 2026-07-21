import sys
buf = sys.stdin.buffer

n, m = map(int, buf.readline().split())
AB = map(int, buf.read().split())

reachable_from_start = set()
reachable_to_goal = set()
for a, b in zip(AB,AB):
    if a == 1:
        reachable_from_start.add(b)
    if b == n:
        reachable_to_goal.add(a)

possible = reachable_from_start & reachable_to_goal
if possible or n in reachable_from_start:
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")
