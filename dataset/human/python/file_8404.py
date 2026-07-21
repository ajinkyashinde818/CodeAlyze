url = "https://atcoder.jp//contests/abc160/tasks/abc160_c"

def main():
    lake, house = list(map(int, input().split()))
    dis = list(map(int, input().split()))
    ans = []
    for i in range(1, len(dis)):
        ans.append(dis[i] - dis[i - 1])
    ans.append(lake - dis[-1] + dis[0])
    print(sum(ans) - max(ans))

if __name__ == '__main__':
    main()
