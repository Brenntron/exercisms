VOWELS = 'aeiou'

def starts_with_vowel_plus(text: str) -> bool:
    """Returns True if text begins with a vowel or special substrings. False if not"""
    if not text:
        return False
    lower_text = text.lower()
    return text[0] in VOWELS or lower_text.startswith(('yt', 'xr'))

def translate(text: str) -> str:
    translated_phrase = []
    for word in text.split(' '):
        translated_word = translate_word(word)
        translated_phrase.append(translated_word)

    return ' '.join(translated_phrase)
        

def translate_word(text: str) -> str:
    if starts_with_vowel_plus(text):
        return f"{text}ay"
    else:
        qu_index = text.rfind('qu', 0, 3)
        new_append = ''

        if qu_index >= 0:
            new_append = text[0:qu_index+2]
        elif text[0] == 'y':
            new_append = text[0]
        else: 
            vowels_plus_y = VOWELS + 'y'
            vowel_index = next((index for index, character in enumerate(text) if character.lower() in vowels_plus_y), None)
            new_append = text[0:vowel_index]

        trimmed_text = text.replace(new_append, '')
        return f"{trimmed_text}{new_append}ay"

