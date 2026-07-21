init = input()

words = [
  'dream',
  'dreamer',
  'erase',
  'eraser'
]

def reverseWord(str):
  return str[::-1]

def elimTheWord(str):
  for word in reversed_words:
    if str.find(word) == 0:
      str = str[len(word):]
  return str

reversed_words = list(map(reverseWord, words))

# main
target = reverseWord(init)

while True:
  pivot = elimTheWord(target)
  if pivot == '':
    print('YES')
    break
  if pivot == target:
    print('NO')
    break
  target = pivot
