class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        gene_set = set(bank)
        if endGene not in gene_set:
            return -1

        queue = deque()
        queue.append([startGene, 0])
        choices = ['A', 'C', 'G', 'T']
        visited = set()
        while queue:
            gene, steps = queue.popleft()
            if gene == endGene:
                return steps
            for i in range(len(gene)):
                for ch in choices:
                    if gene[i] == ch:
                        continue
                    mutation = gene[:i] + ch + gene[i + 1:]
                    if mutation in gene_set and mutation not in visited:
                        visited.add(mutation)
                        queue.append([mutation, steps + 1])

        return -1