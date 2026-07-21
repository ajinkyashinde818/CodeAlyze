from collections import deque

def check(reverse_cnt, t):

    if reverse_cnt%2 == 0 and t == 1:
        return True
    elif reverse_cnt%2 == 0 and t == 2:
        return False
    elif reverse_cnt%2 == 1 and t == 1:
        return False
    elif reverse_cnt%2 == 1 and t == 2:
        return True

def solve(s, q, qs):
    reverse_cnt = 0

    for item in qs:

        if len(item) == 1:
            # T = 1 文字列を反転
            reverse_cnt += 1
        else:
            # T = 2

            if check(reverse_cnt, int(item[1])):
                # 先頭に追加
                s.appendleft(item[2])

            else:
                # 末尾に追加
                s.append(item[2])


    if reverse_cnt%2 == 1:
        ans = "".join(s)
        ans = ans[::-1]
    else:
        ans = "".join(s)

    return ans

if __name__ == '__main__':

    s = deque() # queue

    str = input()
    q = int(input())
    qs = [list(input().split()) for i in range(q)]

    s.append(str)

    ans = solve(s, q, qs)
    print(ans)
