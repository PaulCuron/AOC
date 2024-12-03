def file2list(fname):
    L = []
    with open(fname) as f:
        for l in f.readlines():
            L.append([])
            l = l.strip().split('-')
            L[-1] = [l[0:-1], int(l[-1].split('[')[0]), l[-1].split('[')[1][:-1] ]
    return L

class line:
    '''
        line:
            -encrypted name : [aaaa, bbbb, cdfe]
            -sectorID       : 1234
            -checksum       : abc
    '''
    def __init__(self, encrypted_name, sectorID, checksum):
        self.encrypted_name = encrypted_name
        self.sectorID = sectorID
        self.checksum = checksum
        self.freqs = [0]*26

    def getfreq(self):
        for word in self.encrypted_name:
            for c in word:
                self.freqs[ord(c)-ord('a')]+=1

    def isValid(self):
        valid = True
        j = 0
        while valid and j<len(self.checksum):
            char = self.checksum[j]
            if self.freqs[ord(char)-ord('a')] != max(self.freqs):
                valid = False
            else:
                if j < len(self.checksum)-1:
                    nchar =self.checksum[j+1] 
                    if self.freqs[ord(char)-ord('a')] == self.freqs[ord(nchar)-ord('a')]:
                        valid = (ord(char)<ord(nchar))
                if valid:
                    self.freqs[ord(char)-ord('a')]=0
            j+=1
        return valid


if __name__=="__main__":
    fname = "input.txt"
    data = file2list(fname)
    u = [chr(i+ord('a')) for i in range(26)]
    S = 0
    for entry in data:
        l = line(entry[0], int(entry[1]), entry[2])
        l.getfreq()
        if l.isValid():
            S+=l.sectorID
    print(S)

