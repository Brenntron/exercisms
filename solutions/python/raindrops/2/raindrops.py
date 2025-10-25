def convert(number):
    factors = [(3, 'Pling'), (5, 'Plang'), (7, 'Plong')]
    sounds = [sound for factor, sound in factors if number % factor == 0]

    return ''.join(sounds) or str(number)
