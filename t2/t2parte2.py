import itertools
from random import randint

'''
   Programacao funcional para gerar SVG:
   - gera uma lista de coordenadas de retangulos
   - define uma lista de estilos (cores), em qualquer quantidade
   - aplica os estilos aos retangulos, gerando uma lista com todos os dados para o SVG
   - coloca os dados no formato SVG, concatenando strings
'''


def svgRect(rs):
    (((x, y), w, h), style) = rs
    return "<rect x='%.3f' y='%.3f' width='%.2f' height='%.2f' style='%s'/>\n" % (x, y, w, h, style)


def svgImage(w, h, rs):
    return "<svg width='%.2f' height='%.2f' xmlns='http://www.w3.org/2000/svg'>\n" % (w, h) + \
           ''.join(map(svgRect, rs)) + "</svg>"


def applyStyles(rects, styles):
    return list(zip(rects, itertools.cycle(styles)))

#Exercício 1 da parte 2
def genRects(n, w, h):
    return [ ((0.0 + (w*x), 0.0), w, h) for x in range (n+1) ]

#Exercício 2 da parte 2
def genColors(n, w, h):
    lis = range(1, n)
    return ["fill:rgb(%s, %s, %s)"%((randint(0,140-n),(randint(0,140-n)),(randint(0,140-n)))) for n in lis]


def writeFile(fname, contents):
    f = open(fname, 'w')
    f.write(contents)
    f.close()


def main():
    maxWidth = 1000
    maxHeight = 100
    n = 10
    w = 50
    h = 50
    rects = genRects(n, w, h)
    styles = genColors(n, w, h)                #["fill:rgb(140,0,0)", "fill:rgb(0,140,0)"]
    rectstyles = applyStyles(rects, styles)
    writeFile("mycolors.svg", svgImage(maxWidth, maxHeight, rectstyles))


if __name__ == '__main__':
    main()
