class User():
    def __init__(self, first_name, last_name, **information):
        self.first_name = first_name
        self.last_name = last_name
        self.information = information
        self.login_attempts = 0

    def describe_user(self):
        for key, value in self.information.items():
            print('key: ' + key + '  value: ' + value)

    def greet_user(self):
        print('Hello, ' + self.first_name + ' ' + self.last_name)

    def increment_login_attempts(self):
        self.login_attempts += 1

    def reset_login_attempts(self):
        self.login_attempts = 0


user1 = User('Bill', 'Gates')

user1.increment_login_attempts()
user1.increment_login_attempts()
user1.increment_login_attempts()
print(user1.login_attempts)

user1.reset_login_attempts()
print(user1.login_attempts)
