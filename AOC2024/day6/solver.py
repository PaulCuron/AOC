import numpy as np


from tqdm import tqdm

def reader(fname):
    directions = {
        "V":np.array([1,0]),
        "^":np.array([-1,0]),
        ">":np.array([0,1]),
        "<":np.array([0,-1])
    }

    with open(fname) as f:
        objects_positions = []
        guard_coord = []
        for i,line in enumerate(f.readlines()):
            for j,c in enumerate(line.strip()):
                if c == "#":
                    objects_positions.append((i,j))
                elif c !=".":
                    guard_coord=np.array([np.array([i,j]), directions[c]])
        dimensions = (i,j)
        print(dimensions)
    return guard_coord, objects_positions, dimensions

def move_guard(guard_coord,object_positions,dimensions):

    rotation = np.array([[0, -1],
                         [1, 0]])
    if tuple(guard_coord[0]+guard_coord[1]) in object_positions:
        guard_coord[1] = np.dot(guard_coord[1],rotation)
    elif 0 <= tuple(guard_coord[0]+guard_coord[1])[0] <= dimensions[0] and 0 <= tuple(guard_coord[0]+guard_coord[1])[1] <= dimensions[1]:
        guard_coord[0] += guard_coord[1]
    else:
        return None
    return guard_coord

def evolve(fname):
    guard_coord, objects_pos,dimensions = reader(fname)
    visited_pos = []
    
    
    while guard_coord is not None:
        if tuple(guard_coord[0]) not in visited_pos:
            visited_pos.append(tuple(guard_coord[0]))
        guard_coord = move_guard(guard_coord, objects_pos, dimensions)
    
    print(len(set(visited_pos)))
    return 0

if __name__=="__main__":

    part_one("input.txt")

    part_two("input.txt")