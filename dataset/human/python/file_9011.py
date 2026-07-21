S=input()
T=""
Vocab=["dream", "dreamer", "erase", "eraser"]
Reverse=[]
for word in Vocab:
    Reverse.append(word[::-1])

SReverse = S[::-1]

def searchWord(TargetString, WordList):
    for word in WordList:
        index=TargetString.find(word)
        if index == 0:
            return True, index+len(word)
        else:
            pass
    return False, index

def cutString(TargetString, slicePoint):
    replacement = TargetString[slicePoint:]
    return replacement

while True:
    if searchWord(SReverse, Reverse)[0]:
        index = searchWord(SReverse, Reverse)[1]
        SReverse = cutString(SReverse, index)
    else:
        break

if len(SReverse) == 0:
    print("YES")
else:
    print("NO")
