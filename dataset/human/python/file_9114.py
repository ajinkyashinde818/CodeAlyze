def main():
    s = input()
    dream = 0
    erase = 1
    work = []
    temp1 = 0
    temp2 = 0
    kind = -1
    append = work.append
    for c in s:
        if c == 'd':
            if kind != -1:
                append([kind, temp2-temp1])
            kind = dream
            temp1 = temp2
        elif c == 's':
            if kind != -1:
                append([kind, temp2-temp1-3])
            kind = erase
            temp1 = temp2-3
        temp2 += 1
    append([kind, len(s)-temp1])
    result = []
    append = result.append
    for i, j in work:
        if i == dream:
            if j <= 5:
                append("dream")
            else:
                append("dreamer")
        else:
            if j <= 5:
                append("erase")
            else:
                append("eraser")
    result = "YES" if "".join(result)==s else "NO"
    print(result)
main()
