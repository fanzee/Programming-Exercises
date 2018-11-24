def make_album(singer, album_name):
    information = {
        'singer': singer,
        'album_name': album_name,
    }
    return information


while True:
    singer = input("请输入歌手名(quit退出)：\n")
    if singer == 'quit':
        break
    album_name = input("请输入专辑名(quit退出)：\n")
    if album_name == 'quit':
        break
    print(make_album(singer, album_name))
    break
