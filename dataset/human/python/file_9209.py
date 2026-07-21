S = raw_input() + "end!"

def solve():
    pos = 0
    while True:
        plus_one_flag = 0
        if S[pos:pos+5] == "dream":
            pos += 5
        elif S[pos:pos+5] == "erase":
            pos += 4
            plus_one_flag = 1
        elif S[pos:pos+6] == "end!":
            return True
        else:
            return False

        if S[pos:pos+4] == "erer" or S[pos:pos+4] == "erdr" or S[pos:pos+4] == "eren":
            pos += 2
            plus_one_flag = 0
        pos += plus_one_flag

print "YES" if solve() else "NO"
