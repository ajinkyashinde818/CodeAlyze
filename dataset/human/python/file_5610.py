import sys
s = raw_input()

ss = s.replace("x","")

if(ss == ss[::-1]):
    pass

else:
    print "-1"
    sys.exit()


count = 0

right = 0
left = len(s)-1

for i in range(len(s)*2):

    if ( s[right] != s[left]):
        count += 1
        if(s[right]!="x"):
            right -= 1

        else:
            left += 1
            
    right += 1
    left -= 1
    if(right>=left):
        print count
        sys.exit()
