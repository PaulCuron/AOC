from tqdm import tqdm

def reader(fname):
    with open(fname) as f:
        orders = []
        line = f.readline()
        while line.strip()!="":
            orders.append(line.strip())
            line = f.readline()
        updates = [line.strip().split(',') for line in f.readlines()]

    order_relation = {}
    for order in orders:
        x,y = order.split("|")
        if x in order_relation:
            order_relation[x].append(order)
        else:
            order_relation[x] = [order]
        if y in order_relation:
            order_relation[y].append(order)
        else:
            order_relation[y] = [order]
    return order_relation, updates

def is_ordered(L, order_relation):
    for x in L:
        if not check_rules(x, L, order_relation):
            return False
    return True

def check_rules(x, L, order_relation):
    if not x in order_relation:
        return True
    else:
        rules = order_relation[x]
        for rule in rules:
            X,Y = rule.split("|")
            if (x!=X and X in L):
                if L.index(X)>L.index(x):
                    return False
            if (x!=Y and Y in L):
                if L.index(x)>L.index(Y):
                    return False
        return True
def is_lower(a,b, order_relation):
    if a in order_relation:
        for rule in order_relation[a]:
            X,Y = rule.split("|")
            if (b==X):
                return False
            if (a==X and b ==Y):
                return True
    return False

def order(update, order_relation):
    ordered_list = [update[0]]
    for c in update[1:]:
        u = 0
        while u<len(ordered_list) and is_lower(ordered_list[u], c, order_relation):
            u+=1
        ordered_list = ordered_list[:u]+[c]+ordered_list[u:]
    return ordered_list

def part_one(fname):
    order_relation, updates = reader(fname)
    
    S = 0
    for update in tqdm(updates):
        if is_ordered(update, order_relation):
            S += int(update[len(update)//2])
    print(S)
    return 0



def part_two(fname):
    order_relation, updates = reader(fname)
    
    S = 0
    fail = 0
    for update in tqdm(updates):
        if not is_ordered(update, order_relation):
            L = order(update, order_relation)
            if not is_ordered(L, order_relation):
                fail += 1
            else:
                S += int(L[len(update)//2])
    print(f'Failed ordering {fail} updates')
    print(S)
    return 0

if __name__=="__main__":

    part_one("input.txt")

    part_two("input.txt")