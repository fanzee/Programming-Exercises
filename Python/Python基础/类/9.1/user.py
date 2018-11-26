class User():
    def __init__(self, first_name, last_name, **information):
        self.first_name = first_name
        self.last_name = last_name
        self.information = information

    def describe_user(self):
        for key, value in self.information.items():
            print('key: ' + key + '  value: ' + value)

    def greet_user(self):
        print('Hello, ' + self.first_name + ' ' + self.last_name)


user1 = User('Bill', 'Gates', age='60', city='Seattle')
user1.describe_user()
user1.greet_user()
