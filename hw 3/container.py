from complex import *
from fractional import *
from polar_coordinates import *


class Container:
    def __init__(self):
        self.store = []

    def ReadStrArray(self, strArray):
        if strArray == ['']:
            pass

        length = len(strArray)
        i = 0

        while i < length:
            index = int(strArray[i])
            i += 1

            match index:
                case 1:
                    num = Complex()
                case 2:
                    num = Fractional()
                case 3:
                    num = PolarNumber()

            i = num.ReadStrArray(strArray, i)
            self.store.append(num)

    def ReadRnd(self, size):
        for i in range(size):
            index = random.randint(1, 3)

            match index:
                case 1:
                    num = Complex()
                case 2:
                    num = Fractional()
                case 3:
                    num = PolarNumber()

            num.CreateRandom()
            self.store.append(num)

    def Print(self, output):
        print("Container is store", len(self.store), "number:", file=output)
        for num in self.store:
            num.Print(output)
        pass

    def Write(self, ostream):
        ostream.write("Container is store {} numbers:\n".format(len(self.store)))
        for num in self.store:
            num.Write(ostream)
            ostream.write("\n")
        pass

    def Sort(self):
        gap = len(self.store) // 2
        while gap > 0:
            j = gap
            while j < len(self.store):
                temp = self.store[j]
                i = j

                while i >= gap and (self.store[i - gap].ConvertToRealNumber() < temp.ConvertToRealNumber()):
                    self.store[i] = self.store[i - gap]
                    i -= gap
                self.store[i] = temp
                j += 1
            gap //= 2
