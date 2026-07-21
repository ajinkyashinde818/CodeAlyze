def main(S):
    
    words = ["dream",  "dreamer",  "erase",  "eraser"]

    idx = 0
    while idx <= len(S) - 1:
        f = False
        for word in words:
            if idx != 0 and word == S[-len(word) - idx : -idx]:
                idx += len(word)
                f = True
            elif idx == 0 and word == S[-len(word) - idx : ]:
                idx += len(word)
                f = True             

        if not f:
            return False
    return True
        

if __name__ == "__main__":
    S = input()
    if main(S):
        print("YES")
    else:
        print("NO")
