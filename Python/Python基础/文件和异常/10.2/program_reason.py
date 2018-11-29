file_name = 'reasons.txt'
with open(file_name, 'a', encoding='UTF-8') as file_obj:
    while True:
        reason = input('请输入您喜欢编程的原因(quit退出)：\n')
        if reason == 'quit':
            break
        file_obj.write(reason + '\n')
