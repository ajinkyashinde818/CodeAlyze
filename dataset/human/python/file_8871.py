import sequtils, strutils, math, algorithm, tables

var
  s = readLine(stdin)

if s.replace("eraser", "").replace("erase", "").replace("dreamer", "").replace("dream", "").len == 0:
  echo "YES"
else:
  echo "NO"
