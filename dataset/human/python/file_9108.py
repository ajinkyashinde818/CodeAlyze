def main():
    divs = ["dream", "dreamer", "erase","eraser"]

    S = input()

    rev_S = S[::-1]
    
    rev_divs = [div[::-1] for div in divs]
    
    i = 0
    while(1):
        can = False
        for rev_div in rev_divs:
            if rev_S[i:(i+len(rev_div))] == rev_div:
                can = True
                i += len(rev_div)

                if i == len(rev_S):
                    print("YES")
                    return 
        
        if not can:
            print("NO")
            return

main()
