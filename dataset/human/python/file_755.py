import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

from functools import reduce
import operator
from scipy.sparse import csr_matrix
from scipy.sparse.csgraph import connected_components

N = int(readline())
A = list(map(int,readline().split()))
B = list(map(int,readline().split()))

a_xor = reduce(operator.xor,A)
b_xor = reduce(operator.xor,B)

if any(x != y for x,y in zip(sorted(A + [a_xor]),sorted(B + [b_xor]))):
    print(-1)
    exit()

Adiff = [x for x,y in zip(A,B) if x != y]
Bdiff = [y for x,y in zip(A,B) if x != y]
x_to_i = {x:i for i,x in enumerate(set(Adiff + [a_xor]))}
row = [x_to_i[x] for x in Adiff]
col = [x_to_i[x] for x in Bdiff]
if a_xor != b_xor:
    row.append(x_to_i[a_xor])
    col.append(x_to_i[b_xor])
V = len(x_to_i)
graph = csr_matrix(([1]*len(row),(row,col)),(V,V))
Ncomp,comp = connected_components(graph)

counter = [0] * Ncomp
for x in Adiff:
    counter[comp[x_to_i[x]]] += 1
c = comp[x_to_i[a_xor]]
counter[c] += 1

answer = sum(x+1 for x in counter) - 2
print(answer)
