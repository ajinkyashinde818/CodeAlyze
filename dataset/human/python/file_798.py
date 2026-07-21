import sys
input = sys.stdin.readline
input = sys.stdin.buffer.readline

def RD(): return sys.stdin.read()
def II(): return int(input())
def MI(): return map(int,input().split())
def LI(): return list(map(int,input().split()))
def TI(): return tuple(map(int,input().split()))


def main():
    N,R = MI()
    ans = R + 100*(10-N)

    if N<10:
        print(ans)
    else:
        print(R)



if __name__ == "__main__":
	main()
