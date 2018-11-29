import json

number = int(input('请输入您最喜欢的数字：\n'))
file_name = 'number.json'
with open(file_name, 'w') as file_obj:
    json.dump(number, file_obj)
