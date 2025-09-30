def square(number):
    if number < 1 or number > 64:
        raise ValueError("square must be between 1 and 64")

    if number == 1:
        return 1

    total = 1
    for _ in range(1, number):
        total *= 2

    return total


def total():
    total = 0

    for i in range(1, 65):
        total += square(i)

    return total
