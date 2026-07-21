def zero_index(i: str) -> int:
  return int(i) - 1

n, k = map(int, input().split())
transition = list(map(zero_index, input().split()))
places = [0]
next_place = transition[0]
virgin = [True] * n
virgin[0] = False
while virgin[next_place]:
  virgin[next_place] = False
  places.append(next_place)
  next_place = transition[next_place]
start = places.index(next_place)
period = len(places) - start
if k < start:
  t = k
else:
  t = (k - start) % period + start
print(places[t] + 1)
