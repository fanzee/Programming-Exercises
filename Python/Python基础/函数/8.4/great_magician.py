def show_magicians(magicians_list):
    for person in magicians_list:
        print(person)


def make_great(magicians_list):
    i = 0
    while i < len(magicians_list):
        magicians_list[i] = 'the Great ' + magicians_list[i]
        i += 1


magicians = ['David Copperfield', 'Jason Latimer', 'Criss Angel']
show_magicians(magicians)

make_great(magicians)
show_magicians(magicians)
