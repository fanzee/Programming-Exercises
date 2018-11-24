def make_car(manufacturer, size, **infomation):
    car = {}
    car['manufacturer'] = manufacturer
    car['size'] = size
    for key, value in infomation.items():
        car[key] = value
    return car


car = make_car('subaru', 'outback', color='blue', tow_package=True)
print(car)