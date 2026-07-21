input_str = input()
new_str = ''.join(list(reversed(input_str)))
candidates = ["dream", "dreamer", "erase", "eraser"]
candidates = [''.join(list(reversed(s))) for s in candidates]

def match_candidates(s, i, candidates):
    for candidate in candidates:
        length = len(candidate)
        if s[i:i+length] == candidate: return length
    return -1

def judge_str(s, candidates):
    i = 0
    while i < len(new_str):
        jump = match_candidates(s, i, candidates)
        if jump == -1:
            return "NO"
        i += jump
    return "YES"
    
print(judge_str(new_str, candidates))
