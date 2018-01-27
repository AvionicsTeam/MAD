# A small tool for converting data registered in X-Plane to CSV format

RecordedData = open("flight.txt", "r").read().split("\n")

def RemoveMultipleSpaces(s):
    if "  " in s:
        return RemoveMultipleSpaces(s.replace("  ", " "))
    else:
        return s

assert RemoveMultipleSpaces("A       B") == "A B"

def IsNumber(s):
    try:
        float(s)
    except ValueError:
        return False
    return True

if RecordedData[0].__len__() <= 1:
    RecordedData.pop(0)

for i in range(0, RecordedData.__len__()):
    RecordedData[i] = RemoveMultipleSpaces(RecordedData[i])[:-3].replace(" | ", ", ")

Header = ", ".join("\""+x.replace(",_", "###").replace(" ", "").replace("_", "").replace("###", "_").replace(",", "_").replace("/", "_")+"\"" for x in RecordedData[0].split(", "))

RecordedData = [Header] + [x for x in RecordedData if IsNumber(x.split(", ")[0])]


open("converted.csv", "w").write("\n".join(RecordedData))
