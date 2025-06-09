class Solution:
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        indegree = defaultdict(int)
        graph = defaultdict(list)

        for recipe, ing_list in zip(recipes, ingredients):
            for ing in ing_list:
                graph[ing].append(recipe)
                indegree[recipe] += 1
            
        queue = deque(supplies)
        res = []

        while queue:
            curr = queue.popleft()
            for nei in graph[curr]:
                indegree[nei] -= 1
                if indegree[nei] == 0:
                    res.append(nei)
                    queue.append(nei)
        return res
        