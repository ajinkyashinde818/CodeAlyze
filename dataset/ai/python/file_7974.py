import json
record = {'id': 90, 'active': True}
print(json.dumps(record, sort_keys=True))
