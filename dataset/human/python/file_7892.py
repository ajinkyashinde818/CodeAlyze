import strutils
var v = readLine(stdin)
var counta,countb,countc = 0

for i in 0..2:
    case v[i]
    of 'a':
        counta = counta + 1
    of 'b':
        countb = countb + 1
    of 'c':
        countc = countc + 1
    else:
        counta = counta
        
if((counta == 1) and (countb == 1) and (countc == 1)):
    echo "Yes"
else:
    echo "No"
