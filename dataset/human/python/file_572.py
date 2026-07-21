N = int(input())
A = list(map(int, input().split()))

def main():
    absA = [abs(a) for a in A]
    total = sum(absA)
    if 0 in A or not len([a for a in A if a < 0]) % 2:
        print(total) 
    else:
        print(total - 2*min(absA))

if __name__ == "__main__":
    main()
