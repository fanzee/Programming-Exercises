import unittest
from employee import Employee


class TestEmployee(unittest.TestCase):
    def setUp(self):
        self.employee = Employee('Potter', 'Harry', 1000)

    def test_give_default_raise(self):
        self.assertEqual(self.employee.annual_salary, 1000)

    def test_give_custom_raise(self):
        self.employee.give_raise()
        self.assertEqual(self.employee.annual_salary, 6000)
