import json
record = {'id': 22, 'active': True}
print(json.dumps(record, sort_keys=True))
