def solve():
    while 1:
        try:
            s = list(input())
            s.reverse()
            s = "".join(s)
            if len(s) < 5:
                raise EndLoop

            l = 0
            r = 5
            while r <= len(s):
                if s[l:r] == "maerd" or s[l:r] == "esare":
                    l += 5
                    r += 5
                elif s[l:r] == "remae":
                    if s[l:r + 2] == "remaerd":
                        l += 7
                        r += 7
                    else:
                        raise EndLoop
                elif s[l:r] == "resar":
                    if s[l:r + 1] == "resare":
                        l += 6
                        r += 6
                    else:
                        raise EndLoop
                else:
                    raise EndLoop

            print("YES")
            break
        except:
            print("NO")
            break


solve()
