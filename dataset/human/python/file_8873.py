import strutils, sequtils

proc reverse(s: string): string =
  result = ""
  for i in countdown(s.len - 1, 0):
    result.add(s[i])

proc main() =
  let s = stdin.readLine.strip.reverse
  let words = @["dream", "dreamer", "erase", "eraser"].mapIt(it.reverse)
  var i = 0
  while i < s.len:
    var found = false
    for w in words:
      if s[i..^1].startsWith(w):
        i += w.len
        found = true
        break
    if not found:
      echo "NO"
      return
  echo "YES"
main()
