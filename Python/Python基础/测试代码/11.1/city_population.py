def city_country_population(city, country, population=''):
    if population:
        return str(city).title() + ', ' + str(country).title() + ' - population ' + str(population)
    else:
        return str(city).title() + ', ' + str(country).title()


