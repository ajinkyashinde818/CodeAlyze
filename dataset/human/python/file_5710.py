import sys
import numpy as np


def main():
    s = input()
    snotx = s.replace('x', '')
    if snotx != snotx[::-1]:
        print(-1)
        sys.exit()
    ans = 0
    ileft = 0
    iright = len(s) - 1
    while ileft < iright:
        if s[ileft] != s[iright]:
            if s[ileft] == 'x':
                ans += 1
                ileft += 1
            elif s[iright] == 'x':
                ans += 1
                iright -= 1
            else:
                print("Error!")
                sys.exit()
        else:
            ileft += 1
            iright -= 1
    print(ans)



main()
