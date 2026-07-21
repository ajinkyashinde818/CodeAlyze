import string
if __name__=="__main__":
    s = list(input())
    t = list(input())
    min_s = 27
    max_t = 0
    dic = list(string.ascii_lowercase)
    c = 0
    for j in range(len(s)):
        if s[j] in t:
            c+=1
    if c==len(s) and c<len(t):
        print("Yes")
        exit()
    for i in string.ascii_lowercase:
        if s.__contains__(i):
            min_s = min(min_s,dic.index(i)+1)
        if t.__contains__(i):
            max_t = max(max_t,dic.index(i)+1)
    if max_t<=min_s:
        print("No")
    else:
        print("Yes")
