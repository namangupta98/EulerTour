input = open('input/in3.txt', 'r')
G = {}

# Create Graph
def createGraph(file):
    for i in range(len(file)):
        file[i] = file[i].split()

    return file


adjacencylist = input.readlines()
adjacencylist = createGraph(adjacencylist)

for node in adjacencylist:
    G[node[0]] = node[1:]

input.close()
