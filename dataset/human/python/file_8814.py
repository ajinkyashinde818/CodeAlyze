import sys
read = sys.stdin.read
def main():
    k, n = map(int, input().split())
    a = tuple(map(int, input().split()))
    dis_max = (k - a[-1]) + a[0]
    for i1 in range(1, n):
        dis = a[i1] - a[i1-1]
        dis_max = max(dis_max, dis)
    print(k - dis_max)
if __name__ == '__main__':
    main()
