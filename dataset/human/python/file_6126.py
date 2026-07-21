import lists, sequtils, strutils, algorithm, math, future

var unko = stdin.readLine.split.map(parseInt)
var A = unko[0] #gedoku, mazui
var B = unko[1] #gedoku, oisii
var C = unko[2] #doku, oisii

var re = 0

if A + B + 1 >= C:
  re = B + C
else:
  re = 2 * B + A + 1 

echo re
