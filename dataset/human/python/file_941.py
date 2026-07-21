import sequtils, strutils

const mo = 1_000_000_007

proc powmod(x: int, y=mo-2): int =
  result = 1
  var
    x = x
    i = 1
  while i<=y:
    if (i and y) != 0:
      result = result * x mod mo
    x = x*x mod mo
    i = i shl 1

var
  fact, inv: array[200_000+1, int]
fact[0] = 1
for i in 1..200_000:
  fact[i] = fact[i-1]*i mod mo
inv[200_000] = powmod(fact[200_000])
for i in countdown(200_000, 1):
  inv[i-1] = inv[i]*i mod mo

proc comb(n,r: int): int = fact[n] * inv[n-r] mod mo * inv[r] mod mo
proc perm(n,r: int): int = fact[n] * inv[n-r] mod mo

let
  n = stdin.readline.parseInt
  s = stdin.readline
var
  ds = newSeq[int](n*2)
  cnt: array[2, int]

inc cnt[0]
for i in 1..<(n*2):
  ds[i] = ds[i-1] xor int(s[i-1]==s[i])
  inc cnt[ds[i]]

# echo ds

var res = 1
if cnt[0] != cnt[1] or s[0] == 'W' or s[^1] == 'W':
  res = 0
var
  i = 0
  l,r = 0
while i < n*2:
  while i < n*2 and ds[i] == 0:
    inc l; inc i
  while i < n*2 and ds[i] == 1:
    inc r; inc i
  res = res * perm(l, r) mod mo
  l -= r
  r = 0
res = res * fact[n] mod mo

echo res
