import sequtils, strutils, future, math

let ks = stdin.readline.split.map(parseInt)
echo sum(lc[min(ks[1]-x, ks[0])-max(0, (ks[1]-ks[0]-x))+1 | (x <- max(0,ks[1]-2*ks[0])..min(ks[0], ks[1])), int])
