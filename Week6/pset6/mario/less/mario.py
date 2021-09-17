from cs50 import get_int


def main():
    height = get_height()
    draw(height, height)


def get_height():
    while True:
        height = get_int("Height: ")
        if height>0 and height<9:
            break
    return height


def draw(height, h):
    if height == 0:
        return

    draw(height - 1, h)
    print(" " * (h - height), end='')
    print("#" * height)

main()
