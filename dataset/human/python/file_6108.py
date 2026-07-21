def f_b():
    n = int(input())
    a = list(map(lambda x: int(x)-1, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))
    s = b[a[0]]
    for i in range(1, n):
        s += b[a[i]]
        if a[i]==a[i-1]+1:
            s += c[a[i-1]]
    print(s)

if __name__ == "__main__":
    f_b()
