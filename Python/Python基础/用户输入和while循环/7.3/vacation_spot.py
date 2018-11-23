active = True
spot_list = []
while active:
    spot = input("你梦想的度假圣地是？(quit退出)\n")
    spot_list.append(spot)
    if spot == 'quit':
        active = False
spot_list.pop()
print(spot_list)
