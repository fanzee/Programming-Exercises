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


class Admin(User):
    def __init__(self, first_name, last_name, privileges, **information):
        super().__init__(first_name, last_name, **information)
        self.privileges = privileges

    def show_privileges(self):
        print(self.privileges)


admin = Admin('Bill', 'Gates', ['can add post', 'can delete post', 'can ban user'])
admin.show_privileges()
