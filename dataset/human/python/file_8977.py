from collections import defaultdict,deque
import math
def main():
    s = input()
    lis = ["maerd", "remaerd", "esare", "resare"]
    s = s[::-1]

    i = 0
    while(i < len(s)-4):
        if(s[i:i+5] in lis):
            i+=5
        elif(i+7 <= len(s) and s[i:i+7]=="remaerd"):
            i += 7
        elif(i+6<=len(s) and s[i:i+6]=="resare"):
            i+=6
        else:
            print("NO")
            exit()
    print("YES")
if __name__ == '__main__':
    main()
