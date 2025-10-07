def side_comparison(f):
    def inner(sides):
        a, b, c = sorted(sides)
        return a + b > c and f(sides)
    return inner

def equilateral(sides):
    if len(sides) != 3 or any(side <= 0 for side in sides):
        return False

    return sides[0] == sides[1] == sides[2]


@side_comparison
def isosceles(sides):
    return len(set(sides)) <= 2


@side_comparison
def scalene(sides):
    return len(set(sides)) == 3

