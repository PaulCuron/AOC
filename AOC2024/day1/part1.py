import numpy as np

fname = "input.txt"

with open(fname) as f:
    L = f.readlines()
    L1, L2 = [int(line.strip()split()[0]) for line in L], [int(line.strip()split()[1]) for line in L]