def main():
  S = input()[::-1]
  i = 0
  while i < len(S):
    if S[i:i+5] == 'maerd' or S[i:i+5] == 'esare':
      i += 5
    elif S[i:i+6] == 'resare':
      i += 6
    elif S[i:i+7] == 'remaerd':
      i += 7
    else:
      print('NO')
      break
  else:
    print('YES')
  return

if __name__ == '__main__':
  main()
