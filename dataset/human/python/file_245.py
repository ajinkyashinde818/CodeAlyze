hex_to_dig = {"0":"0000", "1":"0001", "2":"0010", "3":"0011",
              "4":"0100", "5":"0101", "6":"0110", "7":"0111",
              "8":"1000", "9":"1001", "a":"1010", "b":"1011",
              "c":"1100", "d":"1101", "e":"1110", "f":"1111"}
def dig_to_dec(digit):
  tf = digit[0]
  x = digit[1:25][::-1]
  y = digit[25:32]
  
  sumx = 0
  acc = 1
  for i, c in enumerate(x):
    if c == "1":
      sumx += acc
    acc *= 2
  
  sumy = 0
  acc = 0.5
  for i, c in enumerate(y):
    if c == "1":
      sumy += acc
    acc /= 2
  
  tf = "-" if int(tf) == 1 else ""
  if sumy == 0:
    print(tf + str(sumx) + "." + "0")
  else:
    print(tf + str(sumx + sumy))

n = int(input())
for _ in range(n):
  h = input()
  d = ""
  for c in h:
    d += hex_to_dig[c]
  dig_to_dec(d)
