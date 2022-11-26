import pandas as pd
from enum import Enum

class Color:
    colors = pd.DataFrame()
    @classmethod
    def init(cls):
        cls.colors = cls.__load_colors_from_csv()
        cls.colors['Name'] = cls.colors['Name'].apply(lambda x : x.strip())
        cls.colors = cls.colors.drop_duplicates(['Name'])
        cls.colors = cls.colors.set_index('Name')

    @classmethod
    def get_code(cls, color_name: str) -> str:
        try:
            return str(cls.colors['Foreground Escape Code'][color_name])
        except:
            return "[38:5:0m"

    @classmethod
    def __load_colors_from_csv(cls) -> pd.DataFrame:
        color_df = pd.read_csv('DefaultColorCodes.csv')
        return color_df[['Name', 'Foreground Escape Code']]