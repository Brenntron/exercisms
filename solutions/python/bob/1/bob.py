def response(hey_bob):
    striped_msg = hey_bob.strip()
    response = ""
    is_yelling = striped_msg.isupper()
    is_question = striped_msg.endswith("?")

    if striped_msg == "":
        response = "Fine. Be that way!"
    elif is_question and is_yelling:
        response = "Calm down, I know what I'm doing!"
    elif is_yelling:
        response = "Whoa, chill out!"
    elif is_question:
        response = "Sure."
    else:
        response = "Whatever."

    return response
