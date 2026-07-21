def main():
    S = input()
    Q = int(input())
    H = True
    A = ""  #
    B = ""
    for _ in range(Q):  # リストにしない
        q = list(input().split())
        if q[0] == "1": H = not H
        elif q[1] == "1" and H:     A = q[2] + A
        elif q[1] == "1" and not H:     B = B + q[2]
        elif q[1] == "2" and H:     B = B + q[2]
        elif q[1] == "2" and not H:     A = q[2] + A

    ans = A + S + B
    if H:   print(ans)
    else:   print(ans[::-1])

main()
