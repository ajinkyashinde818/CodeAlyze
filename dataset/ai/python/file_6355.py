class Counter:
  def __init__(self, start):
self.value = start
def increment(self):
self.value += 1
counter = Counter(11)
counter.increment()
print(counter.value)
