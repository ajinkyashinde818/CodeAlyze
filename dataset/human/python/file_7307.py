def main():
    s = input()
    q = int(input())
    flag = 0
    cnt = 0
    front = []
    back = []

    for i in range(q):
        t = input()
        if len(t) == 1:
            cnt += 1
            if flag == 0:
                flag = 1
            elif flag == 1:
                flag = 0
        else:
            _, a, b = (str(i) for i in t.split())
            if a == "1":
                if flag == 0:
                    front.append(b)
                elif flag == 1:
                    back.append(b)
            elif a == "2":
                if flag == 0:
                    back.append(b)
                elif flag == 1:
                    front.append(b)

    if cnt % 2 == 0:
        front = front[::-1]
        s = ''.join(front) + s + ''.join(back)
    else:
        back = back[::-1]
        s = ''.join(back) + s[::-1] + ''.join(front)

    print(s)

if __name__ == '__main__':
    main()
