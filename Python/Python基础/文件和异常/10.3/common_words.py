count = 0
with open('the_cash_boy.txt', encoding='UTF-8') as file_obj:
    for line in file_obj:
        count += line.count('the')
    print(count)
