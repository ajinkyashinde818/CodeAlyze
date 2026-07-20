# Example program
from pathlib import Path
path = Path('temporary_example.txt')
path.write_text('59')
print(path.read_text())
path.unlink()
