"""
# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates
"""

class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        def dfs(emp):
            importance = emps[emp].importance
            for e in emps[emp].subordinates:
                importance += dfs(e)
            return importance

        emps = {emp.id: emp for emp in employees}

        return dfs(id)
