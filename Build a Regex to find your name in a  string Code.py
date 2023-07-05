import re

def print_hi(name):
    print(f'Hi, {name}')
if __name__ =='__main__':
    print_hi('PyCharm')
    regex = "anus+"
    name = input("Enter a line:: ")
    if (re.search(regex, name)):
        print("anus is present in the input line")
    else:
        print("anus is not present in the input line")