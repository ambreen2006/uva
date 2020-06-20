import sys
from collections import defaultdict


def following_order(variables, constraint,
                    visited, order):
    def confirms_to_constraint(variable, constraint):
        successors = constraint[variable]
        if any(map(lambda x: x in visited, successors)):
            return False
        return True

    if len(order) == len(variables):
        print(order)
        return
    for i in range(0, len(variables)):
        if variables[i] not in visited:
            visited.add(variables[i])
            if confirms_to_constraint(variables[i], constraint):
                following_order(variables, constraint,
                                visited, order + variables[i])
            visited.remove(variables[i])


def main():
    variables_list = []
    constraint_list = []
    input_variables = True
    for line in sys.stdin:
        line = line.replace('\n', '').split(' ')
        if input_variables:
            variables_list.append(line)
            input_variables = False
        else:
            constraints = defaultdict(list)
            for x, y in zip(line[::2], line[1::2]):
                constraints[x].append(y)
            constraint_list.append(constraints)
            input_variables = True

    for i in range(0, len(variables_list)):
        variables = variables_list[i]
        variables.sort()
        constraints = constraint_list[i]
        visited = set()
        following_order(variables, constraints,
                        visited, "")
        if i != (len(variables_list) - 1):
            print('')


if __name__ == '__main__':
    main()
