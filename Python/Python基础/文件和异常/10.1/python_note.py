filename = 'learning_python.txt'

with open(filename) as file_obj:
    print(file_obj.read())
print('')

with open(filename) as file_obj:
    for every_line in file_obj:
        print(every_line.strip())
print('')

with open(filename) as file_obj:
    lines = file_obj.readlines()
for line in lines:
    print(line.strip())
