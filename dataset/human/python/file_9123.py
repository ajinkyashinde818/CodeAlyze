S = str(input())
def detect_dream(string):
    assert string[0] == "d"
    if string[:5] != "dream":
        return False, ""
    if len(string) >= 8:
        if string[:8] in ["dreamere", "dreamerd"]:
            return True, "dreamer"
    if string == "dreamer":
        return True, "dreamer"
    return True, "dream"

def detect_erase(string):
    assert string[0] == "e"
    if string[:5] != "erase":
        return False, ""
    if len(string) >= 6:
        if string[:6] == "eraser":
            return True, "eraser"
    return True, "erase"

while len(S) >= 5:
    if S[0] == "d":
        result, string = detect_dream(S)
    elif S[0] == "e":
        result, string = detect_erase(S)
    else:
        break
    if result:
        S = S.replace(string,"",1)
    else:
        break
if len(S) == 0:
    print("YES")
else:
    print("NO")
