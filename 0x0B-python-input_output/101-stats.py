#!/usr/bin/python3
"""Module to write a script of dict of Filesize and code_status"""


import sys


filesize = 0
count = 0
stc = {"200": 0,
       "301": 0,
       "400": 0,
       "401": 0,
       "403": 0,
       "404": 0,
       "405": 0,
       "500": 0}

try:
    for line in sys.stdin:
        line = line.split()

        filesize += int(line[-1])

        code = line[-2]
        if code in list(stc.keys()):
            stc[code] += 1

        count += 1

        if count % 10 == 0:
            print("File size: {}".format(filesize))
            for key in list(stc.keys()):
                print("{}: {}".format(key, stc[key]))

except KeyboardInterrupt:
    print("File size: {}".format(filesize))
    for key in list(stc.keys()):
        print("{}: {}".format(key, stc[key]))
    raise
