def is_fit(str_list,chr_):
    while len(chr_) > 0:
        if   chr_[-7:] in t_list:
            chr_ = chr_[:-7]
        elif chr_[-6:] in t_list:
            chr_ = chr_[:-6]
        elif chr_[-5:] in t_list:
            chr_ = chr_[:-5]
        else:
            return "NO"
    return "YES"

s = input()
t_list = ["dream","dreamer","erase","eraser"]

print(is_fit(t_list,s))
