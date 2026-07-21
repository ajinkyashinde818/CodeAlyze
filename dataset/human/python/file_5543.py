import sys

sys.setrecursionlimit(10 ** 6)
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")

def main():
    x,y=input().split()
    if x<y:print("<")
    if x==y:print("=")
    if x>y:print(">")

main()
