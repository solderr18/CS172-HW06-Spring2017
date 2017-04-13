# splitBabyNames.py - file are delivered with comma separated values.
#   This program converts them to space separated
import glob

readpath = "/Users/jdumoulin/Documents/dev/CS172-nocommit/HW6Example/names/"
files = glob.glob('%s*.txt' % readpath)
for file in files:
    with open(file, "r") as f:
        # get the file name
        fname = file.split('/')[-1]
        with open(fname, "w") as g:
            for line in f:
                x,y,z = line.split(',')
                g.write('%s\t%s\t%s' %(x,y,z))

