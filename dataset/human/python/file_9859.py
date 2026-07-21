def mp():return map(int,input().split())
def lmp():return list(map(int,input().split()))

n,k = mp()
a = lmp()
a.insert(0,0)
here = 1
cnt = 0
hajimete = [0]*(n+1)
hajimete[0] = -1
used = set()
used.add(1)
flag = False
for i in range(k):
    cnt += 1
    here = a[here]
    if here not in used:
        used.add(here)
        hajimete[here] = cnt
    else:
        flag = True
        break
if not flag:
    print(here)
else:
    loop = cnt - hajimete[here]
    town = hajimete[here] + ((k-hajimete[here]) % loop)
    print(hajimete.index(town))
