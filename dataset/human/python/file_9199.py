import sys
S = input()
length = len(S)
while 1:
    if length == 0:
        print("YES")
        sys.exit()
    elif S[length-7 : length] == "dreamer":
        length = length - 7
    elif S[length-5 : length] == "dream":
        length = length - 5
    elif S[length-5 : length] == "erase":
        length = length - 5
    elif S[length-6 : length] == "eraser":
        length = length - 6
    else:
        print("NO")
        sys.exit()
