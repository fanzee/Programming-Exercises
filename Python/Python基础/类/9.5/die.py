from random import randint


class Die():
    def __init__(self, sides=6):
        self.sides = sides

    def roll_die(self):
        print(str(self.sides) + '面的骰子点数是：' + str(randint(1, self.sides)))


die_6 = Die()
die_10 = Die(10)
die_20 = Die(20)
for i in range(10):
    die_6.roll_die()
    die_10.roll_die()
    die_10.roll_die()
    print('')
