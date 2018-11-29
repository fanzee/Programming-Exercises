file_name = 'guest_book.txt'
with open(file_name, 'w', encoding='UTF-8') as file_obj:
    while True:
        name = input('请输入您的名字(quit退出)：\n')
        if name == 'quit':
            break
        print('你好！' + name)
        file_obj.write(name + '已访问！\n')
