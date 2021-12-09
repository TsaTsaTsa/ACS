import sys
from container import *

if __name__ == '__main__':
    if len(sys.argv) != 4:
        print("Incorrect command line! You must write:")
        print("    python main -f <inputFileName> <outputFileName>")
        print("    python main -r <numberOfElements> <outputFileName>")

    container = Container()

    if sys.argv[1] == "-f":
        inputFileName = sys.argv[2]
        outputFileName = sys.argv[3]

        ifile = open(inputFileName)
        strArray = ifile.read().replace("\n", " ").split(" ")
        ifile.close()

        container.ReadStrArray(strArray)
    elif sys.argv[1] == "-n":
        numberOfElements = int(sys.argv[2])
        outputFileName = sys.argv[3]

        container.ReadRnd(numberOfElements)
    else:
        print("Incorrect command line! You must write:")
        print("    python main -f <inputFileName> <outputFileName>")
        print("    python main -n <numberOfElements> <outputFileName>")

    with open(outputFileName, 'w') as output:
        print("===== FILLED CONTAINER =====", file=output)
        container.Write(output)

        container.Sort()
        print("===== SORTED CONTAINER =====", file=output)
        container.Write(output)
