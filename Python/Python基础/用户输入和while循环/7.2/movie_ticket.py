age = int(input("请输入您的年龄，我们将告诉您票价\n"))
if age < 3:
    print("免费")
elif 3 <= age <= 12:
    print("10美元")
else:
    print("15美元")
