input_str = input()
process_flag = 'process'
ans_flag = 'NO'
d_e = ''
ans_list = []

def pre_str_process(now_str):
  ans_list.append(now_str[:5])
  now_str = now_str[5:]
  return now_str

def dream(now_str):
  now_str = pre_str_process(now_str)
  if (now_str == '') or (now_str == 'er'):
    return now_str, 'OK'
  if now_str[:5] == 'dream':
    return now_str, 'dream'
  if now_str[:2] == 'er':
    if now_str[:5] == 'erase':
      return now_str, 'erase'
    if now_str[:7] == 'ererase':
      now_str = now_str[2:]
      return now_str, 'erase'
    if now_str[:7] == 'erdream':
      now_str = now_str[2:]
      return now_str, 'dream'
    else:
      return now_str, 'NG'

  else:
    return now_str, 'NG'

def erase(now_str):
  now_str = pre_str_process(now_str)
  if (now_str == '') or (now_str == 'r'):
    return now_str, 'OK'
  if now_str[0] == 'r':
    now_str = now_str[1:]
    if now_str[:5] == 'dream':
      return now_str, 'dream'
    if now_str[:5] == 'erase':
      return now_str, 'erase'
    else:
      return now_str, 'NG'
  if now_str[:5] == 'erase':
    return now_str, 'erase'
  if now_str[:5] == 'dream':
    return now_str, 'dream'
  else:
    return now_str, 'NG'

first_str = input_str[:5]
process_num = 0
while process_flag == 'process':
  process_num += 1
  if process_num == 1:
    if first_str == 'dream':
      now_str = input_str
      d_e = 'dream'
    elif first_str == 'erase':
      now_str = input_str
      d_e = 'erase'
    else:
      break
  elif d_e == 'dream':
    now_str, d_e = dream(now_str)
  elif d_e == 'erase':
    now_str, d_e = erase(now_str)
  elif d_e == 'OK':
    ans_flag = 'YES'
    break
  elif d_e == 'NG':
    break
print(ans_flag)
