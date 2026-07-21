def main():
    s = input()
    q = int(input())
    left = ""
    right = ""
    hanten = False
    for i in range(q):
        query = input().split()
        if query[0] == "1":
            hanten = not hanten
        else:
            c = query[2]
            if query[1] == "1":
                if not hanten:
                    left = "".join([left,c])
                else:
                    right = "".join([right,c])
            else:
                if not hanten:
                    right =  "".join([right,c])
                else:
                    left = "".join([left,c])
        #print(query)
        #print(s,left,right)
    left = left[::-1]
    answer = left + s + right

    if not hanten:
        print(answer)
    else:
        print(answer[::-1])


if __name__ == '__main__':
    main()
