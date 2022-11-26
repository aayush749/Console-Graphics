import sys
from graphics import Graphics
from argparse import ArgumentParser

def main(argc, argv):

    Graphics.init_graph(argv[0], argv[1])

    Graphics.putpixel(1, 1)
    Graphics.putpixel(10, 3)
    Graphics.putpixel(3, 10)
    Graphics.display(show_axis=True, axis_color = argv[2])

if __name__ == '__main__':
    parser = ArgumentParser("Graphics Test", description="Graph Plotting Application")
    parser.add_argument("--width", type = int, default=50)
    parser.add_argument("--height", type = int, default=50)
    parser.add_argument("--color", type = str, default="White")
    args = parser.parse_args()
    width = args.width
    height = args.height
    color = args.color
    main(3, (width, height, color))