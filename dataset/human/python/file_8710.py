import sys
i = []
for line in sys.stdin.readlines():
  i.append(line.rstrip().split(" "))

list_i1 = [int(s) for s in i[1]]

a = 0
distance = []
for list_i1[a] in list_i1:
  if a > len(list_i1)-2:
    break
  distance.append(list_i1[a+1] - list_i1[a]) 
  a += 1
c = 0
for b in distance:
  c += b
distance.append(int(i[0][0]) - c)

print(int(i[0][0]) - max(distance))
