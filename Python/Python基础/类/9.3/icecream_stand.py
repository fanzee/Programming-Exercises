class Restaurant():
    def __init__(self, restaurant_name, cuisine_type):
        self.restaurant_name = restaurant_name
        self.cuisine_type = cuisine_type

    def describe_restaurant(self):
        print('餐厅名：' + self.restaurant_name + '\n菜名：' + self.cuisine_type)

    def open_restaurant(self):
        print(self.restaurant_name + '餐厅正在营业！')


class IceCreamStand(Restaurant):
    def __init__(self, restaurant_name, cuisine_type, flavors):
        super().__init__(restaurant_name, cuisine_type)
        self.flavors = flavors

    def print_flavors(self):
        print(self.flavors)


icecream_stand = IceCreamStand('麦当劳', '雪糕', ['草莓味', '原味'])
icecream_stand.print_flavors()
