import sqlite3

conn = sqlite3.connect('MyStar.db')
cur = conn.cursor()
# create a table
cur.execute("CREATE TABLE Stars(SID VARCHAR ,Sname VARCHAR ,Gender CHARACTER ,Age INTEGER ,Representative VARCHAR )")
# insert values
cur.execute("INSERT INTO Stars VALUES('101','Taylor Swift','F',28,'Love Story')")
cur.execute("INSERT INTO Stars VALUES('102','Ed Sheeran','M',26,'Shape of You')")
cur.execute("INSERT INTO Stars VALUES('103','Adele','F',29,'Rolling in the Deep')")
conn.commit()
# print result
file = open('out.txt', 'w')
for row in cur.execute("SELECT * FROM Stars WHERE Gender='F'"):
	print(row)
	file.write(str(row) + "\n")
