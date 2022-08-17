#!/usr/bin/python3
"""Defines the island_perimeter function"""


def island_perimeter(grid):
    """
    island_perimeter returns the perimeter of the island discribed in the grid

    :param grid(list[list[int]]): is a 2D array repesenting the land zone and 
    zone
    :return int: the perimeter of the island in the grid if present
    """
    def get_value(y, x):
        try:
            if y < 0 or x < 0:
                raise
            val = grid[y][x]
            if val == 0:
                ret = 1
            else:
                ret = 0
        except BaseException:
            ret = 1
        return ret

    perimeter = 0
    for y in range(len(grid)):
        for x in range(len(grid[y])):
            if grid[y][x] > 0:
                perimeter += get_value(y, x + 1)
                perimeter += get_value(y, x - 1)
                perimeter += get_value(y + 1, x)
                perimeter += get_value(y - 1, x)
    return perimeter
