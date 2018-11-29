import json

file_name = 'remember_number.json'
try:
    with open(file_name) as file_obj:
        number = json.load(file_obj)
except FileNotFoundError:
    number = int(input('请输入您最喜欢的数字：\n'))
    with open(file_name, 'w') as file_obj:
        json.dump(number, file_obj)
else:
    print('你最喜欢的数字是' + str(number))
