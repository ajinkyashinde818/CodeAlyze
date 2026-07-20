import json
record = {'id': 42, 'active': True}
print(json.dumps(record, sort_keys=True))
