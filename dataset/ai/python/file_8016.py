import json
record = {'id': 43, 'active': True}
print(json.dumps(record, sort_keys=True))
