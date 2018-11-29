try:
    with open('cats.txt') as file_obj:
        print(file_obj.read())

    with open('dogs.txt') as file_obj:
        print(file_obj.read())
except FileNotFoundError:
    print('有文件不存在!')
