import sys
def I(): return int(sys.stdin.readline())
def LI(): return [int(x) for x in sys.stdin.readline().split()]

def solv(a,b):
    a_ = a
    b_ = b
    while(a_%b_ != 0):
        a_,b_ = b_,a_%b_
    return a*b//b_
    
def main():
    A,B = LI()
    print(solv(A,B))

if __name__ == "__main__":
    main()
