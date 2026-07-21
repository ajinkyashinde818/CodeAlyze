import strutils, sequtils, sets

let
  tmp = map(split readLine stdin, parseInt)
  (N, M) = (tmp[0], tmp[1])
var
  s, e = initSet[int]()

for i in 1 .. M:
  let a_b = map(split readLine stdin, parseInt)

  for j, v in a_b:
    if v == 1:
      incl s, a_b[j xor 1]
    if v == N:
      incl e, a_b[j xor 1]

if len(s * e) == 0: write stdout, "IM"
echo "POSSIBLE"
