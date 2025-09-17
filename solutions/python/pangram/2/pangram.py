def is_pangram(sentence):
    chars = {c.lower() for c in sentence if c.isalpha()}
    return len(chars) == 26
