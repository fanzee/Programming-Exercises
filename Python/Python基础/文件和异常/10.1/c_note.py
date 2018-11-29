filename = 'learning_python.txt'

with open(filename) as file_obj:
    for every_line in file_obj:
        message = every_line.replace('Python', 'C')
        print(message.strip())
