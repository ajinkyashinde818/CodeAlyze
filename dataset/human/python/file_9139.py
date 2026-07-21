import copy

S = input()
strs = list(S)
strs.reverse()
targets = [list("maerd"), list("remaerd"), list("esare"), list("resare")]

cnt = -1
_targets = copy.copy(targets)
for i in range(len(strs)):
    s = strs[i]
    cnt += 1
    is_match = False
    __targets = copy.copy(_targets)
    for target in __targets:
        if len(target) <= cnt:
            continue
        if target[cnt] == s:
            is_match = True
            if len(target) - 1 == cnt:
                _targets = copy.copy(targets)
                cnt = -1
            break
        else:
            _targets.remove(target)
    if not(is_match):
        print("NO")
        exit()

print("YES")
