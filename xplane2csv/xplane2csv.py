# A small tool for converting data registered in X-Plane to CSV format

RawData = open("flight.txt", "r").read().split("\n")

Values = {}

def RemoveMultipleSpaces(s):
    """Removes multiple spaces from given strings."""
    if "  " in s:
        return RemoveMultipleSpaces(s.replace("  ", " "))
    else:
        return s

def PrepareHeader(Header):
    """ Prepares CSV column names."""
    Header = Header.strip()
    PreparedHeader = ["\""+x.replace(",_", "###").replace(" ", "").replace("_", "").replace("###", "_").replace(",", "_").replace("/", "_").replace("|", "")+"\"" for x in Header.split(" | ")]
    for i,x in enumerate(PreparedHeader):
        if PreparedHeader.count(x)>1:
            PreparedHeader[i] = PreparedHeader[i] + "_X"

    return PreparedHeader

def ProcessRange(CurrentRange):
    """ Processes raw data range."""
    Header = PrepareHeader(CurrentRange[0])
    Data = CurrentRange[1:]

    Columns = {}
    for col in Header:
        Columns[col] = []

    for i,x in enumerate(Data):
        row = RemoveMultipleSpaces(x)[:-3].split(" | ")
        for num,cell in enumerate(row):
            Columns[Header[num]].append(cell)

    return Columns

# Find empty lines which separates data ranges
Separators = [i for i,x in enumerate(RawData) if x.__len__() <= 1]

# Process separated ranges
for i in range(Separators.__len__()-1):
    ProcessedRange = ProcessRange(RawData[Separators[i]+1:Separators[i+1]])
    for key,value in ProcessedRange.items():
        if key in Values:
            Values[key].extend(value)
        else:
            Values[key] = value

# Find longest column
maxlen = 0
for key,value in Values.items():
    if value.__len__() > maxlen:
        maxlen = value.__len__()

# Fill in shorter columns with zeros
for key,value in Values.items():
    if value.__len__()<maxlen:
        Values[key] = (maxlen - value.__len__()) * [0] + value
    
# Now we can generate our CSV file
f = open("converted.csv", "w")
f.truncate()
f.write(", ".join(Values.keys()) + "\n")

for i in range(maxlen):
    row = []
    for key,value in Values.items():
        row.append(str(value[i]))
    f.write(", ".join(row)+"\n")

f.close()
