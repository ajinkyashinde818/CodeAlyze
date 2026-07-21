from collections import defaultdict

n = int(input())

for i in range(2, 450):
    if n == i * (i - 1) // 2:
        break
else:
    print("No")
    exit()

num_apexes = i

edge_dict = defaultdict(list)

for i in range(num_apexes):
    for j in range(num_apexes):
        if i == j:
            continue
        edge_dict[i].append(j)

used = set([])
sets = defaultdict(list)
count = 1
for s in edge_dict.keys():
    for e in edge_dict[s]:
        if (s, e) in used or (e, s) in used:
            sets[s].append(str(count))
            sets[e].append(str(count))
            count += 1
        else:
            used.add((e, s))

print('Yes')
print(num_apexes)
for i in sets.keys():
    words = [str(len(sets[i])),] + sets[i]
    print(' '.join(words))
