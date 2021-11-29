import math
from number import *


class PolarNumber(Number):
    def __init__(self):
        self.angle = 0.0
        self.x = 0
        self.y = 0

    def ReadStrArray(self, strArray, i):
        if i >= len(strArray) - 1:
            return 0
        self.x = int(strArray[i])
        self.y = int(strArray[i + 1])
        self.angle = int(strArray[i + 2])
        i += 3
        return i


    def Print(self):
        print("It is polar coordinates: angel = ", self.angle, ", x coordinate = ", self.x,
              ", y coordinate = ", self.y,
              ". Convert to real number ", self.ConvertToRealNumber())
        pass


    def Write(self, ostream):
        ostream.write("It is polar coordinates: angel = {}, x coordinate = {}, y coordinate = {}. Convert to real number {}"
                      .format(self.angle, self.x, self.y, self.ConvertToRealNumber()))
        pass


    def ConvertToRealNumber(self):
        return math.sqrt(self.x**2 + self.y**2)
        pass
