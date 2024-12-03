import numpy as np

def file2list(fname):
    L = []
    with open(fname) as f:
        for line in f.readlines():
            L.append([])
            for c in line.strip():
                L[-1].append(c)
    return L

def instruction2dir(c):
    dirs = {'U':np.array((-1,0)),
            'L':np.array((0,-1)),
            'R':np.array((0,1)),
            'D':np.array((1,0))}
    return dirs[c]

def executeline(line,pos):
    for instr in line:
        dir = instruction2dir(instr)
        pos = pos + dir
        pos[0] = min(2,max(pos[0],0))
        pos[1] = min(2,max(pos[1],0))
    return 3*pos[0]+pos[1]+1,pos
   
if __name__=="__main__":
    fname = 'input.txt'
    pos = np.array((1,1))
    code = ''
    instr = file2list(fname)
    for line in instr:
        digit, pos = executeline(line,pos)
        code = code+str(digit)
    print(code)