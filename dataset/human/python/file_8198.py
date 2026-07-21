def main():
    k, s = map(int, input().split())
    ans = 0
    for z in range(s//3, k+1):
        for y in range((s-z)//2, s-z+1):
            x = s-z-y
            if x <= y and y <= z:
                if x == y and y == z:
                    ans += 1
                elif x == y or y == z:
                    ans += 3
                else:
                    ans += 6
    print(ans)


if __name__ == "__main__":
    main()
