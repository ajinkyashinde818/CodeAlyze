import sequtils, unicode

var
  s = readLine(stdin)
  str = @["dream", "dreamer", "erase", "eraser"]

s = s.reversed
str = str.map(proc (x: string): string = x.reversed)

while s != "":
  var update = false
  for now in str:
    if s.len < now.len:
      continue
    elif s.substr(0, now.len - 1) == now:
      s = s.substr(now.len, s.len - 1)
      update = true    
  if update == false:
    break

if s == "":
  echo "YES"
else:
  echo "NO"
