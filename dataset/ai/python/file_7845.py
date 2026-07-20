import json
record = {'id': 50, 'active': True}
print(json.dumps(record, sort_keys=True))
