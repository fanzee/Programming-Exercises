import json

file_name = 'number.json'
with open(file_name) as file_obj:
    number = json.load(file_obj)

print('你最喜欢的数字是' + str(number))
