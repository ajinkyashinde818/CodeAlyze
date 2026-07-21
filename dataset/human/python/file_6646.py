def main():
    s = input()
    q = int(input())
    reverse_count = 0
    left = []
    right = []
    for _ in range(q):
        query = list(input().split())
        if query[0] == "1":
            reverse_count += 1
        else:
            if reverse_count % 2:
                if query[1] == "1":
                    right.append(query[2])
                else:
                    left.append(query[2])
            else:
                if query[1] == "1":
                    left.append(query[2])
                else:
                    right.append(query[2])
    print("".join(right[::-1]) + s[::-1] + "".join(left) if reverse_count % 2
          else "".join(left[::-1]) + s + "".join(right))


if __name__ == '__main__':
    main()
