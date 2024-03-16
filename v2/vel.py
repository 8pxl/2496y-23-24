f = open("out.txt")
vel = {}
for line in f:
    l = line.split()
    if (l[0], l[1]) not in vel.keys():
        vel[(l[0], l[1])] = (float(l[2]), 1)
    else:
        vel[(l[0], l[1])] = (vel[(l[0], l[1])][0] + float(l[2]), vel[(l[0], l[1])][1] + 1)

for key, value in vel.items():
    print (key, value[0] / value[1])