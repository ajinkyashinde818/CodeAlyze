import sequtils,strutils, algorithm,math

var
  s = toSeq(readLine(stdin).items)
  t = toSeq(readLine(stdin).items)
  s_dash: string
  t_dash: string

s = s.sorted(system.cmp[char])
t = t.sorted(system.cmp[char]).reversed()
proc toString(str: seq[char]): string =
  result = newStringOfCap(len(str))
  for ch in str:
    add(result, ch)
s_dash = toString(s)
t_dash = toString(t)
if s_dash < t_dash:
  echo "Yes"
else:
  echo "No"
