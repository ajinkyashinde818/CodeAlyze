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


proc nextInt: int =
   return parseInt nextString()


proc main: void =
   let A, B, C = nextInt()
   var ans = 0

   ans += min(A + B + 1, C)
   ans += B
   writeLine stdout, ans


when isMainModule:
   main()
