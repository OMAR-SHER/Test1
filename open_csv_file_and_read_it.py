import csv
def print_hi(name):
 print(f'Hi, {name}')
if __name__ == '__main__':
    print_hi('anas')
    with open("anus_x.csv") as csv_file:#.csv file is created by save as(csv comma dilemma) not by changing extensio manually# thas why anus_y is error
        csv_reader = csv.reader(csv_file, delimiter=',')
        for row in csv_reader:
             print(row[0], row[1], row[2],row[3],row[4])