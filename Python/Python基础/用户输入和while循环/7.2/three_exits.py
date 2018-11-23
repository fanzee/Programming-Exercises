active = True
while active:
    age = input("请输入您的年龄，我们将告诉您票价\n")
    if age == 'quit':
        break
    elif int(age) < 3:
        print("免费\n")
        active = False
    elif 3 <= int(age) <= 12:
        print("10美元\n")
        active = False
    else:
        print("15美元\n")
        active = False
