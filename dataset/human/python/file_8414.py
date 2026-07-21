import copy

l = int(input().split()[0])
lh = int(l / 2)
houses = list(map(int, input().split()))

houses2 = copy.deepcopy(houses)
houses2.append(houses2[0])
houses2 = houses2[1::]
distances = [abs(h1 - h2) for (h1, h2) in zip(houses, houses2)]
route = sum(sorted([abs(d - l) if d > lh else d for d in distances])[:-1:])

print(route)
