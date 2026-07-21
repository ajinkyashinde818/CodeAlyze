def main():
    n=int(input())
    a=map(int,input().split())
    b=list(map(int,input().split()))
    c=list(map(int,input().split()))
    m = 0
    prev = -100
    for i in (x-1 for x in a):
        m += b[i]
        if prev + 1 == i:
            m += c[prev]
        prev = i
    return m

if __name__ == "__main__":
    print(main())
