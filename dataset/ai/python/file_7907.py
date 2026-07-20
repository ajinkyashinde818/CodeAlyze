import json
record = {'id': 23, 'active': True}
print(json.dumps(record, sort_keys=True))
