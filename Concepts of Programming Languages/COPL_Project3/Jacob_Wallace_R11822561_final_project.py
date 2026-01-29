# ===============================================================
# |                 PROJECT 3: Simulation Matrix                |
# ===============================================================

# imports
import os
import argparse 
from multiprocessing import Pool

# neighboring offset values to find cells touching cell index
nOff = [
    (-1, -1), (-1, 0), (-1, 1),
    (0, -1),          (0, 1),
    (1, -1), (1, 0), (1, 1)
]

#cell values representing corresponding characters 
ids = { 
    'O': 2, 'o': 1, '.': 0, 'x': -1, 'X': -2
}

# ===============================================================
# |                         Functions                           |
# ===============================================================
 
# calculate summation of neighboring cells
def nSum(matrix, rows, cols, i, j): 
    ns = 0 # neighbors sum variable
    for index in nOff:  # check neighboring cells/positions
        
        disX = index[0] # row offset
        disY = index[1] # columns offset
        neX = i + disX # row index of neighbor
        neY = j + disY # column index of neighbor
     
        if neX >= 0: 
            if neX < rows: 
                if neY >= 0:
                    if neY < cols:
                        ns += matrix[neX][neY] 
    return ns
    
# apply the rules as listed in the pdf and apply to cells
def applyRules(args):
    # arrays of powers and prime numbers to compare instead of calculating
    powerArr = (1, 2, 4, 8, 16)
    primeArr = (2, 3, 5, 7, 11, 13)
    # process/worker arguments
    matrix = args[0] 
    start = args[1] 
    end = args[2] 
    rows = args[3]
    cols = args[4]
    # copy matrix to edit
    temp=[]
    for row in matrix[start:end]:
        temp.append(row[:]) # ":" needed for some reason?
    # apply the rules
    for i in range(start, end): 
        for j in range(cols): 
            cell = matrix[i][j] 
            sum1 = nSum(matrix, rows, cols, i , j) 

            if cell == 2: # rules for 'O' cell.
                if sum1 in powerArr:   
                    temp[i-start][j]= 0
                elif sum1<10: 
                    temp[i-start][j]= 1 
                else:  
                    temp[i-start][j]= 2 

            elif cell == 1:  # rules for 'o' cell.
                if sum1 <=0:
                    temp[i-start][j]= 0
                elif sum1 >=8:
                    temp[i-start][j]= 2 
                else: 
                    temp[i-start][j]= 1 

            elif cell == 0: # rules for '.' cell.
                if sum1 in primeArr: 
                    temp[i-start][j]= 1
                elif abs(sum1) in primeArr:
                    temp[i-start][j]= -1
                else: 
                    temp[i-start][j]= 0
                
            elif cell == -1: # rules for 'x' cell.
                if sum1>=1: 
                    temp[i-start][j]= 0
                elif sum1<= -8: 
                    temp[i-start][j]= -2
                else: 
                    temp[i-start][j]= -1

            elif cell == -2: # rules for 'X' cell.
                if abs(sum1) in powerArr: 
                    temp[i-start][j]= 0 
                elif sum1>-10:
                    temp[i-start][j]= -1 
                else: 
                    temp[i-start][j]= -2

    return temp
   
#divdie the matrix then process them in parallel.
def procSpawn(matrix, procNum): 
    rows = len(matrix) # rows in matrix
    cols = len(matrix[0]) # columns in matrix

    # Split matrix up into slices for each process defined by user.
    for LOOP in range(100):
        #print(f"Step: {LOOP+1}/100")
        size=rows // procNum 
        slices=[]

        for L1 in range(procNum):
            start = L1*size
        
            if L1 == procNum-1:
                end=rows 
            else:
                end= (1+L1)*size
            
            slices.append([matrix, start, end, rows, cols])

        with Pool(procNum) as pool: #pool takes all processes and adds them to a process pool.
            mapPool = pool.map(applyRules, slices) 

        #combine back to a individual matrix
        matrixOut = []
        for L2 in mapPool:
            for row in L2:
                matrixOut.append(row)

        matrix = matrixOut 

    return matrix # return final matrix after 100 iterations

# ===============================================================
# |                          Main Thread                        |
# ===============================================================
# the main or "driver" that runs the program.
if __name__ == "__main__":
    print("Project :: R11822561") 
    # argument parser
    parser = argparse.ArgumentParser(description = "Matrix Simulation")
    parser.add_argument("-i", "--input",type=str, required=True)
    parser.add_argument("-o", "--output",type=str, required=True)
    parser.add_argument("-p", "--processes",type=int, required=False, default=1)
    args = parser.parse_args() 

    
    matrix = []
    # read file
    with open(args.input, "r") as file:
        for line in file: 
            row = [ids[char] for char in line.strip()]
            matrix.append(row)
    # start the program
    matrix = procSpawn(matrix, args.processes)
    # write the output matrix to file
    with open(args.output, "w") as file:
        for row in matrix: 
            line = ""
            for cell in row:
                for key in ids:
                    if ids[key] == cell:
                        line += key
                        break
            line += "\n"
            file.write(line) 