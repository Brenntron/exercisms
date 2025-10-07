def equilateral(sides):
    if len(sides) != 3 or any(side <= 0 for side in sides):
        return False

    return sides[0] == sides[1] == sides[2]


def isosceles(sides):
    if len(sides) != 3 or any(side <= 0 for side in sides):
        return False

    if length_sum_comparison(sides) is False:
        return False

    return len(set(sides)) <= 2


def scalene(sides):
    if len(sides) != 3 or any(side <= 0 for side in sides):
        return False

    if length_sum_comparison(sides) is False:
        return False

    return len(set(sides)) == 3

def length_sum_comparison(sides):
    a, b, c = sorted(sides)
    return a + b > c

