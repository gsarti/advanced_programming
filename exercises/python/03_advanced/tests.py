import unittest

class MyRange():
    """
    Class MyRange that acts like a range.
    """      
    def __init__(self, start, stop, step=1):
        """
        Initialize the range member of the MyRange class.
        """
        self.range = range(start, stop, step)
        
def myrange(*args):
    """
    Returns a custom range, managing argument errors.
    """
    num_args = len(args)
    if num_args not in [1,2,3]:
        raise TypeError("myrange should have at most three arguments and at least one!")
    if num_args==1:
        return MyRange(0,args[0]).range
    elif num_args==2:
        return MyRange(args[0],args[1]).range
    elif num_args==3:
        return MyRange(args[0],args[1],args[2]).range

class TestMyRange(unittest.TestCase):
    def test_min_arguments(self):
        with self.assertRaises(TypeError):
            myrange()
    
    def test_max_arguments(self):
        with self.assertRaises(TypeError):
            myrange(1,2,3,4)
        
    def test_match_range_behavior(self):
        self.assertEqual(range(10), myrange(10))
        self.assertEqual(range(1,6), myrange(1,6))
        self.assertEqual(range(12, 0, -1), myrange(12, 0, -1))
    
    def test_range_size(self):
        self.assertEqual(100, len(myrange(0,100,1)))
        self.assertEqual(50, len(myrange(1,101,2)))
        
if __name__ == '__main__':
    unittest.main() 