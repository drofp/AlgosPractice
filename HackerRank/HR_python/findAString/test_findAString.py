import findAString_me1
import findAString_notMe1
import findAString_notMe2
import unittest


class TestSubStringFinder(unittest.TestCase):
    """
    Test the substring finder from the findAString solutions to the Hackerrank problem "Find a String"
    """

######### No instance of substring exists in string #########
    def test_no_substring_me1(self):
        """
        Test a string with no instance of the given substring returns 0 found substrings
        - my version
        """
        result = findAString_me1.count_substring("AABBCCADSFEASDXZC", "LL")
        self.assertEqual(result, 0)
    
    def test_no_substring_notMe1(self):
        """
        Test a string with no instance of the given substring returns 0 found substrings
        - Not my version 1
        """
        result = findAString_notMe1.count_substring("AABBCCADSFEASDXZC", "LL")
        self.assertEqual(result, 0)

    def test_no_substring_notMe2(self):
        """
        Test a string with no instance of the given substring returns 0 found substrings
        - Not my version 2
        """
        result = findAString_notMe2.count_substring("AABBCCADSFEASDXZC", "LL")
        self.assertEqual(result, 0)

######### Input string is empty and input substring is not #########
    # def test_no_string(self):
    #     """
    #     Test an empty string input with non-empty substring
    #     """
    #     result = findA

if __name__ == '__main__':
    unittest.main()
