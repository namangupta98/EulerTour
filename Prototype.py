input = open('input_example.txt', 'r')
G = {}


# Create Graph
def createGraph(file):
    for i in range(len(file)):
        file[i] = file[i].split()

    return file


adjacencylist = input.readlines()
adjacencylist = createGraph(adjacencylist)

input.close()


for node in adjacencylist:
    G[int(node[0])] = node[1:]


# function to check existence of Euler Tour
def isEulerTour(Graph):
    for node in Graph:
        if len(Graph[node]) % 2 != 0:
            return False

    return True


if isEulerTour(G):
    curr_path = [1]
    eulerTour = []
    curr_node = 1

    while curr_path:
        if len(G[curr_node]):

            # adjacent node to the current node
            new_node = int(G[curr_node].pop())

            # remove edge from the adjacent node as well
            i = 0   # index value
            for val in G[new_node]:
                if int(val) == curr_node:
                    G[new_node].pop(i)
                else:
                    i += 1
            curr_node = new_node

            # Adding current node in the path
            curr_path.append(curr_node)

        else:
            eulerTour.append(curr_path.pop())

    print('Euler Tour: ', eulerTour)
