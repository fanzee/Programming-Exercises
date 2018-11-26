class Restaurant():
    def __init__(self, restaurant_name, cuisine_type):
        self.restaurant_name = restaurant_name
        self.cuisine_type = cuisine_type
        self.number_served = 0

    def describe_restaurant(self):
        print('餐厅名：' + self.restaurant_name + '\n菜名：' + self.cuisine_type)

    def open_restaurant(self):
        print(self.restaurant_name + '餐厅正在营业！')

    def set_number_served(self, number):
        if number > 0:
            self.number_served = number

    def increment_number_served(self, increment_number):
        self.number_served += increment_number


restaurant = Restaurant('肯德基', '牛肉汉堡')
print('就餐人数：' + str(restaurant.number_served))

restaurant.number_served = 10
print('就餐人数：' + str(restaurant.number_served))

restaurant.set_number_served(20)
print('就餐人数：' + str(restaurant.number_served))

restaurant.increment_number_served(30)
print('就餐人数：' + str(restaurant.number_served))
