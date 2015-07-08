#! /usr/bin/python
# -*- mode:python; coding:utf-8 -*-
#if __name__ == '__main__’: マナーとしてメイン関数がシェルでここから始まるの意味。
#=====================================================================================

#                       opt.py

#                           by 2015-02-17

#                           Last change : Katsurou Takahashi

#=====================================================================================



# 機  能 : objファイルの読み込み

#

# 使用法 : 

#

# 実  例 : 

#

# 注意点 : 

#

# 参  考 : 



#-------------------------------------------------------------------------------------

#                        import

#-------------------------------------------------------------------------------------



import sys

from optparse import OptionParser # 引数パーザー





#-------------------------------------------------------------------------------------

#                        method

#-------------------------------------------------------------------------------------



# 標準入力

def read_stdin():

    data = []

    for line in sys.stdin:

        data.append(line.strip())

    return data



# オプションのパーズ

def opt_parser():

    parser = OptionParser()

    parser.add_option('-e', action="store", dest="elem", default=None,

                  help='element number (ex. -e 1,2 )')

    (options, args) = parser.parse_args()

    return options



#-------------------------------------------------------------------------------------

#                        main

#-------------------------------------------------------------------------------------




infp = open(sys.argv[1], 'r')
outfp = open(sys.argv[2], 'w')
for line in infp.readlines():
    s = line.split()
    if len(s) < 1:
        continue
    if s[0] == 'v':
        x = 2*float(s[1])
        y = 2*float(s[2])
        z = 2*float(s[3])
        outfp.write('v ' + str(x) + ' ' + str(y) + ' ' + str(z) + '\n')
        print ('v ' + str(x) + ' ' + str(y) + ' ' + str(z) + '\n')
    else:
        outfp.write(line)

infp.close()
outfp.close()

infp = open(sys.argv[1], 'r')
outfp = open(sys.argv[2], 'w')

for line in infp.readlines():
    g = line.split()
    if len(g) < 1:
        continue
    if g[0] == 'f':#fのデータを改造して、三角形の単体分割ファイルにして計算する。それで、そのあとの処理が円滑に行える。
    # データそのものを書き換えるソースコードを書くと、ShapeNet自体を書き換える必要があるので、ソースコード内で書き換えることができれば、そのままできる。その分岐の設計をしっかりしよう。
        # for fvertical in len(s):
        xf = g[1]
        yf = g[2]
        zf = g[3]
        outfp.write('f ' + str(xf) + ' ' + str(yf) + ' ' + str(zf) + '\n')
        print ('f ' + str(xf) + ' ' + str(yf) + ' ' + str(zf) + '\n')
    else:
        outfp.write(line)


infp.close()
outfp.close()





#=====================================================================================

#                        END

#=====================================================================================

#~

#(END) 

