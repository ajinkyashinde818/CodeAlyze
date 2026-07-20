# Example program
from pathlib import Path
path = Path('temporary_example.txt')
path.write_text('57')
print(path.read_text())
path.unlink()
