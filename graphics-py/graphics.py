import numpy as np
from color import Color

class Graphics:
    n_rows: int = 50
    n_cols: int = 50
    matrix = np.zeros((n_rows, n_cols), dtype = np.uint8)

    @classmethod
    def init_graph(cls, width: int, height: int, default_bg: np.uint8 = np.uint8(ord('.'))) -> None:
        if cls.n_rows != height or cls.n_cols != width:
            cls.n_rows, cls.n_cols = height, width
            cls.matrix = np.zeros((cls.n_rows, cls.n_cols), dtype=np.uint8)

        Color.init()
        for row in range(cls.n_rows):
            for col in range(cls.n_cols):
                cls.matrix[row][col] = default_bg
    
    @classmethod
    def putpixel(cls, x, y, pixel: str = '*') -> None:
        x += cls.n_cols // 2
        y = cls.n_rows // 2 - y - 1
        x = int(x)
        y = int(y)
        if x < 0 or x >= cls.n_cols or y < 0 or y >= cls.n_rows:
            return
        
        cls.matrix[y][x] = np.uint8(ord(pixel))

    @classmethod
    def display(cls, show_axis: bool = True, axis_color: str = "White (SYSTEM)") -> None:
        for row in range(cls.n_rows):
            for col in range(cls.n_cols):
                is_axis: bool = False
                if show_axis:
                    is_axis = cls.__draw_axis(row, col, axis_color)

                if not is_axis:
                    print(chr(cls.matrix[row][col]), sep = ' ', end = '')
            print()

    @classmethod
    def __draw_axis(cls, row: int, col: int, color_name: str) -> bool:
        color_code = Color.get_code(color_name)
        if row == 0 and col == cls.n_cols // 2:
            print(f'\033{color_code}^' + "\033[1;39m", sep = ' ', end = '')
            return True
        elif row == cls.n_rows // 2 and col == 0:
            print(f'\033{color_code}<' + "\033[1;39m", sep = ' ', end = '')
            return True
        elif row == cls.n_rows // 2 and col == cls.n_cols - 1:
            print(f'\033{color_code}>' + "\033[1;39m", sep = ' ', end = '')
            return True
        elif row == cls.n_rows - 1 and col == cls.n_cols // 2:
            print(f'\033{color_code}V' + "\033[1;39m", sep = ' ', end = '')
            return True
        
        if row == cls.n_rows // 2 and col == cls.n_cols // 2:
            print(f'\033{color_code}+' + "\033[1;39m", sep = ' ', end = '')
            return True

        if col == cls.n_cols // 2:
            print(f'\033{color_code}|' + "\033[1;39m", sep = ' ', end = '')
            return True

        if row == cls.n_rows // 2:
            print(f'\033{color_code}-' + "\033[1;39m", sep = ' ', end = '')
            return True

        return False