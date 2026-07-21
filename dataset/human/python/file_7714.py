import sys
input = sys.stdin.readline

def I(): return int(input())
def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

def main():
    mod=10**9+7
    x=I()
    if x<1200:
        print("ABC")
    else:
        print("ARC")

main()
