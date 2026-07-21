def solve(S):
        index = 0
        while index < len(S):
            if S[index] != "d" and S[index] != "e":
                print("NO")
                return
            if S[index] == "d":
                if index + 6 < len(S) and S[index:index+7] == "dreamer" and (index + 7 == len(S) or (S[index + 7] == "d" or S[index + 7] == "e")):
                    index += 7
                elif index + 4 < len(S) and S[index:index + 5] == "dream":
                    index += 5
                else:
                    print("NO")
                    return
            elif S[index] == "e":
                if index + 5 < len(S) and S[index:index + 6] == "eraser":
                    index += 6
                elif index + 4 < len(S) and S[index:index + 5] == "erase":
                    index += 5
                else:
                    print("NO")
                    return
        print("YES")



S = input()
solve(S)
