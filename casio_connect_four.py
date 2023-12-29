# Originally written on a Casio Graph 90+E while bored in class
# Please ignore the bad code quality

J="_O@" # version 2
HEIGHT=6 # max 6
WIDTH=7 # max 11/21

x=[[0 for _ in range(WIDTH)] for _ in range(HEIGHT)]
tour,joue,coup=0,1,0
partie="b"

def affiche(x):
  for row in x:
    for n in row:
      print(J[n]+" ",end="")
    print()

def jouer_coup(coup):
  #Coup valide ?
  
  # -69 : Erreur
  # -2 : Arrete la partie
  # -1 : Annuler le dernier coup
  # 0 : Le coup est valide
  
  try: 
    coup=int(coup)
  except:
    return -69

  if coup==0:
    return -2

  if coup==-1:
    return -1
  
  if coup>WIDTH or coup<0:
    return -69

  # Joue le coup
  i=1
  while i<=HEIGHT:
    if x[HEIGHT-i][coup-1]!=0:
      i+=1
    else:
      x[HEIGHT-i][coup-1]=joue
      break

  if i==HEIGHT+1: # Colonne pleine ?
    return -69

  return 0 # Tout est good :)

# Boucle Principale
while tour<HEIGHT*WIDTH:
  affiche(x)

  coup=input(str(joue)+">")
  coco=jouer_coup(coup)

  if coco==0:
    partie+=str(coup)
    tour+=1
    joue=(tour%2)+1
  elif coco==-1:
    print("magie")
  elif coco==-2:
    break

affiche(x)  
print(partie)
