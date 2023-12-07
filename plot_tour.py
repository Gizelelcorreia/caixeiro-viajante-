import matplotlib.pyplot as plt
import math
import sys

class Solution:
    def __init__(self):

        self.tour = []
        self.cost = 0
        self.timer = 0

class Data:
    def __init__(self):
        self.instance_name = ""
        self.nb_nodes = 0
        self.x = []
        self.y = []
        self.distances = {}

def compute_distance(p1, p2):
    distance = (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2
    return math.sqrt(distance)

def load(name_file: str) -> Data:
    
    data = Data()

    f = open(name_file)
    lines = f.readlines()
    f.close()
    
    load_coord = False
    for line in lines:
        s_line = line.strip().split()
        
        if len(s_line) == 0:
            continue
        
        if 'NAME' in s_line[0]:
            data.instance_name = s_line[-1]
            continue

        if 'DIMENSION' in s_line[0]:
            data.nb_nodes = int(s_line[-1])
            continue

        if 'NODE_COORD_SECTION' in s_line[0]:
            load_coord = True
            continue

        if 'EDGE_WEIGHT_TYPE' in s_line[0]:
            if 'EUC_2D' not in s_line[-1]:
                print('Instace type ', s_line[-1], ' is not supported!')
                sys.exit(1)

        if 'EOF' in s_line[0]:
            break
        
        if load_coord:
            data.x.append(float(s_line[1]))
            data.y.append(float(s_line[2]))
            
            
    for i in range(data.nb_nodes):
        data.distances[i] = {}
        for j in range(data.nb_nodes):
            data.distances[i].update({j: float('inf')})
      
    for i in range(data.nb_nodes):
        for j in range(data.nb_nodes):
            if i == j:
                continue
            data.distances[i][j] = compute_distance((data.x[i], data.y[i]), \
                                                    (data.x[j], data.y[j]))

    return data

def plot(data, solution, strategy = ''):
    
    x = []
    y = []
    
    for i in solution.tour:
        x.append(data.x[i])
        y.append(data.y[i])
    
    plt.plot(x,y, linestyle='-', marker='o', color='r')
    
    title = data.instance_name
    
    title += ' (Cost: ' + '{:,.{}f}'.format(solution.cost, 1)
    
    if strategy != '':
        title += ' \\ ' + strategy
    title += ')'

    plt.title(title)
    # plt.show()
    filename = data.instance_name
    if strategy != '':
        filename += '_' + strategy
    plt.savefig(filename + '.png', dpi=300)
    plt.clf()

def main():

    args = sys.argv
    dt = load(args[1])

    solution = Solution()

    f = open("rota.txt", "r")
    line = f.readline()
    sl = line.split()
    for i in sl:
        solution.tour.append(int(i))

    plot(dt, solution)

if __name__ == '__main__':
    main()