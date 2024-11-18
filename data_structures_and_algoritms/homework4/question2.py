class UnionFind:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.rank = [0] * n

    def find(self, u):
        if self.parent[u] != u:
            self.parent[u] = self.find(self.parent[u])
        return self.parent[u]

    def union(self, u, v):
        u_root = self.find(u)
        v_root = self.find(v)
        if u_root == v_root:
            return False
        if self.rank[u_root] < self.rank[v_root]:
            self.parent[u_root] = v_root
        else:
            self.parent[v_root] = u_root
            if self.rank[u_root] == self.rank[v_root]:
                self.rank[u_root] += 1
        return True

def update_mst(n, T, new_vertex_edges):
    """
    n: number of original vertices in G (vertices are numbered from 0 to n-1)
    T: list of edges in the original MST, each edge is a tuple (u, v, weight)
    new_vertex_edges: list of edges from new vertex v (numbered n) to G, each edge is a tuple (u, n, weight)
    """
    total_vertices = n + 1
    E_prime = T + new_vertex_edges
    E_prime.sort(key=lambda x: x[2])
    uf = UnionFind(total_vertices)
    T_prime = []
    for u, v, weight in E_prime:
        if uf.union(u, v):
            T_prime.append((u, v, weight))

    return T_prime


n = 5
T = [
    (0, 1, 1),
    (1, 2, 2),
    (1, 3, 3),
    (3, 4, 4)
]
new_vertex_edges = [
    (2, 5, 1),
    (4, 5, 2)
]
T_prime = update_mst(n, T, new_vertex_edges)

print("Updated MST:")
for edge in T_prime:
    print(edge)