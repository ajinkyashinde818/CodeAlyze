def main():
    import numpy as np
    k, n = map(int, input().split())
    a = list(map(int, input().split()))
    b = np.array(a + [a[-1]+k-a[-1]+a[0]])
    c = np.diff(b)
    ans = sum(c) - max(c)

    print(ans)

if __name__ == '__main__':
    main()
