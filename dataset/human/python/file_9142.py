import sys
import re
sys.setrecursionlimit(10**7)
input = lambda: sys.stdin.readline().strip()

def main():
    S = input()
    words = ["eraser","erase","dreamer","dream"]
    for w in words:
        S = re.sub(w,"",S)
    if S=="":
        print("YES")
    else:
        print("NO")

main()
