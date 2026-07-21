n = input()
def main(n):
    n = [0] + [int(i) for i in n] + [0]
    last = 0
    ans = 0
    last_5 = 0
    ls = []
    for i in n[::-1]:
        if i > 5:
            if last == 0 and last_5 == 0:
                ans += 10 - i
                ls.append(10 - i)
            else:
                ans += 10 - i - 1
                ls.append(10 - i - 1)
            last += 1 + last_5
            last_5 = 0
        elif i == 5:
            if last == 0 and last_5 == 0:
                ans += 5
                last = 0
                last_5 = 1
                ls.append(5)
            else:
                ans += 10 - 5  - 1
                last += 1 + last_5
                last_5 = 0
                ls.append(4)
        else:
            if last >= 1:
                if i == 4:
                    ans += 5
                    last = 0
                    last_5 = 1
                    ls.append(5)
                    continue
                else:
                    ans += 1 + i
                    ls.append(1 + i)
            else:
                ans += i
                ls.append(i)
            last = 0
            last_5 = 0
    print(ans)

if __name__ == '__main__':
    main(n)
