import hashlib

if __name__=="__main__":
    door_id = "wtnhxymk"
    password = ["" for i in range(8)]
    counter = 0
    hash = "111111111111"
    valid = False
    for i in range(8):
        while hash[0:5]!="00000" or not valid:
            hash = hashlib.md5((door_id+str(counter)).encode()).hexdigest()
            pos = hash[5]
            try:
                pos = int(pos)
                valid = (pos<8)
            except:
                valid = False
            counter+=1
        password[pos] = hash[6]
        counter+=1
        valid = False
        print(password)
    print(password)