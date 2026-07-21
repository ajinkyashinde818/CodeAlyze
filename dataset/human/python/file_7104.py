from collections import deque
def main():
    S = deque(map(str, input()))
    Q = int(input())
    flag = False
    for _ in range(Q):
        A = tuple(map(str, input().split()))
        if A[0] == "1":
            flag = not(flag)
        else:
            if (A[1] == "1" and not(flag)) or (A[1] == "2" and flag):
                S.appendleft(A[2])
            else:
                S.append(A[2])
    if flag:
        print("".join(S)[::-1])
    else:
        print("".join(S))
if __name__ == "__main__":
    main()
