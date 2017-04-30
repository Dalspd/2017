def pre(a, b):
	'''a--Term-loop b--Term || while true return 1; else return 0'''
	if a == b:
		return 1
	else:
		return 0


def equ(a, b):
	'''Two man can't have the same term'''
	if a == b:
		return 1
	else:
		return 0


for a in range(1, 6):
	for b in range(1, 6):
		for c in range(1, 6):
			for d in range(1, 6):
				for e in range(1, 6):
					if pre(b, 2) + pre(a, 3) == 1 and pre(b, 2) + pre(e, 4) == 1 and pre(c, 1) + pre(d, 2) == 1 and pre(
							c, 5) + pre(d, 3) == 1 and pre(e, 4) + pre(a, 1) == 1:
						if equ(a, b) + equ(a, c) + equ(a, d) + equ(a, d) + equ(a, e) + equ(b, c) + equ(b, d) + equ(b,
																												   e) + equ(
								c, d) + equ(c, e) + equ(d, e) == 0:
							print("ACTUAL TERM: a:%d b:%d c:%d d:%d e:%d" % (a, b, c, d, e))
