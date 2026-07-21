import strutils, unicode
var
  S = stdin.readLine
  Q = stdin.readLine.parseInt
  r = 0
  (fs, bs) = ("", "")
for _ in 1 .. Q:
  let q = stdin.readLine.split
  let t = q[0].parseInt
  if t == 1: r = r xor 1
  else:
    let (f, c) = (q[1].parseInt, q[2])
    if r == f - 1: fs.add(c) else: bs.add(c)
var ans = fs.reversed & S & bs
echo if r == 1: ans.reversed else: ans
