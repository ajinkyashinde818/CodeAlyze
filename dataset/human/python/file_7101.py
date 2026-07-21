from collections import deque
import sys
input = lambda: sys.stdin.readline().rstrip() 
def main():
    moji=input()
    d=deque(moji)
    cycle=int(input())
    flont_or_back=0
    flont=""
    back=""
    for i in range(cycle):
        line=input()
        if line[0]=="1":
            flont_or_back+=1
        else:
            fi=line[2]
            ci=line[4]
            if flont_or_back%2==0:
                if fi=="1":
                    d.appendleft(ci)
                else:
                    d.append(ci)
            else:
                if fi=="1":
                    d.append(ci)
                else:
                    d.appendleft(ci)
    if flont_or_back%2==0:
        print("".join(d))
    else:
        d.reverse()
        print("".join(d))

if __name__ == '__main__':
    main()
