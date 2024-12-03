from part1 import file2list, line

def decode(c, key):
    return chr((ord(c)-ord('a')+key)%26+ord('a'))

def decrypt(L, key):
    decoded = ""
    for word in L:
        for c in word:
            decoded = decoded + decode(c,key)
        decoded+=" "
    return decoded

if __name__=="__main__":
    fname = 'input.txt'
    data = file2list(fname)
    for entry in data:
        l = line(entry[0], int(entry[1]), entry[2])
        if 'north' in decrypt(l.encrypted_name,l.sectorID):
            print(decrypt(l.encrypted_name,l.sectorID))
            print(l.sectorID)