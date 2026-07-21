S = input()

def solve(T) :
    while 1:
        flag = True
        for i in ("dream", "dreamer", "erase", "eraser"):
            if T.endswith(i):
                T = T[: -len(i)]
                flag = False
                break
        
        if flag:
            print("NO")
            break
        
        if len(T) == 0:
            print("YES")
            break

solve(S)
