import numpy as np
# import image as im
from PIL import Image as im

TileWidth = 32
TileHeight = 32
RowsTocolor = 3;

L = np.zeros((TileWidth, TileHeight))

flag = [ [0,0,0,0], [0,0,0,1], [0,0,1,0], [0,1,0,0], [1,0,0,0], [0,0,1,1], [0,1,0,1], [1,0,0,1], [0,1,1,0], [1,0,1,0], [1,1,0,0], [0,1,1,1], [1,0,1,1], [1,1,0,1], [1,1,1,0], [1,1,1,1]]

# 1 means pixel values will be black

# Black Background
#      000
#     3   1
#     3   1
#     3   1
#      222

def main():
    cnt=0
    for i in flag:
        temp = L
        if(i[0] == 1):
            for j in range(RowsTocolor):
                for k in range(len(temp[j])):
                    temp[j][k] = 255;
        if(i[1] == 1):
            for j in range(RowsTocolor):
                for k in range(len(temp[j])):
                    temp[k][len(temp[j]) - j - 1] = 255;
        if(i[2] == 1):
            for j in range(RowsTocolor):
                for k in range(len(temp[j])):
                    temp[len(temp[j]) - j - 1][k] = 255;
        if(i[3] == 1):
            for j in range(RowsTocolor):
                for k in range(len(temp[j])):
                    temp[k][j] = 255;
        temp = np.array(temp, np.uint8)
        data = im.fromarray(temp)
        cnt = cnt+1
        data.save("Black" + str(i[0]) + str(i[1]) + str(i[2]) + str(i[2]) + ".png");

if __name__ == '__main__':
    main()
