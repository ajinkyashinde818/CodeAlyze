import itertools

TS = ['dream','dreamer','erase','eraser']
I = itertools.permutations(TS)
L = list(I)

S = raw_input()
res = []
for i in range(len(L)):
    Sn = S
    for j in range(4):
        Sn = Sn.replace(L[i][j],"")
    res.append(len(Sn))

if min(res) == 0:
    print "YES"
else:
    print "NO"
