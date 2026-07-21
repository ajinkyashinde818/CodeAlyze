def main2():
    S = input()
    idx = 0
    while idx < len(S):
        if S[idx:].startswith("dream"):
            e = S[idx+5:idx+5+3]

            if len(e) == 3:
                if e.startswith("d") or e == "era":
                    idx += 5

                elif e == "erd" or e == "ere":
                    idx += 7
                    
                else:
                    idx += 5

            elif len(e) == 2:
                if e == "er":
                    idx += 7
                else:
                    idx += 5

            elif len(e) == 1:
                idx += 5
            
            else:
                idx += 5

        elif S[idx:].startswith("eraser"):
            idx += 6

        elif S[idx:].startswith("erase"):
            idx += 5

        else:
            print("NO")
            exit()

    print("YES")

if __name__ == "__main__":
    main2()
