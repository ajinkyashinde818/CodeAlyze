from collections import Counter
s = raw_input()
t = raw_input()

s=sorted(s)
t=sorted(t, reverse=True)

for x in xrange(min(len(s), len(t))):
    if s < t:
        print "Yes"
        break
    elif s>t:
        print "No"
        break
else:
    if len(s) < len(t):
        print "Yes"
    else:
        print "No"
