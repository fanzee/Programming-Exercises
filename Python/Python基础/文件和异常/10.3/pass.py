try:
    with open('cats.txt') as file_obj:
        print(file_obj.read())

    with open('dogs.txt') as file_obj:
        print(file_obj.read())
except FileNotFoundError:
    pass
