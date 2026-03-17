VOWELS = 'aeiou'
VOWELS_PLUS_Y = VOWELS + 'y'

def starts_with_vowel_plus(text: str) -> bool:
    """Returns True if text begins with a vowel or special substrings. False if not"""
    if not text:
        return False
    lower_text = text.lower()
    return lower_text[0] in VOWELS or lower_text.startswith(('yt', 'xr'))

def translate(text: str) -> str:
    return ' '.join(translate_word(word) for word in text.split())
        

def translate_word(text: str) -> str:
    if starts_with_vowel_plus(text):
        return f"{text}ay"

    qu_index = text.find('qu', 0, 3)
    new_append = ''

    if qu_index >= 0:
        new_append = text[0:qu_index+2]
    elif text[0] == 'y':
        new_append = text[0]
    else: 
        vowel_index = next((index for index, character in enumerate(text) if character.lower() in VOWELS_PLUS_Y), None)
        new_append = text[0:vowel_index]

    trimmed_text = text.replace(new_append, '', 1)
    return f"{trimmed_text}{new_append}ay"

