from part1 import istriangle

def file2list2(fname):
    L = []
    with open(fname) as f:
        raw = f.readlines()
        for i in range(len(raw)//3):
            activetriplet = [raw[i*3+k].strip().split() for k in range(3)]
            for j in range(3):
                L.append([int(u[j]) for u in activetriplet])
    return L

if __name__=="__main__":
    fname = "input.txt"
    data = file2list2(fname)
    counter = 0
    for line in data:
        counter+= istriangle(line)
    print(counter)
