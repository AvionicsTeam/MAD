# A small tool for converting data registered in X-Plane to CSV format

RecordedData = open("flight.txt", "r").read().split("\n")

def RemoveMultipleSpaces(s):
    if "  " in s:
        return RemoveMultipleSpaces(s.replace("  ", " "))
    else:
        return s

assert RemoveMultipleSpaces("A       B") == "A B"

if RecordedData[0].__len__() <= 1:
    RecordedData.pop(0)

for i in range(0, RecordedData.__len__()):
    RecordedData[i] = RemoveMultipleSpaces(RecordedData[i])[:-3].replace(" | ", ", ")

RecordedData[0] = ", ".join("\""+x.replace(",_", "###").replace(" ", "").replace("_", "").replace("###", "_").replace(",", "_").replace("/", "_")+"\"" for x in RecordedData[0].split(", "))

open("converted.csv", "w").write("\n".join(RecordedData))
