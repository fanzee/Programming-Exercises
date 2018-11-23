sandwich_orders = ['火腿奶酪三明治', '猪排三明治', '金枪鱼三明治']
finished_sandwiches = []
while sandwich_orders:
    doing = sandwich_orders.pop()
    print("我正在做" + doing)
    finished_sandwiches.append(doing)
print(finished_sandwiches)
