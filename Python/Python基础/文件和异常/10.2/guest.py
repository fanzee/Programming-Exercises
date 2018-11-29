name = input('请输入您的名字：\n')
file_name = 'guest.txt'
with open(file_name, 'w') as file_obj:
    file_obj.write(name)
