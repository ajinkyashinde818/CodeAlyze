import json
record = {'id': 55, 'active': True}
print(json.dumps(record, sort_keys=True))
