def file2list(fname):
    data = []
    with open(fname) as f:
        for line in f.readlines():
            data.append([])
            for n in line.strip().split():
                data[-1].append(int(n))
    return data

def istriangle(L):
    X = [L[i]<(L[(i-1)%3]+L[(i+1)%3]) for i in range(3)]
    return sum(X)==3

if __name__=="__main__":
    fname = "input.txt"
    lines = file2list(fname)
    counter = 0
    for line in lines:
        counter += istriangle(line)
    print(counter)