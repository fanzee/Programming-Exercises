import unittest
from city_functions import city_country
from city_population import city_country_population


class CityTestCase(unittest.TestCase):
    def test_city_country(self):
        result = city_country('santiage', 'chile')
        self.assertEqual(result, 'Santiage, Chile')

    def test_city_country_population(self):
        result = city_country_population('santiage', 'chile')
        self.assertEqual(result, 'Santiage, Chile')

    def test_city_country_population2(self):
        result = city_country_population('santiage', 'chile', 5000000)
        self.assertEqual(result, 'Santiage, Chile - population 5000000')
