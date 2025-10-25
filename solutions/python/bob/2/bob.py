def response(hey_bob):
    msg = hey_bob.strip()
    is_yelling = msg.isupper()
    is_question = msg.endswith("?")

    if not msg:
        return "Fine. Be that way!"
    elif is_question and is_yelling:
        return "Calm down, I know what I'm doing!"
    elif is_yelling:
        return "Whoa, chill out!"
    elif is_question:
        return "Sure."
    else:
        return "Whatever."
