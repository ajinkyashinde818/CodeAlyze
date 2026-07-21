from collections import deque

if __name__ == '__main__':
    s = input()
    q = int(input())
    ans = s
    rev_count = 0
    leftList = deque()
    rightList =[]
    alist =[]

    for i in range(q):
        a = [i for i in input().split()]
        alist.append(a)
        if len(a) == 1:
            rev_count = rev_count +1

    if rev_count % 2 ==1:
        ans = ans[::-1]

    for i in alist:
        if len(i) == 1:
            rev_count = rev_count -1
        else:
            if int(i[1]) == 1:
                if rev_count % 2 == 1:
                    rightList.append(i[2])
                else:
                    leftList.appendleft(i[2])

            else:
                if rev_count % 2 == 1:
                    leftList.appendleft(i[2])
                else:
                    rightList.append(i[2])

    ans = ''.join(leftList)+ ans+''.join(rightList)

    print(ans)
