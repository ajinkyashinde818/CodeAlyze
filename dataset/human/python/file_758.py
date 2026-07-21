import sequtils, strutils, algorithm, math
when (NimMajor, NimMinor) <= (0, 18): import future else: import sugar
proc scanf(fmt: cstring){.header: "<stdio.h>", varargs.}
proc scan(): int = scanf("%lld", addr result)

let N, R = scan()

if N >= 10:
  echo R
else:
  echo(R + 100*(10-N))
