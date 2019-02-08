# Starting in the top left corner of a 2x2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
# How many such routes are there through a 20x20 grid?

lattice_size = 20

def build_lattice(size):
    lattice = [ [1] for i in range(0, size+1)]
    for i in range(0, size+1):
        for j in range(0, size+1):
            lattice[j].append(1)
    return lattice

def fill_latice_with_values(lattice):
    lattice_length = len(lattice)
    for i in range(1, lattice_length):
        for j in range(1, lattice_length):
            lattice[i][j] = lattice[i-1][j] + lattice[i][j-1]

def find_route_count_for_lattice(lattice_size):
    lattice = build_lattice(lattice_size)
    fill_latice_with_values(lattice)
    return lattice[lattice_size][lattice_size]


number_of_routes = find_route_count_for_lattice(lattice_size)

print(number_of_routes)