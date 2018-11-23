print("五香烟熏牛肉卖完了\n")
sandwich_orders = ['火腿奶酪三明治', '五香烟熏牛肉', '五香烟熏牛肉', '猪排三明治', '金枪鱼三明治', '五香烟熏牛肉']
finished_sandwiches = []
while '五香烟熏牛肉' in sandwich_orders:
    sandwich_orders.remove('五香烟熏牛肉')
finished_sandwiches = sandwich_orders[:]
print(finished_sandwiches)
