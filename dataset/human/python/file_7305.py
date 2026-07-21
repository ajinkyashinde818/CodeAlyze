S = input()
Q = int(input())
lst_query = [input().split() for i in range(Q)]

def make_reverse(S):

    if len(S) == 1:
        return S

    reversedS = ""
    for i in range(len(S)-1, -1, -1):
        reversedS += S[i]
    else: return reversedS

def main(S, Q, lst_query):

    cnt_reverse = 0
    leftS  = ""
    rightS = ""

    for i in range(Q-1, -1, -1):
        
        query = lst_query[i]

        if int(query[0]) == 1:
            cnt_reverse += 1
        else:
            if cnt_reverse % 2 == 0:
                if int(query[1]) == 1: leftS  = leftS + query[2]
                else                 : rightS = query[2] + rightS
            else:
                if int(query[1]) == 1: rightS = query[2] + rightS
                else                 : leftS  = leftS + query[2]

    if cnt_reverse % 2 == 1: S = make_reverse(S)
    return leftS + S + rightS


if __name__ == "__main__":

    answer = main(S, Q, lst_query)
    print(answer)
