class Restaurant():
    def __init__(self, restaurant_name, cuisine_type):
        self.restaurant_name = restaurant_name
        self.cuisine_type = cuisine_type

    def describe_restaurant(self):
        print('餐厅名：' + self.restaurant_name + '\n菜名：' + self.cuisine_type)

    def open_restaurant(self):
        print(self.restaurant_name + '餐厅正在营业！')


Restaurant('全聚德', '北京烤鸭').describe_restaurant()
Restaurant('真功夫', '香辣排骨').describe_restaurant()
Restaurant('肯德基', '牛肉汉堡').describe_restaurant()
