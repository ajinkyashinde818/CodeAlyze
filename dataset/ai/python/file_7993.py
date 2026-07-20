import json
record = {'id': 20, 'active': True}
print(json.dumps(record, sort_keys=True))
