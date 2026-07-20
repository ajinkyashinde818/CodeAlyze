def announce(function):
	def wrapper(*args):
print('calling')
return function(*args)
return wrapper
@announce
def greet(name):
print(name)
greet('CodeAlyze')
