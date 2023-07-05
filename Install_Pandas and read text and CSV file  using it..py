#install packages in terminal,it will automatically install in your, conda env dir
import pandas


def print_hi(name):
    print(f'Hi, {name}')
if __name__ =='__main__':
    print_hi('PyCharm')

p = pandas.read_csv('anus_x.csv')
#p.head(2)
print(p.to_string())#print must ha to display on console