import random

from number import *

class Fractional(Number):
    def __init__(self):
        self.number = 0
        self.denominator = 0

    def ReadStrArray(self, strArray, i):
        if i >= len(strArray) - 1:
            return 0
        self.number = int(strArray[i])
        self.denominator = int(strArray[i+1])
        i += 2
        return i

    def Print(self):
        print("It is fraction: Numerator = {}, Denominator = {}. Convert to real number {}".format(self.number, self.denominator, self.ConvertToRealNumber()))
        pass

    def Write(self, ostream):
        ostream.write("It is fraction: Numerator = {}, Denominator = {}. Convert to real number {}".format(self.number, self.denominator, self.ConvertToRealNumber()))
        pass

    def InRnd(self):
        self.number = random.uniform(1, 2000)
        self.denominator = random.uniform(1, 2000)

    def ConvertToRealNumber(self):
        return self.number / self.denominator
        pass
