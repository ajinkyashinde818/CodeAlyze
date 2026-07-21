D, G = map(int, input().split())
PnC = [list(map(int, input().split())) for x in range(D)]

counts = []
def calc(i, count, total, last):
  if G <= total:
    counts.append(count)
    return
  if i >= D:
    for x in range(PnC[last][0]):
      if G <= total + 100*x*(last+1):
        counts.append(count + x)
        return
    return
  calc(i+1, count, total, i)
  calc(i+1, count+PnC[i][0], total+PnC[i][1]+100*(i+1)*PnC[i][0], last)

calc(0, 0, 0, 0)
print(min(counts))
