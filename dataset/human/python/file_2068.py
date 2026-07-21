from collections import defaultdict

n = int(input())
s = input()

mod = int(1e9+7)

c_map = defaultdict(int)
for c in s:
    c_map[c] += 1

ans = 1
for cnt in c_map.values():
 	if cnt == 1:
 		ans *= 2
 	else:
 		ans *= (cnt+1)

 	if ans > mod:
 		ans %= mod

print(ans-1)
