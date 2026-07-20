from pathlib import Path
path = Path('temporary_example.txt')
path.write_text('60')
print(path.read_text())
path.unlink()
