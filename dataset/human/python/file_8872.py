import strutils


proc nextString: string =
   result = ""
   while not endOfFile stdin:
      let nextChar = readChar stdin
      case nextChar
      of '\r':
         discard
      of "\n"[0], ' ':
         break
      else:
         add result, nextChar


proc main: void =
   const dd = ["dream", "dreamer", "erase", "eraser"]
   let S = nextString()

   var cnt = 0
   var j = S.high

   for i in countdown(S.high, 0):
      if j - i > "dreamer".len:
         break
      for d in dd:         
         if S[i..j] == d:
            j = i - 1
            cnt += d.len

   writeLine stdout, if S.len == cnt: "YES" else: "NO"


if isMainModule:
   main()
