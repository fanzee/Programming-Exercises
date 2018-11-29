import json

file_name = 'username.json'


def get_stored_name():
    try:
        with open(file_name) as file_obj:
            username = json.load(file_obj)
    except FileNotFoundError:
        return None
    else:
        return username


def get_new_username():
    username = input('请输入您的名字：\n')
    with open(file_name, 'w') as file_obj:
        json.dump(username, file_obj)


def greet_user():
    username = get_stored_name()
    if username:
        answer = input('这是你的用户名吗：' + username + '?（yes/no）\n')
        if answer == 'yes':
            print('欢迎回来！')
        else:
            get_new_username()
    else:
        get_new_username()


greet_user()
