while True:
    a = input('请输入加法运算的第一个数字：\n')
    b = input('请输入加法运算的第二个数字：\n')
    try:
        total = int(a) + int(b)
        print('结果是: ' + str(total))
        break
    except ValueError:
        print('输入含有文本，请输入数字重试！\n')
