class Restaurant():
    def __init__(self, restaurant_name, cuisine_type):
        self.restaurant_name = restaurant_name
        self.cuisine_type = cuisine_type

    def describe_restaurant(self):
        print('餐厅名：' + self.restaurant_name + '\n菜名：' + self.cuisine_type)

    def open_restaurant(self):
        print(self.restaurant_name + '餐厅正在营业！')


restaurant = Restaurant('全聚德', '北京烤鸭')

print(restaurant.restaurant_name)
print(restaurant.cuisine_type)

restaurant.describe_restaurant()
restaurant.open_restaurant()
