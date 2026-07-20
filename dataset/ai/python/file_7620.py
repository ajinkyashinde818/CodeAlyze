import re
match = re.search(r'\d+', 'item 42')
print(match.group())
