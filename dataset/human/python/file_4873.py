s = input()
t = input()
s = "".join(sorted(list(s)))
t = "".join(sorted(list(t),reverse=True))
import string
letter = list(string.ascii_lowercase)
for i in range(min(len(s), len(t))) :
    if letter.index(s[i]) == letter.index(t[i]) :
        continue
    elif letter.index(s[i]) < letter.index(t[i]) :
        ans = "Yes"
        break
    elif letter.index(s[i]) > letter.index(t[i]) :
        ans = "No"
        break
else :
    if len(s) < len(t) :
        ans = "Yes"
    elif len(s) >= len(t) :
        ans = "No"
print(ans)
