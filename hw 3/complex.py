import random
import math
from number import *

class Complex(Number):
    def __init__(self):
        self.real_part = 0
        self.imaginary_part = 0

    def ReadStrArray(self, strArray, i):
        if i >= len(strArray) - 1:
            return 0
        self.real_part = int(strArray[i])
        self.imaginary_part = int(strArray[i+1])
        i += 2
        return i

    def InRnd(self):
        self.real_part = random.uniform(1, 2000)
        self.imaginary_part = random.uniform(1, 2000)

    def Print(self):
        print("It is complex number: real part = {}, imaginary part = {}. Convert to real number {}".format(self.real_part, self.imaginary_part, self.ConvertToRealNumber()))
        pass

    def Write(self, ostream):
        ostream.write("It is complex number: real part = {}, imaginary part = {}. Convert to real number {}".format(self.real_part, self.imaginary_part, self.ConvertToRealNumber()))
        pass

    def ConvertToRealNumber(self):
        return math.sqrt(self.real_part**2 + self.imaginary_part**2)
        pass
