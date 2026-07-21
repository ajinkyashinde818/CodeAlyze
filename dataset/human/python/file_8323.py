from strutils import join, split, parseInt
from sequtils import map
from math import sum

var
  k, n, m, s, b: int

(k, n) = stdin.readLine.split(' ').map(parseInt)
let a = stdin.readLine.split(' ').map(parseInt)

m = 0
s = 0
for i in countup(0, n - 2):
  b = a[(i + 1) mod n] - a[i]
  s += b
  if b > m:
    m = b

b = (k - a[^1]) + a[0]
s += b
if b > m:
  m = b

echo($(s - m))
