S = input()

S_inv = S[::-1]

def judge(S):
    cursor = 0
    len_S = len(S)
    
    while cursor < len_S:
        next_str = S[cursor:cursor+7]
        if next_str[:] == "remaerd":
            cursor += 7
        elif next_str[:6] == "resare":
            cursor += 6
        elif next_str[:5] == "esare":
            cursor += 5
        elif next_str[:5] == "maerd":
            cursor += 5
        else:
            return False
        
    if cursor != len_S:
        return False
    
    return True

if judge(S_inv):
    print("YES")
else:
    print("NO")
