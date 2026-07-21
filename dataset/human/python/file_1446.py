import strutils, sequtils
let NM = stdin.readline.split.map(parseInt)
var n, m: seq[string] = @[]
for _ in 1 .. NM[0]: n.add(stdin.readline)
for _ in 1 .. NM[1]: m.add(stdin.readline)
for Ni in 0 ..< n.len:
  for Nj in 0 ..< n.len:
    block block_M:
      for Mi in 0 ..< m.len:
        for Mj in 0 ..< m.len:
          if Ni + Mi < n.len and Nj + Mj < n.len:
            if m[Mi][Mj] != n[Ni + Mi][Nj + Mj]:
              break block_M
          else:
            break block_M
      echo "Yes"; quit()
echo "No"
