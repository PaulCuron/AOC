from part1 import file2list, instruction2dir, np

def executeline2(line,pos):
    for instr in line:
        dir = instruction2dir(instr)
        if dir[0]:
            if abs(pos[0]+dir[0]-2) <= 2-abs(pos[1]-2):
                pos = pos +dir
        elif dir[1]:
            if abs(pos[1]+dir[1]-2) <= 2-abs(pos[0]-2):
                pos = pos +dir
    A = [[' ',' ','1',],
         [' ','2','3','4'],
         ['5','6','7','8','9'],
         [' ','A','B','C'],
         [' ',' ','D']]
    digit = A[pos[0]][pos[1]]
    return digit, pos

if __name__=="__main__":
    fname = 'input.txt'
    pos = np.array((2,0))
    code = ''
    instr = file2list(fname)
    for line in instr:
        digit, pos = executeline2(line,pos)
        code = code+digit
    print(code)