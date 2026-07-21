def main():
    s = list(input())
    wox = [i for i in s if i != "x"]
    if len(wox) == 0: return 0
    wowr = list(reversed(wox))
    for i in range(len(wox)//2+1):
        if wox[i] != wowr[i]:
            return -1
    sr = list(reversed(s))
    si = ri = 0
    ret = 0
    while si < len(s) and ri < len(sr):
        if s[si] == sr[ri]:
            si += 1
            ri += 1
        elif s[si] == "x":
            si += 1
            ret += 1
        else:
            ri += 1
            ret += 1
    return (ret + len(s) - min(si,ri))//2
print(main())
