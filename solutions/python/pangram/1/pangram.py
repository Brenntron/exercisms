def is_pangram(sentence):
    if sentence == "":
        return False

    characters = set()

    for letter in sentence:
        print('letter:',letter)
        if letter.isalpha() and letter not in characters:
            characters.add(letter.lower())

    if characters.__len__() == 26:
        return True
    else:
        return False
