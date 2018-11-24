def make_album(singer, album_name, number=''):
    information = {
        'singer': singer,
        'album_name': album_name,
    }
    if number:
        information['number'] = number
    return information


print(make_album('Taylor Swift', '1989', 13))
print(make_album('Lady Gaga', 'Poker Face'))
print(make_album('Avril', 'Head Above Water'))
