def main():
    s = input()
    q = int(input())
    reverse = 0
    head = ""
    tail = ""
    for _ in range(q):
        query = input().split()
        if query[0] == "1":
            reverse = not(reverse)
        else:
            if (reverse^int(query[1]))&1:
                head += query[2]
            else:
                tail += query[2]
    s = head[::-1] + s + tail
    if reverse&1:
        print(s[::-1])
    else:
        print(s)
if __name__ == "__main__":
    main()
