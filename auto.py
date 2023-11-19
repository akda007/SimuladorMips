file = open('a.txt', 'r')
output = open('o.txt', 'w')


for i in file.readlines():
    output.write(f'void {i.split(" ")[0]}()\n')

file.close()
output.close()