from collections import deque

def main():
    S = deque(input())
    Q = int(input())
    rev_flag = False
    for _ in range(Q):
        query = input().split()
        if query[0] == "1":
            rev_flag = not(rev_flag)
            continue
        if query[1] == "1":
            if rev_flag:
                S.append(query[2])
            else:
                S.appendleft(query[2])
        else:
            if rev_flag:
                S.appendleft(query[2])
            else:
                S.append(query[2])
    
    if rev_flag:
        S.reverse()

    print("".join(list(S)))
        
if __name__ == "__main__":
    # print(timeit.timeit(lambda: main(), number=1))
    main()
