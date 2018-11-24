def describe_city(name, country='China'):
    print(str(name).title() + ' is in ' + str(country).title())


describe_city('shanghai')
describe_city('beijing')
describe_city('new york', 'united states of america')
